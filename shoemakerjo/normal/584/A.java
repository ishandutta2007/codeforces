import java.util.Scanner;

public class OlesyaRodion {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		long n = s.nextLong(); //1 to 100
		long t = s.nextLong(); //
		if (t==10) {
			if (n==1) System.out.println(-1);
			else {
				System.out.print(10);
				for (int i = 0; i < n-2; i++) {
					System.out.print(0);
				}
				System.out.println();
			}
		}
		else {
			System.out.print(t);
			for (int i = 0; i < n-1; i++) {
				System.out.print(0);
			}
			System.out.println();
		}
	}

}