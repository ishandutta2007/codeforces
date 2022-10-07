import java.util.Arrays;
import java.util.Hashtable;
import java.util.Scanner;

public class A051 {
	static class amulet {
		int[] ar;

		public amulet(int a, int b, int c, int d) {
			ar = new int[] { a, b, c, d };
			int[] best = null;
			for (int x = 0; x < 4; x++) {
				if (best == null)
					best = ar.clone();
				else {
					boolean better = true;
					for (int y = 0; y < 4; y++) {
						if (best[y] > ar[y]) {
							better = false;
							break;
						}
						if (best[y] < ar[y])
							break;
					}
					if (better)
						best = ar.clone();
				}
				int temp = ar[3];
				ar[3] = ar[2];
				ar[2] = ar[1];
				ar[1] = ar[0];
				ar[0] = temp;
			}
			ar = best;

		}

		public int hashCode() {
			int sum = 0;
			for (int x = 0; x < 4; x++) {
				sum *= 6;
				sum += ar[x];
			}
			return sum;
		}

		public boolean equals(Object o) {
			if (o instanceof amulet) {
				amulet a = (amulet) o;
				return Arrays.equals(ar, a.ar);
			}
			return false;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		Object bleh = new Object();
		Hashtable<amulet, Object> ht = new Hashtable<amulet, Object>();
		for (int x = 0; x < n; x++) {
			String next = in.next();
			int a = next.charAt(0) - '0', b = next.charAt(1) - '0';
			next = in.next();
			int c = next.charAt(0) - '0', d = next.charAt(1) - '0';
			if (x+1<n)
				in.next();
			amulet am = new amulet(a, b, d, c);
			if (ht.containsKey(am))
				continue;
			ht.put(am, bleh);
		}
		System.out.println(ht.size());
	}
}