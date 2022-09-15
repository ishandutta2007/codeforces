import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
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
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int[] d = in.nextIntArray(n);
        int sum = ListUtils.sum(new IntArray(d));
        int s = in.nextInt() - 1;
        int t = in.nextInt() - 1;
        if(s > t) {
            int tmp = s;
            s = t;
            t = tmp;
        }
        
        int forwardPath = 0;
        
        for(int i = s; i < t; ++i) {
            forwardPath += d[i];
        }
        
        out.println(Math.min(forwardPath, sum - forwardPath));
        
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

class ListUtils {

	public static int sum(Iterable<Integer> list){
		int sum = 0;
		for(Integer i: list){
			sum += i;
		}
		return sum;
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