import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
/*
3 2
1 0 2
1 1 1
3 2
1 0 2
1 1 1
 */
public class A {

	static long mod=1_000_000_007;
	static int[] a;static int[] b;
	static int alphaSize;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		alphaSize=fs.nextInt();
		a=new int[n];
		b=new int[n];
		for (int i=0; i<n; i++) b[i]=fs.nextInt();
		for (int i=0; i<n; i++) a[i]=fs.nextInt();
		long waysWon=0;
		long waysToTie=1;
		long waysHere=1;
		for (int i=0; i<n; i++) {
//			System.out.println(i+" ways won: "+waysWon+" waysToTie: "+waysToTie+" "+waysHere);
			if (a[i]==0) {
				if (b[i]==0) {
					waysWon=mul(waysWon, mul(alphaSize, alphaSize));
					waysHere=mul(waysHere, mul(alphaSize, alphaSize));
					waysWon+=mul(nC2(alphaSize), waysToTie);
					
					waysToTie=mul(waysToTie, alphaSize);
				}
				else {
					waysWon=mul(waysWon, alphaSize);
					waysHere=mul(waysHere, alphaSize);
					
					waysWon+=mul(waysToTie, b[i]-1);
					//waysToTie stays the same
				}
			}
			else {
				if (b[i]==0) {
					int bChoices=alphaSize-a[i];
					waysWon=mul(waysWon, alphaSize);
					waysHere=mul(waysHere, alphaSize);

					waysWon+=mul(waysToTie, bChoices);
					//waysToTie stays the same
				}
				else {
					if (b[i]==a[i]) {
						//waysToTie stays the same
					}
					else {
						if (a[i]<b[i]) {
							waysWon+=waysToTie;
						}
						waysToTie=0;
					}
				}
			}
		}
//		System.out.println("Ways won: "+waysWon+" here: "+waysHere);
		long ans=mul(waysWon, inv(waysHere));
		System.out.println(ans);
	}
	
	static long nC2(int n) {
		long over2=inv(2);
		return mul(mul(n, n-1), over2);
	}
	
	static long mul(long a, long b) {
		return a*b%mod;
	}
	
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	
	static long pow(long base, long exp) {
		if (exp==0) return 1;
		long half=pow(base, exp/2);
		if (exp%2==0) return mul(half, half);
		else {
			return mul(half, mul(half, base));
		}
	}
	
	static long inv(long x) {
		return pow(x, mod-2);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
			
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}

}