/**
 * Created by Alex on 10/20/2014.
 */

import java.io.*;
import java.util.*;

public class B295 {
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
        new B295().run();
    }

    final int INF = Integer.MAX_VALUE / 2;

    public void solve() throws IOException {
        int n = nextInt();
        int[][] d = new int[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(d[i], INF);
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = nextInt();
        int[] queries = new int[n];
        for (int i = 0; i < n; ++i)
            queries[i] = nextInt() - 1;
        ArrayList<Long> ans = new ArrayList<>();
        boolean[] checked = new boolean[n];
        for (int k = n - 1; k >= 0; --k) {
            long sum = 0;
            checked[queries[k]] = true;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j) {
                    d[i][j] = Math.min(d[i][j], d[i][queries[k]] + d[queries[k]][j]);
                    if (checked[i] && checked[j])
                        sum += d[i][j];
                }
            ans.add(sum);
        }
        Collections.reverse(ans);
        for (long x : ans)
            out.print(x + " ");

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