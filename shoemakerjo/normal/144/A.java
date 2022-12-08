import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class ArrivalGeneral {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		ArrayList<Integer> nums = new ArrayList<Integer>();
		int[] nums2 = new int[n];
		for (int i = 0; i < n; i++) {
			int cur = s.nextInt();
			nums.add(cur);
			nums2[i] = cur;
		}
		Arrays.sort(nums2);
		int min = nums2[0];
		int max = nums2[nums2.length-1];
		int ans = 0;
		ans = nums.indexOf(max) + n-1-nums.lastIndexOf(min);
		if (nums.indexOf(max) > nums.lastIndexOf(min)) ans--;
		System.out.println(ans);
		

	}

}