import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, Reader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        if( k == 1){
            int cnt = (m + n + n - 2) / (n - 1);
            out.println(cnt);
            for(int  i = 0 ; i < cnt;++i){
                out.print(1 + (n - 1) * i + " ");
            }
            return;
        }
        if( m < n){
            out.println(2 * k);
            for(int i = 0; i < k; ++i){
                out.print("1 ");
            }
            out.print(n+ " ");
            for(int i = 1; i < k; ++i){
                out.print(n + 1 + " ");
            }
            return;
        }
        out.println(2 * k + 1);

        for(int i = 0; i < k; ++i){
            out.print("1 ");
        }
        out.print(n+ " ");
        for(int i = 1; i < k; ++i){
            out.print(n + 1 + " ");
        }
        out.print(m + n);
        return;
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