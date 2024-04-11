import java.util.ArrayList;
import java.util.Scanner;


public class A027 {
	public static void main(String[] args) {
		ArrayList<Integer> left = new ArrayList<Integer>();
		for(int x = 1;x<=3001;x++) {
			left.add(x);
		}
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for(int x = 0;x<n;x++) {
			left.remove((Integer)in.nextInt());
		}
		System.out.println(left.get(0));
	}
}