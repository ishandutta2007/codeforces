import java.lang.*;
import java.util.*;
import java.io.*;

public class Problem {

    void solve() throws IOException {
        PriorityQueue<Long> q = new PriorityQueue<Long>();
        int n = in.nextInt();
        int k = in.nextInt();
        for (int i = 0; i < k; ++i) {
            q.add(0L);
        }
        for (int i = 0; i < n; ++i) {
            int s = in.nextInt();
            int m = in.nextInt();
            long now = q.poll();
            now = Math.max(s, now);
            now += m;
            q.add(now);
            out.println(now);
        }
    }

    static FastReader in;
    static PrintWriter out;
    static PrintStream err;

    public static void main(String[] args) throws IOException {
        try {
            in = new FastReader();
            out = new PrintWriter(System.out);
            err = System.err;
            new Problem().solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

}

class FastReader {
    private StringTokenizer st;
    private BufferedReader br;

    public FastReader() {
        this(System.in);
    }

    public FastReader(InputStream ps) {
        br = new BufferedReader(new InputStreamReader(ps));
    }

    public FastReader(String filename) throws FileNotFoundException {
        this(new FileInputStream(filename));
    }

    public String nextToken() throws IOException {
        while (st == null || !st.hasMoreElements()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}