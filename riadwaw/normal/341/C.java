import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    private static final int MOD = 1000000007;
    int[] fact;
    long[] inv;
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        fact = IntegerUtils.factorials(n, MOD);
        inv = new long[fact.length];
        for(int i = 0; i < fact.length; ++i) {
            inv[i] = IntegerUtils.modInverse(fact[i], MOD);
        }
        int[]a = in.nextIntArray(n);
        boolean[] positions = new boolean[n];
        boolean[] numbers = new boolean[n];
        int all = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] != -1) {
                numbers[a[i] - 1] = true;
                positions[i] = true;
                ++all;
            }

        }



        int same = 0;
        for(int i = 0; i < n; ++i) {
            if(numbers[i] && positions[i])
                ++same;
        }

        out.println(solve(n - same, all - same));
    }


    long[] memo = new long[2005 * 2005];

    private long solve(int n, int k) {
        int key = n * 2005 + k;
        if(memo[key] != 0)
            return memo[key];
        if(k == 0) {
            long ans = 0;
            int cur = 1;
            for(int i = 0; i <= n; ++i) {
                ans += fact[n] * inv[i] * cur;

                cur = -cur;
                ans %= MOD;
                if(ans < 0) {
                    ans += MOD;
                }
            }
            return memo[key] = ans;
        }
        int rest = n - 2 * k;

        if(rest < 0)
            throw new AssertionError();

        long ans = k * solve(n - 2, k - 1);
        if(rest != 0)
            ans += rest * solve(n - 1, k);
        ans %= MOD;
        return memo[key] = ans;
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