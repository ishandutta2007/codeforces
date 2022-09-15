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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    int[] factorials;
    int mod = 1000000007;
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int nulls = in.nextInt();
        int ones = in.nextInt();
        int res = in.nextInt();
        factorials = IntegerUtils.factorials(nulls + ones + 1, mod);
        if(ones == 0) {
            out.println(res == nulls % 2 ? 0 : 1);
            return;
        }
        long answer = 0;

        if(ones == 1) {
            answer += res == nulls % 2 ? 0 : 1;
        }
        for(int firstOne = res; nulls - firstOne >= 0; firstOne += 2) {
            int nullsRemaining = nulls - firstOne;
            int onesRemaining = ones - 1;

            if(nullsRemaining == 0 && onesRemaining == 0)
                continue;


            answer += c(nullsRemaining + onesRemaining, onesRemaining);
            answer %= mod;
        }

        out.println(answer);
    }

    private long c(int n, int k) {
        return factorials[n] * IntegerUtils.modInverse(factorials[k], mod) % mod * IntegerUtils.modInverse(factorials[n - k], mod) % mod;
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

	public static int[] factorials(int n, int mod){
		int [] fact = new int[n + 1];
		fact[0] = 1;
		for(int i = 1; i <= n; ++i)
			fact[i] = (int) (fact[i - 1] * 1L * i % mod);
		return fact;
	}

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

	public static long modInverse(long number, long mod) {
		return power(number, mod - 2, mod);
	}

	}