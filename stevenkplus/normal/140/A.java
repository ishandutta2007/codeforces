import java.util.Scanner;


public class A100 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		double pi = Math.PI;
		int n = in.nextInt(),R=in.nextInt(),r=in.nextInt();
		int perim = 2*n*r;
		double rr = r + r/Math.sin(pi/n);
		System.out.println(rr<=R||(n==1&&R>=r)||(n==2&&R>=2*r)?"YES":"NO");
	}
}