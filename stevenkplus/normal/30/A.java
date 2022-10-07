import java.util.Scanner;

public class A030 {
	public static void main(String[] args) {

		int p = ans();
		if (p != Integer.MAX_VALUE)
			System.out.println(p);
		else
			System.out.println("No solution");
	}

	static int ans() {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
		if (b == 0)
			return 0;
		if(a==0) return Integer.MAX_VALUE;
		double r = (double)b / a;
		boolean neg = false;
		if (r < 0) {
			if(c%2==0) {
				return Integer.MAX_VALUE;
			}
			neg = true;
			r = -r;
		}
		double d;
		int p = (int) Math.round(d =( Math.pow(r, 1./c)));
		if(Math.abs(d-p)>=.000001) {
			return Integer.MAX_VALUE;
		}
		if (neg)
			p = -p;

		return p;
	}
}