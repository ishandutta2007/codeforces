
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Double.max;
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

    public void run() throws IOException {
        FastScanner in = new FastScanner(System.in);
        //FastScanner in = new FastScanner(new FileInputStream("input.txt"));
        //PrintWriter out = new PrintWriter("output.txt");

        int n = in.nextInt();
        int u = in.nextInt();

        ArrayList<Integer> lst = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int en = in.nextInt();
            lst.add(en);
        }

        Double energy = -1.0;

        int k = 2;
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            k = min(k, n - 1);
            //System.out.println(k);
            while ((k + 1 < n) && (lst.get(k + 1) - lst.get(i) <= u)) {
                k += 1;
            }

            //System.out.println(i + " " +  j + " " + k);

            if (k <= j || k >= n) {
                continue;
                //continue;
            }
            if (lst.get(k) - lst.get(i) <= u) {
                double good = lst.get(k) - lst.get(j);
                double all = lst.get(k) - lst.get(i);
                energy = max(energy, good / all);
            }
        }

        if (energy < 0) {
            System.out.println(-1);
        } else {
            System.out.format("%.10f\n", energy);
        }

    }

    public static void main(String[] args) throws IOException {
        new probA().run();
    }
}