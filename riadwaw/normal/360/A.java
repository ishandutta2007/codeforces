import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
        int m = in.nextInt();
        int[] added = new int[n];
        int[] maxValue = new int[n];
        Arrays.fill(maxValue, 1000000000);

        int[] t = new int[m];
        int[] l = new int[m];
        int[] r = new int[m];
        int[] d = new int[m];
        for(int i = 0; i < m; ++i) {
            t[i] = in.nextInt();
            l[i] = in.nextInt();
            r[i] = in.nextInt();
            d[i] = in.nextInt();
            if(t[i] == 1){
                for(int j = l[i] - 1; j < r[i]; ++j) {
                    added[j] += d[i];
                }

            }
            else {
                for(int j = l[i] - 1; j < r[i]; ++j) {
                    maxValue[j] = Math.min(maxValue[j], d[i] - added[j]);
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            added[i] = maxValue[i];
        }
        for(int i = 0; i < m; ++i) {
           if(t[i] == 1){
                for(int j = l[i] - 1; j < r[i]; ++j) {
                    added[j] += d[i];
                }

            }
            else {
               int mx = -1000000000;


               for(int j = l[i] - 1; j < r[i]; ++j) {
                    mx = Math.max(mx, added[j]);
               }

               if(mx != d[i]) {
                   out.println("NO");
                   return;
               }
            }
        }
         out.println("YES");
        for(int i = 0; i < n; ++i)
            out.print(maxValue[i] + " ");


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