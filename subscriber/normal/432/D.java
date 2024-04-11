import java.io.*;
import java.util.*;

public class D {
    FastScanner in;
    PrintWriter out;

    void solve() {
        String s = in.next();
        int n = s.length();
        int[] p = new int[n];
        p[0] = 0;
        for (int i = 1; i < n; i++) {
            int x = p[i - 1];
            while (x > 0 && s.charAt(x) != s.charAt(i)) x = p[x - 1];
            if (s.charAt(x) != s.charAt(i)) p[i] = 0; else p[i] = x + 1;
        }
        boolean[] good = new boolean[n + 1];
        good[n] = true;
        int x = p[n - 1];
        while (x > 0) {
            good[x] = true;
            x = p[x - 1];
        }
        int[] count = new int[n + 1];
        for (int i = 0; i < n; i++) count[p[i]]++;
        count[n]++;
//      System.err.println(Arrays.toString(count));
        for (int i = n; i > 0; i--) count[p[i - 1]] += count[i];
        ArrayList<Integer> a = new ArrayList();
        ArrayList<Integer> b = new ArrayList();
        for (int i = 1; i <= n; i++) if (good[i] && count[i] > 0) {
            a.add(i);
            b.add(count[i]);
        }
        out.println(a.size());
        for (int i = 0; i < a.size(); i++) {
            out.println(a.get(i) + " " + b.get(i));
        }
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
        new D().runIO();
    }
}