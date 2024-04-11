import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class D120 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("input.txt"));
		int n = in.nextInt(), m = in.nextInt();
		int[] a = new int[n];
		int[] b = new int[m];
		int[] cols = new int[m];
		int p = 0;
		for (int x = 0; x < n; x++) {
			int s = 0;
			for (int i = 0; i < m; i++) {
				int next = in.nextInt();
				s += next;
				cols[i] += next;
			}
			a[x] = s + p;
			p += s;
		}
		p = 0;
		int A = in.nextInt(), B = in.nextInt(), C = in.nextInt();
		for (int x = 0; x < m; x++) {
			b[x] = p + cols[x];
			p += cols[x];
		}
		int count = 0;
		for (int x = 0; x < n; x++) {
			for (int y = x+1; y+1 < n; y++) {
				int s1 = a[x], s2 = a[y] - a[x], s3 = a[n - 1] - a[y];
				if (s1 == A && s2 == B && s3 == C || s1 == B && s2 == A
						&& s3 == C || s1 == B && s2 == C && s3 == A || s1 == A
						&& s2 == C && s3 == B || s1 == C && s2 == A && s3 == B
						|| s1 == C && s2 == B && s3 == A)
					count++;
			}
		}
		a = b;
		for (int x = 0; x < m; x++) {
			for (int y = x+1; y+1 < m; y++) {
				int s1 = a[x], s2 = a[y] - a[x], s3 = a[m - 1] - a[y];
				if (s1 == A && s2 == B && s3 == C || s1 == B && s2 == A
						&& s3 == C || s1 == B && s2 == C && s3 == A || s1 == A
						&& s2 == C && s3 == B || s1 == C && s2 == A && s3 == B
						|| s1 == C && s2 == B && s3 == A)
					count++;
			}
		}
		PrintWriter out = new PrintWriter("output.txt");
		out.println(count);
		out.close();
	}
}