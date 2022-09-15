import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        in.nextIntArrays(a, b);

        if(n == 1){
            out.println("0.0000");
            return;
        }
        double[] angle = new double[n];
        for(int i = 0; i < n; ++i){
            angle[i] = Math.atan2(b[i], a[i]);
        }
        ArrayUtils.sort(angle);
        
        double maxAngle = angle[0] - angle[n - 1] + 2 * Math.PI;

        for(int i = 1; i < n; ++i){
            double curAngle = angle[i] - angle[i - 1];
            maxAngle = Math.max(curAngle, maxAngle);
        }
        
        out.println((2 * Math.PI - maxAngle)/ Math.PI * 180);
        
        
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

    public static void sort(double[] array) {
        Collections.sort(new DoubleArray(array));
    }

    }

class DoubleArray extends Array<Double> {
    private final double[] array;

    public DoubleArray(double... array) {
        this.array = array;
    }

    public Double get(int i) {
        return array[i];
    }

    public Double set(int index, Double element) {
        Double res = array[index];
        array[index] = element;
        return res;
    }

    public int size() {
        return array.length;
    }
}

abstract class Array<T> extends AbstractList<T> implements RandomAccess {
}