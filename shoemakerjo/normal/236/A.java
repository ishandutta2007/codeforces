import java.util.Scanner;

public class BoyorGirl {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String line = s.next();
		String alph = "abcdefghijklmnopqrstuvwxyz";
		int ans = 0;
		for (int i = 0; i < alph.length(); i++) {
			if (line.indexOf(alph.charAt(i)) >= 0) {
				ans++;
			}
		}
		if (ans%2==0) {
			System.out.println("CHAT WITH HER!");
		}
		else System.out.println("IGNORE HIM!");

	}

}