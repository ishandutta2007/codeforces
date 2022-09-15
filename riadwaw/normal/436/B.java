import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.StringTokenizer;

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
        int k = in.nextInt();
        String[] s = in.nextStringArray(n);
        int[] ans = new int[m];
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if (s[i].charAt(j) == 'R') {
                    if(j + i < m) {
                        ans[j + i] ++;
                    }
                }
                if(s[i].charAt(j) == 'L') {
                    if(j - i >= 0) {
                        ans[j - i]++;
                    }
                }
                if(s[i].charAt(j) == 'U') {
                    if(i % 2 == 0) {
                        ans[j] ++;
                    }
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            out.print(ans[i] + " ");
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

    public String[] nextStringArray(int size) {
        String[] array = new String[size];
        for (int i = 0; i < size; ++i) {
            array[i] = nextString();
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

	public OutputWriter(Writer writer){
		super(writer);
	}

}