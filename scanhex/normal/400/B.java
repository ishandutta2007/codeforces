/**
 * Created by Alex on 10.03.14.
 */

import java.io.*;
import java.util.*;

public class B {
    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }

    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[] dist = new int[n];
        for (int i = 0; i < n; i++) {
            String s = nextToken();
            int i1 = -1;
            int i2 = -1;
            for (int j = 0; j < m; j++) {
                if (s.charAt(j) == 'G') i1 = j;
                if (s.charAt(j) == 'S') i2 = j;
            }
            if (i2 - i1 < 0) {
                out.print(-1);
                out.close();
                System.exit(0);
            }
            dist[i] = i2 - i1;
        }
        HashSet<Integer> dist1 = new HashSet<Integer>();
        for (int i : dist) dist1.add(i);
        out.print(dist1.size());
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}