import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {

    class Man {
        int h, w;

        Man(int w, int h) {
            this.w = w;
            this.h = h;
        }
    }

    void solve() throws IOException {
        int n = in.nextInt();
        Man[] m = new Man[n];
        for (int i = 0; i < n; ++i) {
            m[i] = new Man(in.nextInt(), in.nextInt());
        }
        int ans = Integer.MAX_VALUE;
        for (int H = 1; H < 2000; H++) {
            int res = 0;
            boolean ok = true;
            for (Man p : m) {
                if (p.w <= H && p.h <= H) {
                    res += Math.min(p.w, p.h);
                } else if (p.w <= H) {
                    res += p.h;
                } else if (p.h <= H) {
                    res += p.w;
                } else ok = false;
            }
            if (ok) ans = Math.min(ans, res * H);
        }
        out.println(ans);
    }

    static FastReader in;
    static PrintWriter out;
    static PrintStream err;

    public static void main(String[] args) {
        try {
            in = new FastReader();
            out = new PrintWriter(System.out);
            err = System.err;
            new B().solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}

class FastReader {
    BufferedReader br;
    StringTokenizer st;

    FastReader(InputStream is) {
        br = new BufferedReader(new InputStreamReader(is));
    }

    FastReader() {
        this(System.in);
    }

    FastReader(String file) throws FileNotFoundException {
        this(new FileInputStream(file));
    }

    String nextToken() throws IOException {
        while (st == null || !st.hasMoreElements()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
}