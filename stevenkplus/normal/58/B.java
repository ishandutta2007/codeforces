import java.util.Scanner;


public class B058 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		System.out.print(n);
		int x = 2;
		while(n!=1) {
			while(n%x==0) {
				System.out.print(" "+(n/=x));
			}
			x+=1+x%2;
		}
		System.out.println();
	}
}