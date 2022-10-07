import java.util.Scanner;

public class B139 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] peris = new int[n];
		int[] heights = new int[n];
		for (int x = 0; x < n; x++) {
			int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
			peris[x] = 2 * (a + b);
			heights[x] = c;
		}
		int m = in.nextInt();
		int[] prices = new int[m], xx = new int[m], yy = new int[m];
		for (int x = 0; x < m; x++) {
			int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
			prices[x] = c;
			xx[x] = a;
			yy[x] = b;
		}
		long sum = 0;
		for (int x = 0; x < n; x++) {
			long min = Integer.MAX_VALUE;
			for (int y = 0; y < m; y++) {
				int peri = yy[y]*(xx[y]/heights[x]);
				if(peri==0) continue;
				long cost = prices[y]
						* (long) Math.ceil((double) peris[x] / peri);
				if (cost < min)
					min = cost;
			}
			sum += min;
		}
		System.out.println(sum);
	}
}