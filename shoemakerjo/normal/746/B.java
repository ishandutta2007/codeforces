import java.util.Scanner;

public class Decoding {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		String encoded = s.next();
		String ans = "";
		for (int i = 0; i < n; i++) {
			if (i%2!=n%2) {
				ans = ans+encoded.charAt(i);
			}
			else ans = encoded.charAt(i) + ans;
		}
		System.out.println(ans);
	}

}