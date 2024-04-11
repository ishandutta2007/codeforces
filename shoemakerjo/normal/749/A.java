import java.util.Scanner;

public class BachGold {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		if (n%2==0) {
			int amount = n/2;
			System.out.println(amount);
			for (int i = 0; i < amount; i++) {
				System.out.print(2);
				if (i<amount-1) {
					System.out.print("  ");
				}
				
			}
			System.out.println();
		}
		else {
			int amount = (n-1)/2-1;
			System.out.println(amount+1);
			for (int i = 0;i < amount; i++) {
				System.out.print(2 + " " );
			}
			System.out.println(3);
		}

	}

}