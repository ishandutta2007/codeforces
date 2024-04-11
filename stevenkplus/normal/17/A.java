import java.util.Arrays;
import java.util.Scanner;


public class A017 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(),k=in.nextInt();
		int[] primes = sieve(n);
		int c = 0;
		for(int x = 0;x<primes.length-1;x++) {
			if(Arrays.binarySearch(primes,primes[x]+primes[x+1]+1)>0) {
				c++;
			}
		}
		System.out.println(c>=k?"YES":"NO");
	}
	static int[] sieve(int n) {
		int i = n-1;
		boolean[] ar = new boolean[n+1];
		ar[0]=ar[1]=true;
		for(int x = 2;x<=n;x++) {
			if(!ar[x]) {
				for(int y = x*x;y<=n;y+=x) {
					if(!ar[y]) {
						ar[y] = true;
						i--;
					}
				}
			}
		}
		
		
		int[] ret = new int[i];
		i = 0;
		for(int x = 2;x<=n;x++) {
			if(!ar[x]) ret[i++] = x;
		}
		return ret;
	}
}