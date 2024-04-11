import java.util.Arrays;
import java.util.Scanner;

public class B099 {
	static class cup implements Comparable<cup> {
		int num;
		int val;

		public cup(int x, int b) {
			num = x;
			val = b;
		}

		public int compareTo(cup o) {
			return val - o.val;
		}
	}

	public static void main(String[] ags) {
		int k = b();
		if (k == 1) {
			System.out.println("Exemplary pages.");
		} else if (k == -1)
			System.out.println("Unrecoverable configuration.");

	}

	public static int b() {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		cup[] ar = new cup[n];
		for (int x = 0; x < n; x++) {
			ar[x] = new cup(x, in.nextInt());
		}
		Arrays.sort(ar);
		int distinct = 0;
		for (int x = 0; x < ar.length - 1; x++) {
			if (ar[x].val != ar[x + 1].val)
				distinct++;
		}
		if (distinct == 0)
			return 1;
		if(distinct==1) {
			if(n==2) {
				int diff = ar[1].val-ar[0].val;
				if(diff%2==0) {
					System.out.printf("%d ml. from cup #%d to cup #%d.\n", diff/2,
							ar[0].num+1, ar[1].num+1);
					return 0;
				}
			}
			return -1;
		}
		if (distinct >2)
			return -1;
		int a = ar[0].val, b = ar[ar.length - 1].val, c = ar[1].val;
		if (c != ar[ar.length - 2].val)
			return -1;
		if (a + b == c + c) {
			System.out.printf("%d ml. from cup #%d to cup #%d.\n", c - a,
					ar[0].num + 1, ar[ar.length - 1].num + 1);
			return 0;
		} else
			return -1;
	}
}