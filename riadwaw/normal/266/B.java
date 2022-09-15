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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int t = in.nextInt();
        CharSequence s = in.nextString();
        
        for(int i = 0; i < t; ++i) {
            StringBuilder sb = new StringBuilder(s);
            for(int j = 0; j + 1< n; ++j) {
                if(s.charAt(j) == 'B' && s.charAt(j + 1) == 'G') {
                    sb.setCharAt(j, 'G');
                    sb.setCharAt(j + 1, 'B');
                }
            }
            s = sb;
        }
        
        out.println(s);
        

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