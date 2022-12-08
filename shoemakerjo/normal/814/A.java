import java.io.*;
import java.util.*;
public class AbandonedSentiment {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String[] cs = bf.readLine().split(" ");
		int n = Integer.parseInt(cs[0]);
		int k = Integer.parseInt(cs[1]);
		int[] nums = new int[n];
		int zi = -1;
		StringTokenizer st = new StringTokenizer(bf.readLine());
		for (int i = 0; i < n; i++) {
			nums[i] = Integer.parseInt(st.nextToken());
			if (nums[i]==0) zi = i;
		}
		int[] nums2 = new int[k];
		st = new StringTokenizer(bf.readLine());
		for (int i = 0; i < k; i++) {
			nums2[i] = Integer.parseInt(st.nextToken());
		}
		
		if (k > 1) {
			System.out.println("Yes");
		}
		else {
			if (k == 1) {
				nums[zi] = nums2[0];
			}
			boolean increasing = true;
			int prev = -1;
			for (int i = 0; i < n; i++) {
				if (nums[i] < prev) increasing = false;
				prev = nums[i];
			}
			if (increasing) System.out.println("No");
			else System.out.println("Yes");
		}

	}

}