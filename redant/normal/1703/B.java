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
        BICPCBalloons solver = new BICPCBalloons();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class BICPCBalloons {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            String s = in.next();
            boolean[] vis = new boolean[26];
            int r = 0;
            for (char c : s.toCharArray()) {
                int x = c - 'A';
                if (!vis[x]) ++r;
                vis[x] = true;
                ++r;
            }
            out.println(r);
        }

    }
}