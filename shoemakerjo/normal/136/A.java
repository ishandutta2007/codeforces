import java.util.Scanner;

public class Presents {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[] nums = new int[n];
		for (int i  = 0; i < n; i++) {
			nums[s.nextInt()-1] = i+1;
		}
		for (int i = 0; i < n; i++) {
			System.out.print(nums[i]);
			if (i < n-1) System.out.print(" ");
		}
		System.out.println();

	}

}