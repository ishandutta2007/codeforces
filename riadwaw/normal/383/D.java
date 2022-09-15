import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    int MAGIC = 11100;
    private int mod = 1000000007;

    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int[] a = in.nextIntArray(n);
        int[] counts = new int[MAGIC * 2];
        long ans = 0;
        for(int i = 0; i < n; ++i) {
            ++counts[MAGIC];
            if(counts[MAGIC] > mod)
                counts[MAGIC] -= mod;
            int[] newCounts = new int[MAGIC * 2];
            for(int oldValue = -10000; oldValue <= 10000; ++oldValue) {
                newCounts[MAGIC + oldValue + a[i]] += counts[MAGIC + oldValue];
                if(newCounts[MAGIC + oldValue + a[i]] >= mod)
                    newCounts[MAGIC + oldValue + a[i]] -= mod;
                newCounts[MAGIC + oldValue - a[i]] += counts[MAGIC + oldValue];
                if(newCounts[MAGIC + oldValue - a[i]] >= mod)
                    newCounts[MAGIC + oldValue - a[i]] -= mod;
            }
            counts = newCounts;
            ans += counts[MAGIC];
            if(ans >= mod)
                ans -= mod;
        }
        out.println(ans);
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