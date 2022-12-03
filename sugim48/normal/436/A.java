import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int x = in.nextInt();
		ArrayList<int[]>[] hm = new ArrayList[2];
		hm[0] = new ArrayList<int[]>();
		hm[1] = new ArrayList<int[]>();
		for (int i = 0; i < n; i++) {
			int t = in.nextInt();
			int h = in.nextInt();
			int m = in.nextInt();
			hm[t].add(new int[]{h, m});
		}
		
		Comparator<int[]> cmp = new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return Integer.compare(a[0], b[0]);
			}
		};
		Collections.sort(hm[0], cmp);
		Collections.sort(hm[1], cmp);
		
		int ans = 0;
		for (int j = 0; j <= 1; j++) {
			int k = 0, t = j, h = x;
			Comparator _cmp = new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return -Integer.compare(a[1], b[1]);
				}
			};
			PriorityQueue<int[]>[] que = new PriorityQueue[2];
			que[0] = new PriorityQueue<int[]>(11, _cmp);
			que[1] = new PriorityQueue<int[]>(11, _cmp);
			int[] i = new int[2];
			
			while (true) {
				while (i[t] < hm[t].size() && hm[t].get(i[t])[0] <= h) {
					que[t].add(hm[t].get(i[t]));
					i[t]++;
				}
				if (!que[t].isEmpty()) {
					h += que[t].remove()[1];
					t = 1 - t;
					k++;
				} else {
					ans = Math.max(ans, k);
					break;
				}
			}
		}
		
		System.out.println(ans);
	}
}