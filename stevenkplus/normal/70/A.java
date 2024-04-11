import java.util.Scanner;


public class A070 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		System.out.println(powmod(3,n-1,(int)(1E6+3)));
	}
	static int powmod(int a, int b, int m) {
		int ret = 1;
		for(int x =0;x<b;x++) {
			ret*=a;
			ret%=m;
		}
		return ret;
	}
}