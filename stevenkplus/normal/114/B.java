import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class B114 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), m = in.nextInt();
		boolean[][] bad = new boolean[n][n];
		ArrayList<String> names = new ArrayList<String>(n);
		for (int x = 0; x < n; x++) {
			names.add(in.next());
		}
		for (int x = 0; x < m; x++) {
			String a = in.next(), b = in.next();
			int aa = names.indexOf(a), bb = names.indexOf(b);
			bad[aa][bb] = bad[bb][aa] = true;
		}
		int max = 0;
		int[] best = null;
		big: for (int x = 0; x < 1 << n; x++) {
			int y = x;
			int sum = 0;
			int[] ar = new int[n];
			int k = 0;
			for (int i = 0; i < n; i++) {
				if ((y & 1) == 1) {
					for (int j = 0; j < k; j++) {
						if (bad[ar[j]][i]) {
							continue big;
						}
					}
					sum++;
					ar[k++] = i;
				}
				y >>= 1;
			}
			if (sum > max) {
				max = sum;
				best = ar;
			}
		}
		System.out.println(max);
		ArrayList<String> res = new ArrayList<String>(max);
		for (int x = 0; x < max; x++) {
			res.add(names.get(best[x]));
		}
		Collections.sort(res);
		for (String s : res) {
			System.out.println(s);
		}
	}
}