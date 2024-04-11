import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = in.nextInt();
		int d = in.nextInt();
		long x = in.nextInt();
		
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = i + 1;
		}
		for (int i = 0; i < n; i++) {
			x = (x * 37 + 10007) % 1000000007;
			swap(a, i, (int)x % (i + 1));
		}
		int[] b = new int[n];
		Arrays.fill(b, 0, d, 1);
		for (int i = 0; i < n; i++) {
			x = (x * 37 + 10007) % 1000000007;
			swap(b, i, (int)x % (i + 1));
		}
		
		if (d < 1000) {
			int _k = 0;
			int[] arr = new int[d];
			for (int i = 0; i < n; i++) {
				if (b[i] == 1) {
					arr[_k++] = i;
				}
			}
			for (int i = 0; i < n; i++) {
				int max = 0;
				for (int k = 0; k < d && arr[k] <= i; k++) {
					int j = arr[k];
					max = Math.max(max, a[i - j]);
				}
				out.println(max);
			}
		}
		else {
			int[] arr = new int[n + 1];
			for (int i = 0; i < n; i++) {
				arr[a[i]] = i;
			}
			TreeSet<Integer> set = new TreeSet<Integer>();
			label:
			for (int i = 0; i < n; i++) {
				set.add(-a[i]);
				for (int k: set) {
					int j = arr[-k];
					if (b[i - j] == 1) {
						out.println(-k);
						continue label;
					}
				}
				out.println(0);
			}
		}
		out.flush();
	}
	
	static void swap(int[] a, int i, int j) {
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}