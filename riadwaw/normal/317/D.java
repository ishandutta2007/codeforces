import java.io.IOException;
import java.io.InputStreamReader;
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
    public void solve(int testNumber, Reader in, OutputWriter out) {
        long n = in.nextLong();
        ArrayList<Integer> lengths = new ArrayList<Integer>();
        long ones = n;
        boolean[] used = new boolean[101010];
        for(int i = 2; i * i <= n; ++i){
            if (used[i])
                continue;
            long j = i;
            int len = 0;
            while(j <= n) {
                if(j < 101010)
                    used[(int)j] = true;
                ++len;
                j *= i;
            }

            lengths.add(len);
            ones -= len;
        }

        long gandy = 0;

        if(ones % 2 != 0)
            gandy ^= gandy(1);
        long[] dp = new long[30];
        for(int i = 0; i < 30; ++i) {
            dp[i] = gandy(i);
        }
        for (Integer length : lengths) {
            gandy ^= dp[length];
        }

        out.println(gandy == 0 ? "Petya" : "Vasya");
    }

    private long gandy(int length) {
        if (length == 0) return 0;
        if (length == 1) return 1;
        if (length == 2) return 2;
        if (length == 3) return 1;
        if (length == 4) return 4;
        if (length == 5) return 3;
        if (length == 6) return 2;
        if (length == 7) return 1;
        if (length == 8) return 5;
        if (length == 9) return 6;
        if (length == 10) return 2;
        if (length == 11) return 1;
        if (length == 12) return 8;
        if (length == 13) return 7;
        if (length == 14) return 5;
        if (length == 15) return 9;
        if (length == 16) return 8;
        if (length == 17) return 7;
        if (length == 18) return 3;
        if (length == 19) return 4;
        if (length == 20) return 7;
        if (length == 21) return 4;
        if (length == 22) return 2;
        if (length == 23) return 1;
        if (length == 24) return 10;
        if (length == 25) return 9;
        if (length == 26) return 3;
        if (length == 27) return 6;
        if (length == 28) return 11;
        if (length == 29) return 12;
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

    public long nextLong() {
        return Long.parseLong(nextString());
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