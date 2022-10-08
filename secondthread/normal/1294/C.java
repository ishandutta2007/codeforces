import java.util.Arrays;
import java.util.Scanner;
/*
 * 
3 3 1
aba

 */
public class C {
	
	public static void main(String[] args) {
		Scanner fs = new Scanner(System.in);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			long n=fs.nextLong();
			long fact1=getFact(n, 2);
			if (fact1==-1) {
				
			}
			n/=fact1;
			long fact2=getFact(n, fact1+1);
			if (fact2==-1) {
				System.out.println("NO");
				continue;
			}
			n/=fact2;
			if (n==1||n==fact1||n==fact2) {
				System.out.println("NO");
				continue;
			}
			System.out.println("YES\n"+fact1+" "+fact2+" "+n);
		}
	}
	

	static long getFact(long n, long min) {
		for (long i=min; i*i<n; i++)
			if (n%i==0) return i;
		return -1;
	}
	
}