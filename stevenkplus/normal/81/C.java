import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C081 {
	static class pair implements Comparable<pair> {
		int index, val, num;

		public pair(int v, int k) {
			val = v;
			index = k + 1;
		}

		public int compareTo(pair o) {

			if (sortBy) {
				int D = o.val - val;
				if (D == 0)
					return rat*(o.index - index);
				return D;
			} else
				return index - o.index;
		}
	}

	static boolean sortBy = true;
	static int rat = -1;
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(r.readLine());
		StringTokenizer t = new StringTokenizer(r.readLine());
		int a = Integer.parseInt(t.nextToken()), b = Integer.parseInt(t
				.nextToken());
		pair[] p = new pair[n];
		t = new StringTokenizer(r.readLine());
		boolean constant = true;
		int first = -1;
		for (int x = 0; x < n; x++) {
			int k = Integer.parseInt(t.nextToken());
			if (first == -1)
				first = k;
			if (first != k)
				constant = false;
			p[x] = new pair(k, x);
		}
		first = 1;
		int second = 2;
		rat =-1;
		if (a > b&&!constant) {
			int c = a;
			a = b;
			b = c;
			first = 2;
			second = 1;
			rat = 1;
		}
		if (a != b && !constant)
			Arrays.sort(p);
		for (int x = 0; x < a; x++) {
			p[x].num = first;
		}
		for (int x = a; x < n; x++) {
			p[x].num = second;
		}
		sortBy = false;
		Arrays.sort(p);
		String sep = "";
		for (int x = 0; x < n; x++) {
			System.out.print(sep + p[x].num);
			sep = " ";
		}
		System.out.println();
	}
}