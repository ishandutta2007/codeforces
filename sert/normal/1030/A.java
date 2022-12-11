import java.io.*;
import java.util.*;

public class Main {
    void run(FastIO io) {
        int n = io.nextInt();
        boolean isHard = false;
        for (int i = 0; i < n; i++) {
            if (io.nextInt() == 1) {
                isHard = true;
            }
        }
        io.print(isHard ? "Hard\n" : "Easy\n");
    }

    public static void main(String[] args) {
        try (FastIO io = new FastIO(System.in, System.out)) {
            int tests = 1;
            for (int i = 0; i < tests; i++) {
                new Main().run(io);
            }
        }
    }
    static class FastIO extends PrintWriter {
        BufferedReader br;
        StringTokenizer stok;

        FastIO(InputStream is, OutputStream os) {
            super(os, false);
            br = new BufferedReader(new InputStreamReader(is));
            stok = new StringTokenizer("");
        }
        String nextToken() {
            while (!stok.hasMoreTokens()) {
                String s;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (s == null) {
                    return null;
                }
                stok = new StringTokenizer(s);
            }
            return stok.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(nextToken());
        }
        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
        long nextLong() {
            return Long.parseLong(nextToken());
        }
    }
}