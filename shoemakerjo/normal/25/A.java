import java.util.ArrayList;
import java.util.Scanner;

public class IQTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		boolean even = false;
		boolean odd = false;
		int ans = 0;
		ArrayList<Integer> nums = new ArrayList<Integer>();
		int firstOdd = 0;
		int firstEven = 0;
		int numEven = 0;
		int numOdd = 0;
		for (int i = 1; i <= n; i++) {
			int cur = s.nextInt();
			nums.add(cur);
			if (cur%2==0) {
				numEven++;
				if (!even) firstEven = i;
				even = true;
			}
			else {
				numOdd++;
				if (!odd) firstOdd = i;
				odd = true;
			}
		}
		if (numEven==1) System.out.println(firstEven);
		else System.out.println(firstOdd);
	
	}

}