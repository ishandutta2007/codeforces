import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class codeforces27e {
	static int[] primes;
	public static void main(String[] args) {
		primes = sieve(100);
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		System.out.println(min(0,n,64));
		
	}
	static long min(int a, int b, int lim) {
		if(b==1) return 1;
		long min = -1;
		for(int x=2;x<lim;x++ ){
			if(b%x==0) {
				long val = (long)Math.pow(primes[a], x-1);
				long k=min(a+1,b/x,x+1);
				if(k==-1) continue;
				long durg = val*k;
				if(durg<val) continue;
				if(durg<min || min==-1) min =durg;
			}
		}
		return min;
	}
	static int[] sieve(int lim) {
		lim++;
		boolean[] ar = new boolean[lim];
		int count = lim - 2;
		ar[0] = ar[1] = true;
		for (int x = 2; x < lim; x++) {
			if (!ar[x]) {
				for (int y = x * x; y < lim; y += x) {
					if (!ar[y]) {
						count--;
						ar[y] = true;
					}
				}
			}
		}
		int[] primes = new int[count];
		count = 0;
		for (int x = 2; x < lim; x++) {
			if (!ar[x]) {
				primes[count++] = x;
			}
		}
		return primes;

	}
}