import java.io.InputStreamReader;
import java.io.IOException;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    long sum(int t, int T, int x, int cost, int cnt, int childs){
        if(cnt == 0)
            return Long.MAX_VALUE;
        int mn = childs / cnt;
        int mxcnt = childs % cnt;
        if(mn + t > T){
            return 1L * childs * x + 1L * cost * cnt ;
        }
        if(mn + t == T){
            return 1L * mxcnt * (mn + 1) * x + 1L *cost * cnt * 1L;
        }
        else{
            return 1L*cost*cnt;
        }
    }
    public void solve(int testNumber, Reader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        long ans = 0;
        for(int i = 0;i<n;++i){
            int t = in.nextInt(), T= in.nextInt(), x =in.nextInt(), cost = in.nextInt();

            long best = sum(t, T, x, cost, 1, m);
            if(T > t){
                best = Math.min(best, sum(t, T, x, cost, m/(T - t), m));
                best = Math.min(best, sum(t, T, x, cost, m/(T - t) + 1, m));
            }
            //System.err.println(best);
            ans += best;
        }
        out.print(ans);
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