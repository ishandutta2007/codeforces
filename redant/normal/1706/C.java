import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author RedAnt
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CQpwoeirutAndTheCity solver = new CQpwoeirutAndTheCity();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class CQpwoeirutAndTheCity {
        final long[] base = new long[]{0, 0};
        int n;
        int[] h;

        private long getResultDp() {
            long[][] dp = new long[n][2];
            for (int i = 1; i + 1 < n; i++) {
                dp[i] = dp[i - 1].clone();
                long[] nxt = (i >= 2 ? dp[i - 2].clone() : base.clone());
                nxt[0]++;
                int mx = Math.max(h[i - 1], h[i + 1]);
                nxt[1] += (h[i] > mx ? 0 : (mx + 1 - h[i]));
                if (nxt[0] > dp[i][0] || (nxt[0] == dp[i][0] && nxt[1] < dp[i][1])) {
                    dp[i] = nxt;
                }
            }
            return dp[n - 2][1];
        }

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            n = in.nextInt();
            h = new int[n];
            for (int i = 0; i < n; i++) {
                h[i] = in.nextInt();
            }
            out.println(getResultDp());
        }

    }
}