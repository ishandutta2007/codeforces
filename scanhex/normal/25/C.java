/**
 * Created by Alex on 10/20/2014.
 */

import java.io.*;
import java.util.*;

public class C25 {
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
        new C25().run();
    }

    public void solve() throws IOException {
        int n = nextInt();
        int[][] d = new int[n][n];
        long sum = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                d[i][j] = nextInt();
                sum += d[i][j];
            }
        int k = nextInt();
        for (int edge = 0; edge < k; ++edge) {
            int s = nextInt() - 1;
            int t = nextInt() - 1;
            int c = nextInt();
            sum = 0;
            if (d[s][t] > c) {
                d[s][t] = d[t][s] = c;
            }
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j) {
                    if (d[i][j] > d[i][s] + d[s][t] + d[t][j]) {
                        d[i][j] = d[i][s] + d[s][t] + d[t][j];
                    }
                    if (d[i][j] > d[i][t] + d[t][s] + d[s][j]) {
                        d[i][j] = d[i][t] + d[t][s] + d[s][j];
                    }
                    sum += d[i][j];
                }
            out.print(sum / 2 + " ");
        }
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