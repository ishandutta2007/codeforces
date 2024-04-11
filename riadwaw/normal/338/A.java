import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    private static final long MOD = 1000000009;

    public void solve(int testNumber, Reader in, OutputWriter out) {
        long answer = 0;
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();

        long l = -1;
        long r = n + 1;

        while (l + 1 < r) {
            long c = (l + r) / 2;
            if(n < c * k || canAchieve(n - c * k, k) >= m - c * k) {
                r = c;
            }
            else
                l = c;
        }

        //out.println(r);

        long c = r;

        answer = ((IntegerUtils.power(2, c + 1, MOD) - 2 + MOD) % MOD) * k % MOD;

        n -= k * c;
        m -= k * c;
        answer += m;
        answer %= MOD;

        out.println(answer);
    }

    private long canAchieve(long n, long k) {
        return n - n / k;
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

class IntegerUtils {

	public static long power(long base, long power, long mod) {
		long result = 1 % mod;
		base %= mod;
		while (power > 0) {
			if (power % 2 == 1) {
				result *= base;
				result %= mod;
			}
			base *= base;
			base %= mod;
			power >>= 1;
		}
		return result;
	}

	}