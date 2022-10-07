import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A060 {
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer r = new StringTokenizer(in.readLine());
		int top = Integer.parseInt(r.nextToken()), bottom = 1, m = Integer
				.parseInt(r.nextToken());
		for (int x = 0; x < m; x++) {
			StringTokenizer line = new StringTokenizer(in.readLine());
			line.nextToken();
			line.nextToken();
			boolean b = line.nextToken().charAt(0) == 'r';
			line.nextToken();
			int n = Integer.parseInt(line.nextToken());
			if (b) {
				int k = n + 1;
				if (k > bottom)
					bottom = k;
			} else {
				int k = n - 1;
				if (k < top)
					top = k;
			}

		}
		int ans = top - bottom + 1;
		System.out.println(ans > 0 ? ans : -1);
	}
}