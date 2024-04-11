import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B002 {
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		int[][] arr = new int[n][n];
		int minn = Integer.MAX_VALUE;
		String best = "";
		for (int x = 0; x < n; x++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			for (int y = 0; y < n; y++) {
				arr[x][y] = Integer.parseInt(st.nextToken());
				if (arr[x][y] == 0) {
					minn = 1;
					StringBuffer temp = new StringBuffer();
					for(int i =0;i<x;i++) {
						temp.append("D");
					}
					for(int i=1;i<n;i++) {
						temp.append("R");
					}
					for(int i=1;i<n-x;i++) {
						temp.append("D");
					}
					best = temp.toString();
				}
			}
		}
		int[] arreuo = { 5, 2 };
		for (int k : arreuo) {

			int[] ar = new int[n];
			boolean[][] blah = new boolean[n][n];
			ar[0] = lol(k, arr[0][0]);
			for (int i = 1; i < 2 * n - 1; i++) {
				int st = i;
				if (st >= n)
					st = n - 1;
				for (int j = st; j >= 0 && j >= i - n + 1; j--) {
					int c = lol(k, arr[i - j][j]);
					if (j == i) {
						ar[j] = ar[j - 1] + c;
						blah[i - j][j] = true;
					} else if (j == 0) {
						ar[j] = ar[j] + c;
					} else {
						int a = ar[j - 1] + c;
						int b = ar[j] + c;
						if (a < b) {
							blah[i - j][j] = true;
							ar[j] = a;
						} else {
							ar[j] = b;
						}
					}
				}
			}
			int min = ar[n - 1];
			if (min < minn) {
				minn = min;
				StringBuffer b = new StringBuffer();
				int x = n - 1, y = n - 1;
				while (x + y != 0) {
					if (blah[x][y]) {
						y--;
						b.append("R");
					} else {
						x--;
						b.append("D");
					}
				}
				best = b.reverse().toString();

			}
			if (minn == 0)
				break;

		}
		System.out.println(minn);
		System.out.println(best);
	}

	static int lol(int k, int r) {
		if (r == 0)
			return 0;
		int ret = 0;
		while (r % k == 0) {
			ret++;
			r /= k;
		}
		return ret;
	}
}