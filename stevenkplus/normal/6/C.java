import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C006 {
	public static void main(String[] args) throws Exception {

		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(r.readLine());
		int[] sums = new int[n];
		StringTokenizer st = new StringTokenizer(r.readLine());
		sums[0] = Integer.parseInt(st.nextToken());
		for (int x = 1; x < n; x++) {
			sums[x] = sums[x - 1] + Integer.parseInt(st.nextToken());
		}
		int res = 0;
		for(int x = 0;x<n;x++) {
			int sum1 = 0;
			if(x>0) sum1 = sums[x-1];
			int sum2 = sums[n-1] - sums[x];
			if(sum1<=sum2) {
				res = x+1;
			}
		}
		System.out.println(res+" "+(n-res));
	}
}