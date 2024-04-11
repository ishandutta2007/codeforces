import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
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
		TaskB2 solver = new TaskB2();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB2 {

    final int shift = 1 << 19;
    int[] q = new int[shift << 1];

    int rsum(int l, int r) {
        if(l > r)
            return 0;
        if(l % 2 != 0)
            return rsum(l + 1, r) + q[l];
        if(r % 2 == 0)
            return rsum(l, r - 1) + q[r];
        return rsum(l / 2, r / 2);
    }

    int sum(int l, int r) {
        return rsum(l + shift, r + shift);
    }

    void set(int v, int value) {
        //System.err.println("set " + v + " " + value);
        v += shift;
        if(q[v] == value)
            return;
        q[v] = value;
        v /= 2;
        while (v > 0) {
            q[v] = q[2 * v] + q[2 * v + 1];
            v /= 2;
        }
    }

    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int[] permutation = in.nextIntArray(n);
        int[] where = new int[n];



        for(int i = 0; i < n; ++i) {
            --permutation[i];
            where[permutation[i]] = i;
        }

        for(int i = 0; i + 1< n; ++i) {
            if(where[i] > where[i + 1])
                set(i, 1);
        }

        int q = in.nextInt();
        for(int query = 0; query < q; ++query) {
            int type = in.nextInt();
            if(type == 1) {
                out.println(1 + sum(in.nextInt() - 1, in.nextInt() - 2));
            }
            else {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;

                HashSet<Integer> interesting = new HashSet<Integer>();
                for(int i = -1; i <= 0; ++i) {
                    interesting.add(permutation[a] + i);
                    interesting.add(permutation[b] + i);
                }

                int tmp = permutation[a];
                permutation[a] = permutation[b];
                permutation[b] = tmp;

                where[permutation[a]] = a;
                where[permutation[b]] = b;
                for (int i: interesting) {
                    if(i < 0 || i + 1 >= n)
                        continue;
                    int newValue = where[i] > where[i + 1] ? 1 : 0;
                    set(i, newValue);
                }



            }
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
        } catch ( IOException e) {
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