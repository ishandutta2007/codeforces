import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class VityaCountryside {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[] nums = new int[n];
		for (int i = 0; i < n; i++) {
			nums[i] = s.nextInt();
		}
		if (n==0) {
			System.out.println(-1);
		
		}
		if (n==1) {
			if (nums[0]==15) System.out.println("DOWN");
			else if (nums[0] == 0) System.out.println("UP");
			else System.out.println(-1);
		}
		else {
			if ((nums[n-2] > nums[n-1] && nums[n-1]!=0 ) || nums[n-1]==15) System.out.println("DOWN");
			else System.out.println("UP");
		}

	}

}