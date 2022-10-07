import java.util.Scanner;

public class A006 {
	public static void main(String[] arsg) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt(),b=in.nextInt(),c=in.nextInt(),d=in.nextInt();
		int e = f(a,b,c),f=f(a,b,d),g=f(a,c,d),h=f(b,c,d);
		if(e<f)e=f;
		if(e<g) e=g;
		if(e<h) e=h;
		String[] ar = "IMPOSSIBLE,SEGMENT,TRIANGLE".split(",");
		System.out.println(ar[e]);
	}

	static int f(int a, int b, int c) {
		if(a+b>c&&a+c>b&&b+c>a) return 2;
		if(a+b==c||a+c==b||b+c==a) return 1;
		return 0;
	}
}