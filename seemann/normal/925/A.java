import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Math.abs;
import static java.lang.Math.min;

public class probA {
    class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastScanner(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    private int count(int x1, int y1, int x2, int y2, int y3, int v) {
        int res = abs(y1 - y3);
        res += abs(x1 - x2) / v;
        res += (abs(x1 - x2) % v) != 0 ? 1 : 0;
        res += abs(y2 - y3);
        return res;
    }

    private int solve(int x1, int y1, int x2, int y2, ArrayList<Integer> lest, int v) {
        if (x1 == x2) {
            return abs(y1 - y2);
        }

        int l = 0;
        int r = lest.size();
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (lest.get(m) <= y1) {
                l = m;
            } else {
                r = m;
            }
        }
        int ans = count(x1, y1, x2, y2, lest.get(l), v);
        if (l + 1 < lest.size()) {
            ans = min(ans, count(x1, y1, x2, y2, lest.get(l + 1), v));
        }
        return ans;
    }


    public void run() throws IOException {
        FastScanner in = new FastScanner(System.in);
        //FastScanner in = new FastScanner(new FileInputStream("input.txt"));
        //PrintWriter out = new PrintWriter("output.txt");

        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        int lestn = in.nextInt();
        int liftn = in.nextInt();
        int v = in.nextInt();

        ArrayList<Integer> lest = new ArrayList<>();
        for (int i = 0; i < lestn; i++) {
            lest.add(in.nextInt());
        }

        ArrayList<Integer> lift = new ArrayList<>();
        for (int i = 0; i < liftn; i++) {
            lift.add(in.nextInt());
        }

        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();

            int ans = -1;
            if (lest.size() > 0) {
                ans = solve(x1, y1, x2, y2, lest, 1);
            }
            if (lift.size() > 0) {
                if (ans < 0) {
                    ans = solve(x1, y1, x2, y2, lift, v);
                } else {
                    ans = min(ans, solve(x1, y1, x2, y2, lift, v));
                }
            }
            out.println(ans);
        }

        out.close();
    }

    public static void main(String[] args) throws IOException {
        new probA().run();
    }
}