import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.util.HashSet;
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
        long[] a = in.nextLongArray(n);
        final long all = (1L<<50) - 1;
        for(int i = 33; i >= 0; --i) {

            long and = all;
            for (long l : a) {
                if((l & (1L << i)) != 0) {
                    and &= l;
                }
            }
            if(and == all) {
                continue;
            }

            if(and % (1L << i) != 0) {
                continue;
            }

            Set<Long> answer = new HashSet<Long>();

            for (long l : a) {
                if((l & (1L << i)) != 0) {
                    answer.add(l);
                }
            }

            out.println(answer.size());
            for (long l : answer) {
                out.print(l + " ");
            }
            return;
        }

        throw new AssertionError();
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

    public long nextLong() {
        return Long.parseLong(nextString());
    }

    public long[] nextLongArray(int size) {
        long[] array = new long[size];
        for (int i = 0; i < size; ++i) {
            array[i] = nextLong();
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