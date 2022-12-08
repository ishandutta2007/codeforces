import java.util.Scanner;

public class EpicGame {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int b = s.nextInt();
		int n = s.nextInt();
		boolean Simon = true;
		while (n > 0) {
			if (Simon) {
				Simon = false;
				int gcd = 0;
				for (int i = n; i >= 0; i--) {
					if (a%i==0&&n%i==0) {
						gcd = i;
						break;
					}
				}
				n-=gcd;
			}
			else {
				Simon = true;
				int gcd = 0;
				for (int i = n; i >= 0; i--) {
					if (b%i==0&&n%i==0) {
						gcd = i;
						break;
					}
				}
				n-=gcd;
			}
		}
		if (Simon) System.out.println(1);
		else System.out.println(0);

	}

}