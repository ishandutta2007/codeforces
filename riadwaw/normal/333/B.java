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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        boolean[] badX = new boolean[n];
        boolean[] badY = new boolean[n];
        for(int i = 0; i < m; ++i) {
            badX[in.nextInt() - 1] = true;
            badY[in.nextInt() - 1] = true;
        }

        long answer = 0;

        for(int i = 1; i < n / 2; ++i) {
            int allowedX = (badX[i] ? 0 : 1) + (badX[n - 1 - i] ? 0 : 1);
            int allowedY = (badY[i] ? 0 : 1) + (badY[n - 1 - i] ? 0 : 1);
            answer += solve(allowedX, allowedY);
        }

        if(n % 2 == 1) {
            if(!badX[n / 2] || !badY[n / 2])
                ++answer;
        }

        out.println(answer);
    }

    private long solve(int allowedX, int allowedY) {
        return allowedX + allowedY;
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