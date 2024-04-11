import java.util.Scanner;


public class A092 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		for(int x=1;true;x++) {
			if(m<x) break;
			m-=x;
			x%=n;
		}
		System.out.println(m);
	}
}