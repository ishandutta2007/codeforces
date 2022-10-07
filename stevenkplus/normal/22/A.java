import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class A022 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		ArrayList<Integer> nums = new ArrayList<Integer>();
		int n = in.nextInt();
		for(int x = 0;x<n;x++) {
			int k =in.nextInt();
			if(!nums.contains(k)) nums.add(k);
		}
		Collections.sort(nums);
		if(nums.size()<2) System.out.println("NO");
		else System.out.println(nums.get(1));
		
	}
}