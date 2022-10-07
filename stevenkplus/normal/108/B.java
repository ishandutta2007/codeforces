import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B108 {
	public static void main(String[] args) throws Exception {
		System.out.println(b() ? "YES" : "NO");
	}

	public static boolean b() throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(r.readLine());
		StringTokenizer st = new StringTokenizer(r.readLine());
		int[] ar = new int[n];
		for (int x = 0; x < n; x++) {
			int k = Integer.parseInt(st.nextToken());
			ar[x] = k;
		}
		Arrays.sort(ar);
		int prev = ar[0];
		for (int x = 1; x < n; x++) {
			int k = ar[x];
			if (k == prev)
				continue;
			if (prev * 2L > k) {
				return true;
			}
			prev = k;
		}

		return false;
	}
}