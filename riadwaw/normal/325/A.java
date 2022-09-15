import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        long S = 0;
        long minX = Integer.MAX_VALUE;
        long maxX = Integer.MIN_VALUE;
        long minY = Integer.MAX_VALUE;
        long maxY = Integer.MIN_VALUE;

        for(int i = 0; i < n; ++i) {
            long x1, y1, x2, y2;
            minX = Math.min(minX, x1 = in.nextInt());
            minY = Math.min(minY, y1 = in.nextInt());
            maxX = Math.max(maxX, x2 = in.nextInt());
            maxY = Math.max(maxY, y2 = in.nextInt());

            S += (x2 - x1) * (y2 - y1);
        }

        //System.err.println(minX + " " + minY + " " + maxX + " " + maxY);

        out.println(((maxX - minX) * (maxY - minY) == S && maxX - minX == maxY - minY) ? "YES" : "NO");
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