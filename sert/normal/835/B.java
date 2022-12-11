import java.io.*;
import java.util.*;

public class Main {
    void run(FastIO io) {
        int sum = io.nextInt();
        String s = io.nextToken();

        int curSum = 0;
        int num[] = new int[10];

        for (int i = 0; i < s.length(); i++) {
        	char ch = s.charAt(i);
        	num[ch - '0']++;
        	curSum += ch - '0';
        }

        if (curSum >= sum) {
        	io.println(0);
        	return;
        }

        int kk = 0;
        for (int d = 0; d < 9; d++) {
        	if (curSum + (9 - d) * num[d] >= sum) {
        		io.println(kk + (sum - curSum + 8 - d) / (9 - d));
        		return;
        	}

        	kk += num[d];
        	curSum += (9 - d) * num[d];
        }        
    }

    public static void main(String[] args) {
        int tests = 1;
    	if (args.length == 1 && args[0].equals("MadeBySert")) {
    		tests = 3;
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