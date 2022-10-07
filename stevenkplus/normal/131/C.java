import java.util.Scanner;

public class C131 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
		long sum =0;
		for(int x=4;x<=a;x++) {
			if(c-x<1) break;
			sum+=choose(a,x)*choose(b,c-x);
		}
		System.out.println(sum);
	}
	static long choose(int a, int b) {
		if(b>a) return 0;
		if(b*2>a) return choose(a,a-b);
		long ret = 1;
		for(long x =1;x<=b;x++) {
			ret*=(a-x+1);
			ret/=x;
		}
		return ret;
	}
}