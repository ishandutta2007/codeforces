import java.util.Scanner;
/*
3
1 3 1
1 3 2
1 3 3

3
2 6 1
2 6 2
2 6 3

3
10 30 1
10 30 2
10 30 3
 */
public class C {

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int T=fs.nextInt();
		for (int tt=0; tt<T;tt++) {
			int r=fs.nextInt(),b=fs.nextInt(), k=fs.nextInt();
			if (r>b) {
				int t=r;
				r=b;
				b=t;
			}
			long gcd=gcd(r, b);
			r/=gcd; b/=gcd;
//			int times=(b-1)/r;
			int times;
			if (r==1) {
				times=b-1;
			}
			else {
				times=1+(b-2)/r;
			}
			boolean possible=times<k;
			System.out.println(possible?"OBEY":"REBEL");
		}
	}
	
	
	static long gcd(long a, long b) {
		if (b==0) return a;
		return gcd(b, a%b);
	}

}