import java.util.Scanner;


public class A080 {
	static boolean isPrime(int a) {
		for(int x=2;x<a;x++) if(a%x==0) return false;
		return true;
	}
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int a =in.nextInt(),b=in.nextInt();
		int x;
		for(x=a+1;x<=b;x++) {
			if(isPrime(x)) break;
		}
		System.out.println(x==b?"YES":"NO");
	}
}