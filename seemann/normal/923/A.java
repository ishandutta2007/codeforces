import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
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

    private ArrayList<Integer> getDivizors(int x) {
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 2; i < Math.sqrt(x) + 3; i++) {
            if (x % i == 0) {
                res.add(i);
            }
            while (x % i == 0) {
                x = x / i;
            }
        }
        if (x > 0) {
            res.add(x);
        }
        return res;
    }

    private int getMinStart(int y) {
        ArrayList<Integer> divisors2 = getDivizors(y);
        int m = 2000000;

        for (Integer div : divisors2) {
            int start = y - div + 1;
            if (start < 3) {
                start = y;
            }
            if (start < m) {
                m = start;
            }
        }
        return m;
    }


    public void run() throws IOException {
        FastScanner in = new FastScanner(System.in);
        //FastScanner in = new FastScanner(new FileInputStream("input.txt"));


        //PrintWriter out = new PrintWriter("output.txt");

        PrintWriter out = new PrintWriter(System.out);

        int x = in.nextInt();
        ArrayList<Integer> divisors1 = getDivizors(x);

        int ans = 2000000;
        int mdiv = 0;

        for (Integer div : divisors1) {
            int start = x - div + 1;
            if (start < 3) {
                start = x;
            }
            for (int prev_x = start; prev_x <= x; prev_x++) {
                int res = getMinStart(prev_x);
                if (res < ans) {
                    ans = res;
                    mdiv = prev_x;
                }
            }
        }
        out.print(ans);

        out.close();
    }

    public static void main(String[] args) throws IOException {
        new probA().run();
    }
}