import java.util.Scanner;

public class A115 {
	static class guy {
		guy boss;
		int dist = -1;

		public guy() {
			boss = null;
		}

		public int getDist() {
			if (dist == -1) {
				if (boss == null) {
					dist = 1;
				} else
					dist = 1 + boss.getDist();
			}
			return dist;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		guy[] g = new guy[n];
		for (int x = 0; x < n; x++) {
			g[x] = new guy();
		}
		for(int x = 0;x<n;x++) {
			int next = in.nextInt();
			if(next==-1) continue;
			g[x].boss = g[next-1];
		}
		int max = 0;
		for(int x =0;x<n;x++ ){
			int k = g[x].getDist();
			if(k>max) max = k;
		}
		System.out.println(max);
	}
}