import java.io.BufferedReader;
import java.io.InputStreamReader;

public class C018 {
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(r.readLine());
		long[] sums = new long[n + 1];
		sums[0] = 0;
		String[] s = r.readLine().split(" ");
		for (int x = 0; x < n; x++) {
			sums[x + 1] = sums[x] + Integer.parseInt(s[x]);
		}
		if (sums[n] % 2 != 0) {
			System.out.println(0);
			return;
		}
		long count = 0, want = sums[n] / 2;
		for (int i = 1; i < n; i++) {
			if (sums[i] == want)
				count++;
		}
		System.out.println(count);
	}
}