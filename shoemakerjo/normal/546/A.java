import java.util.Scanner;

public class SoldierBananas {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		long k = s.nextInt(); //cost
		long n = s.nextInt(); //money
		long w = s.nextInt(); //number to buy
		long price = 0;
		for (long i = 1; i <= w; i++) {
			price += i*k;
		}
		long ans = price-n;
		if (ans <= 0) {
			System.out.println(0);
		}
		else System.out.println(ans);

	}

}