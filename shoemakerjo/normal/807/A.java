import java.io.*;
import java.util.*;
public class IsItRated {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int curmin = Integer.MAX_VALUE;
		boolean change = false;
		boolean flip = false;
		for (int i = 0; i < n; i++) {
			int pre = s.nextInt();
			int post = s.nextInt();
			if (pre!=post) change = true;
			if (pre > curmin) flip = true;
			curmin = Math.min(curmin, pre);
		}
		if (change) {
			System.out.println("rated");
		}
		else if (flip) {
			System.out.println("unrated");
		}
		else System.out.println("maybe");
	}

}