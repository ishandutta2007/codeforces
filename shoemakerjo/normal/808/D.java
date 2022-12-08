import java.io.*;
import java.util.*;

public class ArrayDivision {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bf.readLine());
		StringTokenizer st = new StringTokenizer(bf.readLine());
		long[] nums = new long[n];
		for (int i = 0; i < n; i++) {
			nums[i] = Long.parseLong(st.nextToken());
		}	
		HashSet<Long> seen = new HashSet<Long>();

		long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += nums[i];
		}
		
		long cursum = 0;
		boolean found = false;
		for (int i = 0; i < n; i++) {
			cursum+=nums[i];
			seen.add(nums[i]);
			long osum = sum-cursum;
			if (osum==cursum) {
				found = true;
				break;
			}
			long diff = cursum-osum;
			if (diff%2==1) continue;
			if (seen.contains(diff/2)) {
				found = true;
				break;
			}
		}
		seen = new HashSet<Long>();
		cursum = 0;
		for (int i = n-1; i >= 0; i--) {
			cursum+=nums[i];
			seen.add(nums[i]);
			long osum = sum-cursum;
			if (osum==cursum) {
				found = true;
				break;
			}
			long diff = cursum-osum;
			if (diff%2==1) continue;
			if (seen.contains(diff/2)) {
				found = true;
				break;
			}
		}
		if (found) System.out.println("YES");
		else System.out.println("NO");
	}

}