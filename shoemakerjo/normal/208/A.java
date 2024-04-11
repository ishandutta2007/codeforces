import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Dubstep {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String line = s.next();
		String[] ans = line.split("WUB");
//		System.out.print(Arrays.toString(ans));
		ArrayList<String> act = new ArrayList<String>();

		for (int i = 0; i < ans.length; i++) {
			String cur = ans[i];
			if (!cur.equals("")) act.add(cur);
		}
		for (int i = 0; i < act.size(); i++) {
			System.out.print(act.get(i));
			if (i < act.size()-1) System.out.print(" ");
		}
		System.out.println();

	}

}