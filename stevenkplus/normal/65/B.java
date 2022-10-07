import java.util.Scanner;

public class B065 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int prev = 1000;
		int[] result = new int[n];
		for (int x = 0; x < n; x++) {
			String next = in.next();
			int min = 10000;
			for (int i = 0; i < 4; i++) {
				StringBuffer b = new StringBuffer(next);
				for (int d = 0; d < 10; d++) {
					b.setCharAt(i, (char) ('0' + d));
					int k = Integer.parseInt(b.toString());
					if (k >= prev && (k < min || min == -1)) {
						min = k;
					}
				}
			}
			prev = min;
			result[x] = min;
		}
		if(result[n-1]>2011) {
			System.out.println("No solution");
		}
		else {
			for(int x = 0;x<n;x++) {
				System.out.println(result[x]);
			}
		}
	}
}