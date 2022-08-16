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
        AAnotherStringMinimizationProblem solver = new AAnotherStringMinimizationProblem();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class AAnotherStringMinimizationProblem {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            char[] res = new char[m];
            Arrays.fill(res, 'B');
            while (n-- > 0) {
                int i = in.nextInt();
                --i;
                i = Math.min(i, m - 1 - i);
                if (res[i] == 'B')
                    res[i] = 'A';
                else
                    res[m - 1 - i] = 'A';
            }
            out.println(new String(res));
        }

    }
}