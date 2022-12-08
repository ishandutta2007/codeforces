import java.io.*;
import java.util.*;
public class AverageSleepTime {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int[] nums = new int[n];
		int weeks = n-k+1;
//		System.out.println(n + " " + k);
		st = new StringTokenizer(bf.readLine());
		for (int i = 0; i < n; i++) {
			nums[i] = Integer.parseInt(st.nextToken());
		}
//		System.out.println(Arrays.toString(nums))
		long sum = 0;
		for (int i = 0; i < n; i++) {
			long first = Math.max(0, i-k+1);
			long last = Math.min(i, n-k);
			long occ = last-first+1;
			sum+=occ*nums[i];
		}
		double ans = (sum+0.0)/weeks;
//		System.out.println(sum);
		System.out.printf("%.7f\n", ans);
		
	}

}