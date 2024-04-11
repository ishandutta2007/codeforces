import java.util.Scanner;


public class A004 {
	public static void main(String[] args) throws Exception {
		System.out.println(f(new Scanner(System.in).nextInt())?"YES":"NO");
	}
	static boolean f(int n){
		if(n==2) return false;
		return n%2==0;
	}
}