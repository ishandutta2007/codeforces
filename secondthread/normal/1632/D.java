import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

/*

2
1 4

 */
public class D {

	static final boolean debug=false;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			int[][] lift=new int[20][n];
			int modificationsMade=0;
			for (int i=0; i<n; i++) {
				if (debug) System.out.println("\n\nSTARTING AT "+i+" "+Arrays.toString(a));
				lift[0][i]=a[i];
				for (int e=1; e<20; e++) {
					int rangeStart=i-(1<<(e-1));
					if (rangeStart>=0)
						lift[e][i]=gcd(lift[e-1][i], lift[e-1][rangeStart]);
					else
						lift[e][i]=lift[e-1][i];
				}
//				for (int j=0; j<=i; j++) {
//					for (int k=j; k<=i; k++) {
//						if (debug) System.out.println("  Gcd from "+j+" to "+k+" is "+rangeGCD(j, k, lift));
//					}
//				}
				if (!okay(i, a[i], lift)) {
					a[i]=1_000_000_007;
					modificationsMade++;
				}
				lift[0][i]=a[i];
				for (int e=1; e<20; e++) {
					int rangeStart=i-(1<<(e-1));
					if (rangeStart>=0)
						lift[e][i]=gcd(lift[e-1][i], lift[e-1][rangeStart]);
					else
						lift[e][i]=lift[e-1][i];
				}
				out.print(modificationsMade+" ");
			}
			out.println();
		}
		out.close();
	}
	
	static boolean okay(int r, int gcd, int[][] lift) {
		//find all of the times that the gcd changes
		int l=getLeftmostTimeGCDIsX(r, gcd, lift);
		if (debug) System.out.println("Got leftmost time gcd is "+gcd+" is "+l);
		if (checkInvalid(r, r, l, lift)) return false;
		while (l!=0) {
			l--;
			gcd=rangeGCD(l, r, lift);
			int rightL=l;
			l=getLeftmostTimeGCDIsX(r, gcd, lift);
			int leftL=l;
			if (checkInvalid(r, rightL, leftL, lift)) return false;
		}
		return true;
	}
	
	static boolean checkInvalid(int r, int rightL, int leftL, int[][] lift) {
		if (debug) System.out.println("Checking invalid "+leftL+" "+r+"  to "+rightL+" "+r);
		int gcd=rangeGCD(leftL, r, lift);
		int minSize=r-rightL+1;
		int maxSize=r-leftL+1;
		if (gcd>=minSize && gcd<=maxSize) return true;
		return false;
	}
	
	static int getLeftmostTimeGCDIsX(int r, int gcd, int[][] lift) {
		int minL=0, maxL=r;
		while (minL!=maxL) {
			int midL=(minL+maxL)/2;
			int rangeGCD=rangeGCD(midL, r, lift);
			if (debug) System.out.println("    Getting "+midL+" "+rangeGCD+" "+gcd);
			if (rangeGCD%gcd!=0) {
				minL=midL+1;
			}
			else {
				maxL=midL;
			}
		}
		return minL;
	}
	
	
	static int rangeGCD(int l, int r, int[][] lift) {
		int size=r-l+1;
		if (size==1) return lift[0][r];
		int maxOneBit=Integer.highestOneBit(size);
		int exp=Integer.numberOfTrailingZeros(maxOneBit);
		return gcd(lift[exp][r], lift[exp][l+maxOneBit-1]);
	}
	
	
	static int gcd(int a, int b) {
		if (b==0) return a;
		return gcd(b, a%b);
	}
	
	
	static final Random random=new Random();
	static final int mod=1_000_000_007;
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	static long mul(long a, long b) {
		return (a*b)%mod;
	}
	static long exp(long base, long exp) {
		if (exp==0) return 1;
		long half=exp(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	static long[] factorials=new long[2_000_001];
	static long[] invFactorials=new long[2_000_001];
	static void precompFacts() {
		factorials[0]=invFactorials[0]=1;
		for (int i=1; i<factorials.length; i++) factorials[i]=mul(factorials[i-1], i);
		invFactorials[factorials.length-1]=exp(factorials[factorials.length-1], mod-2);
		for (int i=invFactorials.length-2; i>=0; i--)
			invFactorials[i]=mul(invFactorials[i+1], i+1);
	}
	
	static long nCk(int n, int k) {
		return mul(factorials[n], mul(invFactorials[k], invFactorials[n-k]));
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}