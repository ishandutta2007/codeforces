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

    private static final int MAGIC = 100;
    private static final int SIZE = 2 * MAGIC + 1;

    public void solve(int testNumber, Reader in, OutputWriter out) {

        int[][] map = new int[SIZE][SIZE];
        map[MAGIC][MAGIC] = in.nextInt();
        boolean changed = true;
        while (changed) {
            changed = false;
            for(int i = 0; i < SIZE; ++i)
                for(int j = 0; j < SIZE; ++j) {
                    if(map[i][j] >= 4) {
                        map[i - 1][j] += map[i][j] / 4;
                        map[i + 1][j] += map[i][j] / 4;
                        map[i][j - 1] += map[i][j] / 4;
                        map[i][j + 1] += map[i][j] / 4;
                        map[i][j] %= 4;
                        changed = true;

                    }
                }
        }

        long t = in.nextLong();
        for(int i = 0; i < t; ++i) {
            int x = in.nextInt();
            int y = in.nextInt();
            if(x + MAGIC < 0 || x + MAGIC >= SIZE || y  + MAGIC < 0 || y + MAGIC >= SIZE)
                out.println(0);
            else
                out.println(map[x + MAGIC][y + MAGIC]);
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