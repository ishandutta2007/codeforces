import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B140 {
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(r.readLine());
		int[][] prefs = new int[n][n];
		for (int x = 0; x < n; x++) {
			StringTokenizer st = new StringTokenizer(r.readLine());
			for (int y = 0; y < n; y++) {
				prefs[x][Integer.parseInt(st.nextToken()) - 1] = n - y - 1;
			}
		}
		int[] pref = new int[n];
		StringTokenizer st = new StringTokenizer(r.readLine());
		for (int x = n - 1; x >= 0; x--) {
			pref[Integer.parseInt(st.nextToken()) - 1] = x;
		}
		String sep = "";
		for (int x = 0; x < n; x++) {
			int best = -1;
			int maxp = 0;
			for (int y = 0; y < n; y++) {
				if (x != y) {
					if (pref[y] >= maxp) {
						if (best == -1
								|| (prefs[x][y] > prefs[x][best] && pref[y] > maxp)) {
							best = y;
						}
						maxp = pref[y];
					}

				}
			}
			System.out.print(sep + (best + 1));
			sep = " ";
		}
		System.out.println();
	}
}