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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    private int mod = 1000000007;

    public void solve(int testNumber, Reader in, OutputWriter out) {
        String a = in.nextString();
        long n = in.nextInt();

        long answer = 0;

        for(int i = 0; i < a.length(); ++i) {
            if(a.charAt(i) == '0' || a.charAt(i) == '5') {
                answer += (IntegerUtils.power(2, n * a.length(), mod) - 1) * IntegerUtils.modInverse(IntegerUtils.power(2, a.length(), mod) - 1, mod) % mod * IntegerUtils.power(2, i, mod);
                answer %= mod;
            }
        }

        out.println(answer);
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

	public static long modInverse(long number, long mod) {
		return power(number, mod - 2, mod);
	}

	}