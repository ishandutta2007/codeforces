import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int sum=s.nextInt();
		for (int smaller=sum/2; sum>=1; smaller--) {
			if (gcd(smaller, sum-smaller)==1) {
				System.out.println(smaller+" "+(sum-smaller));
				return;
			}
		}

	}
	
	
	public static int gcd(int a, int b) {
		if (a<b) {
			return gcd(b, a);
		}
		int c=a%b;
		if (c==0) {
			return b;
		}
		return gcd(b,c);
	}
}