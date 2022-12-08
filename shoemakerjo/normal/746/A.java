import java.util.Scanner;

public class Compote {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int b = s.nextInt();
		int c = s.nextInt();
		int ans = a/1;
		ans = Math.min(ans, b/2);
		ans = Math.min(ans, c/4);
		System.out.println(ans*7);

	}

}