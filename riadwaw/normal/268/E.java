import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskE {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        final int[] l = new int[n];
        final int[] p = new int[n];
        in.nextIntArrays(l, p);
        int[] indeces = new int[n];
        for(int i = 0; i < n; ++i)
            indeces[i] = i;

        ArrayUtils.sort(indeces, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                if(p[a] == 100 && p[a] == p[b])
                    return 0;
                if(p[a] == 100)
                    return -1;
                if(p[b] == 100)
                    return 1;
                return - (l[a] * p[a]) * (100 -p[b]) + l[b] * p[b] * (100 - p[a]);
            }
        });

        double curp = 0;
        double ans = 0;

        for(int i = n - 1; i >=0; --i){
            ans += l[indeces[i]];

            ans += curp * l[indeces[i]] * p[indeces[i]] / 100.0;

            curp += 1 - p[indeces[i]] / 100.0;
        }

        out.println(String.format("%.12f", ans));
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

    public void nextIntArrays(int[]... arrays) {
        for (int i = 1; i < arrays.length; ++i) {
            if (arrays[i].length != arrays[0].length) {
                throw new InputMismatchException("Lengths are different");
            }
        }
        for (int i = 0; i < arrays[0].length; ++i) {
            for (int[] array : arrays) {
                array[i] = nextInt();
            }
        }
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