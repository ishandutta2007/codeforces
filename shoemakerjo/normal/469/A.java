import java.util.HashSet;
import java.util.Scanner;

public class IWanna {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		HashSet<Integer> nums = new HashSet<Integer>();
		int p = s.nextInt();
		for (int i = 0; i < p; i++) {
			nums.add(s.nextInt());
		}
		int q = s.nextInt();
		for (int i  = 0; i < q; i++) {
			nums.add(s.nextInt());
		}
		boolean good = true;
		for (int i = 1; i <=n; i++) {
			if (!nums.contains(i)) {
				good = false;
				break;
			}
		}
		if (good) System.out.println("I become the guy.");
		else System.out.println("Oh, my keyboard!");

	}

}