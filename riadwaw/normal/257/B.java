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
        int ans = Math.max(solve(n, m), solve(m, n));
        out.println(ans + " " + (n + m - 1 - ans));
    }

    int solve(int a, int b){
        int[] x = new int[a + b];
        x[0] = 0;

        int cnt[] = new int[]{a - 1, b};

        for(int i = 1; i < a + b; ++i){
            if(i % 2 == 1 && cnt[1 - x[i - 1]] > 0){
                --cnt[1 - x[i - 1]];
                x[i] = 1 - x[i - 1];
                continue;
            }
            if(i % 2 == 0 && cnt[x[i - 1]] > 0){
                --cnt[x[i - 1]];
                x[i] = x[i - 1];
                continue;
            }
            if(cnt[1 - x[i - 1]] > 0){
                --cnt[1 - x[i - 1]];
                x[i] = 1 -x[i - 1];
                continue;
            }
            if(cnt[x[i - 1]] > 0){
                --cnt[x[i - 1]];
                x[i] = x[i - 1];
                continue;
            }
        }


        int res = 0;
        for(int  i = 0 ; i < x.length - 1 ; ++i){
            if(x[i] == x[i + 1])
                res++;
        }

        //System.out.println(Arrays.toString(cnt));
        return res;
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