import java.io.*;
import java.util.*;

public class Main {
    void run(FastIO io) {
        int s = io.nextInt();
        int v1 = io.nextInt();
        int v2 = io.nextInt();
        int t1 = io.nextInt();
        int t2 = io.nextInt();

        int tme1 = 2 * t1 + s * v1;
        int tme2 = 2 * t2 + s * v2;

        if (tme1 < tme2) {
        	io.println("First");
        } else if (tme1 == tme2) {
        	io.println("Friendship");
        } else {
        	io.println("Second");
        }
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