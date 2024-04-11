import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Evgeny Savinov
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int [] a = new int[n];
        int [] b = new int[m];
        int mi1 = (int)1e9;
        int ma1 = 0;
        int mi2 = (int)1e9;
        for(int i = 0; i < n; ++i)
        {
            a[i] = in.nextInt();
            mi1 = Math.min(mi1, a[i]);
            ma1 = Math.max(ma1, a[i]);
        }
        for(int i = 0; i < m; ++i)
        {
            b[i] = in.nextInt();
            mi2 = Math.min(mi2, b[i]);
        }
        int min_time = Math.max(mi1 * 2, ma1);
        if (min_time < mi2)
            out.println(min_time);
        else
            out.println(-1);
    }
}