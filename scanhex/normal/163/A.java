/**
 * Created by Alex on 9/22/2014.
 */

import java.io.*;
import java.util.*;

public class A163 {
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
        new A163().run();
    }

    public void solve() throws IOException {
        char[] s = nextToken().toCharArray();
        char[] t = nextToken().toCharArray();
        int[][] d = new int[s.length][t.length];
        int s1, s2 = 0;
        final int MOD = (int)1e9 + 7;
        int ans = 0;
        int sum[] = new int[t.length];
        int[] sum1;
        for (int i = 0; i < s.length; ++i) {
            sum1 = sum;
            sum = new int[t.length];
            for (int j = 0; j < t.length; ++j) {
                if (s[i] != t[j])
                    d[i][j] = 0;
                else
                    d[i][j] = j > 0 ? sum1[j - 1] + 1 : 1;
                sum[j] = (j > 0 ? sum[j - 1] : 0) + d[i][j];
                sum[j] %= MOD;
                ans += d[i][j];
                ans %= MOD;
            }
        }
        out.print(ans);
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