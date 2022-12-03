import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		
		int _n = 1;
		while (_n < n) {
			_n *= 2;
		}
		long[][] seg = new long[2][_n * 2 - 1];
		
		Comparator<int[]> cmp = new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if (a[1] <= b[0]) {
					return -1;
				}
				else if (b[1] <= a[0]) {
					return 1;
				}
				else {
					return 0;
				}
			}
		};
		TreeSet<int[]> set = new TreeSet<int[]>(cmp);
		for (int i = 0; i < n; i++) {
			set.add(new int[]{i, i + 1, i + 1});
		}
		
		for (; m > 0; m--) {
			int type = in.nextInt();
			if (type == 1) {
				int l = in.nextInt() - 1;
				int r = in.nextInt();
				int x = in.nextInt();
				
				int[] e = set.ceiling(new int[]{l, l, 0});
				if (e[0] < l && l < e[1]) {
					set.remove(e);
					set.add(new int[]{e[0], l, e[2]});
					set.add(new int[]{l, e[1], e[2]});
				}
				e = set.floor(new int[]{r, r, 0});
				if (e[0] < r && r < e[1]) {
					set.remove(e);
					set.add(new int[]{e[0], r, e[2]});
					set.add(new int[]{r, e[1], e[2]});
				}
				
				SortedSet<int[]> sub = set.subSet(new int[]{l, l, 0}, new int[]{r, r, 0});
				for (int[] _e: sub) {
					add(seg, _e[0], _e[1], Math.abs(_e[2] - x), 0, 0, _n);
				}
				sub.clear();
				set.add(new int[]{l, r, x});
			}
			if (type == 2) {
				int l = in.nextInt() - 1;
				int r = in.nextInt();
				System.out.println(sum(seg, l, r, 0, 0, _n));
			}
		}
	}
	
	static long sum(long[][] seg, int a, int b, int i, int l, int r) {
		if (b <= l || r <= a) {
			return 0;
		}
		else if (a <= l && r <= b) {
			return (r - l) * seg[0][i] + seg[1][i];
		}
		else {
			long res = (Math.min(b, r) - Math.max(a, l)) * seg[0][i];
			res += sum(seg, a, b, i * 2 + 1, l, (l + r) / 2);
			res += sum(seg, a, b, i * 2 + 2, (l + r) / 2, r);
			return res;
		}
	}
	
	static void add(long[][] seg, int a, int b, long x, int i, int l, int r) {
		if (a <= l && r <= b) {
			seg[0][i] += x;
		}
		else if (l < b && a < r) {
			seg[1][i] += (Math.min(b, r) - Math.max(a, l)) * x;
			add(seg, a, b, x, i * 2 + 1, l, (l + r) / 2);
			add(seg, a, b, x, i * 2 + 2, (l + r) / 2, r);
		}
	}
}