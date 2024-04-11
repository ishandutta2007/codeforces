import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        int[] a = in.readIntArray(n);
        for (int i = 0; i < n; i++) {
            a[i] --;
        }
        boolean[] onCycle = new boolean[n];
        for (int i = 0; i < n; i++) {
            int cur = i;
            for (int t = 0; t < n; t++) {
                cur = a[cur];
            }
            for (int t = 0; t < n; t++) {
                onCycle[cur] = true;
                cur = a[cur];
            }
        }
        boolean[] used = new boolean[n];
        ArrayList<Integer> length = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!onCycle[i] || used[i]) {
                continue;
            }
            int cur = a[i], len = 1;
            used[i] = true;
            while (!used[cur]) {
                used[cur] = true;
                len++;
                cur = a[cur];
            }
            length.add(len);
        }
        BigInteger ans = BigInteger.ONE;
        for (int i : length) {
            BigInteger g = ans.gcd(BigInteger.valueOf(i));
            ans = ans.multiply(BigInteger.valueOf(i)).divide(g);
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            int count = 0, cur = i;
            while (!onCycle[cur]) {
                cur = a[cur];
                count++;
            }
            max = Math.max(max, count);
        }
        BigInteger realAns = ans;
        while (realAns.compareTo(BigInteger.valueOf(max)) < 0) {
            realAns = realAns.add(ans);
        }
        out.printf("%d\n", realAns);
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(BufferedReader reader) {
        this.reader = reader;
    }

    public InputReader(Reader reader) {
        this(new BufferedReader(reader));
    }

    public InputReader(InputStream stream) {
        this(new InputStreamReader(stream));
    }

    private String nextLine() {
        String result;
        try {
            result = reader.readLine();
        } catch (IOException exception) {
            throw new RuntimeException(exception);
        }
        return result;
    }

    public String readWord() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(nextLine());
        }
        return tokenizer.nextToken();
    }

    public int readInt() {
        return Integer.parseInt(readWord());
    }

    public int[] readIntArray(int size) {
        int[] result = new int[size];
        for (int i = 0; i < size; i++) {
            result[i] = readInt();
        }
        return result;
    }

}

class OutputWriter {
    private PrintWriter writer;

    public OutputWriter(PrintWriter writer) {
        this.writer = writer;
    }

    public OutputWriter(Writer writer) {
        this(new PrintWriter(writer));
    }

    public OutputWriter(OutputStream stream) {
        this(new OutputStreamWriter(stream));
    }

    public void printf(String format, Object...args) {
        writer.printf(format, args);
    }

    public void close() {
        writer.close();
    }
}