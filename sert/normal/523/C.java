import java.lang.*;
import java.util.*;
import java.io.*;

import static java.util.Arrays.copyOf;

public class Problem {

    void solve() throws IOException {
        char[] s = in.nextToken().toCharArray();
        char[] t = in.nextToken().toCharArray();
        int n = s.length;
        int k = t.length;
        int l = -1;
        for (int i = 0, j = 0; i < k; ++i) {
            if (t[i] == s[j]) ++j;
            if (j == n) {
                l = i;
                break;
            }
        }
        int r = -1;
        for (int i = k - 1, j = n - 1; i >= 0; --i) {
            if (t[i] == s[j]) --j;
            if (j == -1) {
                r = i;
                break;
            }
        }
        int ans = Math.max(0, r - l);
        out.println(ans);
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