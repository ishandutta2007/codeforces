import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author RiaD
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Reader in = new Reader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, Reader in, PrintWriter out) {
        String[] array = in.nextString().split("WUB");
        List<String> list = ListUtils.filter(new ObjectArray<String>(array), new Filter<String>() {
            @Override
            public boolean accept(String value) {
                return !value.isEmpty();
            }
        });
        for(String s: list){
            out.println(s);
        }
    }
}

class Reader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Reader(BufferedReader reader) {
        this.reader = reader;
    }

    public Reader(InputStream stream) {
        this(new BufferedReader(new InputStreamReader(stream)));
    }

    public String nextString() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(readLine());
        }
        return tokenizer.nextToken();
    }

    private String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

class ListUtils {

    public static <E> List<E> filter(Iterable<E> list, Filter<E> filter) {
        List<E> result = new ArrayList<E>();
        for (E entry : list) {
            if (filter.accept(entry))
                result.add(entry);
        }
        return result;
    }

    }

interface Filter<T> {
    public boolean accept(T value);
}

class ObjectArray<T> extends Array<T> {
    private final T[] array;

    public ObjectArray(T[] array) {
        this.array = array;
    }

    public T get(int i) {
        return array[i];
    }

    public int size() {
        return array.length;
    }

    public T set(int index, T element) {
        T res = array[index];
        array[index] = element;
        return res;
    }
}

abstract class Array<T> extends AbstractList<T> implements RandomAccess {
}