import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.StringTokenizer;
import java.util.Collections;
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
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int needHeight = in.nextInt();
        int[] a = in.nextIntArray(12);
        ArrayUtils.sort(a, new ReverseComparator<Integer>());
        int height = 0;
        if(needHeight == 0) {
            out.println(0);
            return;
        }
        for(int i = 0; i < 12; ++i) {
            height += a[i];
            if(height >= needHeight) {
                out.println(i + 1);
                return;
            }
        }
        out.println(-1);
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

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public int[] nextIntArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = nextInt();
        }
        return array;
    }

    private String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

class OutputWriter extends PrintWriter {

	public OutputWriter(OutputStream out) {
		super(out);
	}

	public OutputWriter(java.io.Writer writer){
		super(writer);
	}

	}

class ArrayUtils {

    public static void sort(int[] array, Comparator<Integer> comparator) {
        Collections.sort(new IntArray(array), comparator);
    }

    }

class ReverseComparator<T extends Comparable<T>> implements Comparator<T> {
    public int compare(T t, T t1) {
        return t1.compareTo(t);
    }
}

class IntArray extends Array<Integer> {
    private final int[] array;

    public IntArray(int... array) {
        this.array = array;
    }

    public Integer get(int i) {
        return array[i];
    }

    public Integer set(int index, Integer element) {
        Integer res = array[index];
        array[index] = element;
        return res;
    }

    public int size() {
        return array.length;
    }
}

abstract class Array<T> extends AbstractList<T> implements RandomAccess {
}