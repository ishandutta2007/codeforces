import java.io.*;
import java.util.*;
public class VanyaLaterns {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int l = s.nextInt();
		ArrayList<Integer> nums = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			nums.add(s.nextInt());
		}
		Collections.sort(nums);
		double ans = Math.max(nums.get(0), l - nums.get(nums.size()-1));
		for (int i = 0; i < nums.size()-1; i++) {
			ans = Math.max(ans, (nums.get(i+1)-nums.get(i))/2.0);
		}
		System.out.printf("%.10f\n",ans);

	}

}