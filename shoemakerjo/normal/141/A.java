import java.util.Scanner;

public class AmusingJoke {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String name = s.nextLine();
		String host = s.nextLine();
		String r = s.nextLine();
		String alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int[] nums = new int[26];
		for (int i = 0; i < name.length(); i++) {
			nums[alph.indexOf(name.charAt(i))]++;
		}
		for (int i = 0; i < host.length(); i++) {
			nums[alph.indexOf(host.charAt(i))]++;
		}
		for (int i = 0; i < r.length(); i++) {
			nums[alph.indexOf(r.charAt(i))]--;
		}
		boolean ok = true;
		for (int i = 0; i < 26; i++) {
			if (nums[i]!=0) ok = false;
		}
		if (ok) System.out.println("YES");
		else System.out.println("NO");

	}

}