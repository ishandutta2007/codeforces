import java.util.Scanner;


public class A055 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println(m(in.nextInt())?"YES":"NO");
	}
	static boolean m(int a) {
		boolean[] vis = new boolean[a];
		int p = 0;
		for(int x = 0;x<=a*2;x++) {
			p+=x;
			p%=a;
			vis[p] = true;
		}
		for(int x = 0;x<a;x++) {
			if(!vis[x]) return false;
		}
		return true;
	}
}