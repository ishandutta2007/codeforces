import java.io.*;
import java.util.*;

public class B {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        String s = in.next();
        int t = 0;
        int p = -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
                if (s.charAt(i) == '.') {
                        if (t == 1) ans++;
                } else if (s.charAt(i) == 'L') {
                    if (t == 2 && (i - p - 1) % 2 == 1) ans++;
                    t = 1;
                    p = i;
                } else if (s.charAt(i) == 'R') {
                        if (t == 0) ans += i;
                        t = 2;
                        p = i;
                }
                //System.err.println(ans);
        }
        if (t == 0) ans = n;
        out.println(ans);
    }

    void run() {
        try {
            in = new FastScanner(new File("1.in"));
            out = new PrintWriter(new File("1.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new B().runIO();
    }
}