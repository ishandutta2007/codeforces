import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class probB {
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

    public void run() throws FileNotFoundException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        //FastScanner in = new FastScanner(new FileInputStream("input.txt"));
        //PrintWriter out = new PrintWriter("output.txt");

        int n = in.nextInt();
        long[] v = new long[n + 10];
        long[] t = new long[n + 10];
        long[] res = new long[n + 10];

        int[] start = new int[n + 10];
        int[] finish = new int[n + 10];

        for (int i = 0; i < n; i++) {
            v[i] = in.nextInt();

            start[i] = 0;
            finish[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            t[i] = in.nextInt();
            if (i > 0) {
                t[i] = t[i] + t[i - 1];
            }

            res[i] = 0;
        }


        for (int i = 0; i < n; i++) {
            int l = i - 1;
            int r = n;

            long before_v = 0;
            if (i > 0) {
                before_v = t[i - 1];
            }

            while (r - l > 1) {
                int m = (r + l) / 2;
                if (t[m] - before_v >= v[i]) {
                    r = m;
                } else {
                    l = m;
                }
            }

            //   r  
            // =>     i   r
            if (r < n) {
                long before_r = 0;
                if (r > 0) {
                    before_r = t[r - 1] - before_v;
                }
                res[r] += v[i] - before_r;
            }

            if (r > i) {
                start[i] += 1;
                finish[r] += 1;
            }

        }

        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += start[i];
            cur -= finish[i];

            long x;
            if (i == 0) {
                x = t[i];
            } else {
                x = t[i] - t[i - 1];
            }

            res[i] += x * cur;

            out.print(res[i]);
            out.print(" ");
        }


        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new probB().run();
    }
}