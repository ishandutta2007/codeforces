import java.util.Scanner;

public class A107 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int p = in.nextInt(), k = in.nextInt();
		boolean[] vis = new boolean[p],ens = new boolean[p];
		int[] diams = new int[p];
		int[] dest = new int[p];
		for (int x = 0; x < k; x++) {
			int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
			dest[a - 1] = b;
			diams[a - 1] = c;
			ens[b-1] = true;
		}
		int[] starts = new int[p], ends = new int[p], d = new int[p];
		int i = 0;
		for (int x = 0; x < p; x++) {
			if (!ens[x]&&!vis[x]) {
				int min = Integer.MAX_VALUE;
				int y = x;
				vis[y] = true;
				while (dest[y] != 0){
					if (diams[y] < min)
						min = diams[y];
					y = dest[y] - 1;
					vis[y] = true;
					if(x==y) break;
				} 
				if (x != y) {
					starts[i] = x;
					ends[i] = y;
					d[i++] = min;
				}
			}
		}
		System.out.println(i);
		for (int x = 0; x < i; x++) {
			System.out.printf("%d %d %d\n", starts[x] + 1, ends[x] + 1, d[x]);
		}
	}
}