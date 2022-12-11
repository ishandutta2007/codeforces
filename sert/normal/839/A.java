import java.io.*;
import java.util.*;

public class Main {
    void run(FastIO io) {
        int n = io.nextInt();
        int k = io.nextInt();

        int mx = 8;
        int ans = -1;

        int sum = 0;
        for (int i = 0; i < n; i++) {
        	int x = io.nextInt();
        	sum += x;

        	if (sum >= 8) {
        		k -= 8;
        		sum -= 8;
        	} else {
        		k -= sum;
        		sum = 0;
        	}

        	if (k <= 0 && ans == -1) {
        		ans = i + 1;
        	}
        }

        io.println(ans);
    }

    public static void main(String[] args) {
    	int tests = 1;
    	if (args.length == 1 && args[0].equals("MadeBySert")) {
    		tests = 4;
    	}
        try (FastIO io = new FastIO(System.in, System.out)) {
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