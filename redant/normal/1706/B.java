import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        BMakingTowers solver = new BMakingTowers();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class BMakingTowers {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] cnt = new int[n];
            int[] prev = new int[n];
            Arrays.fill(prev, -1);
            for (int i = 0; i < n; i++) {
                int c = in.nextInt() - 1;
                cnt[c]++;
                if (prev[c] != -1 && (i - prev[c]) % 2 == 0)
                    cnt[c]--;
                prev[c] = i;
            }
            for (int i = 0; i < n; i++) {
                out.print(cnt[i] + " ");
            }
            out.println();
        }

    }
}