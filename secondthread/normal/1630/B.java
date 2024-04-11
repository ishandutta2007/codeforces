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
3
2 1
1 2
 */
public class B {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int k=fs.nextInt();
			
			int[] a=fs.readArray(n);
			int[] cs=new int[n+1];
			for (int i:a) cs[i]++;
			for (int i=1; i<cs.length; i++) cs[i]+=cs[i-1];
			
			int bestL=0, bestR=n;
			for (int l=0; l<n; l++) {
				int r=getMinR(cs, l, n, k);
//				System.out.println("Considering "+l+" "+r);
				if (r-l<bestR-bestL) {
					bestL=l;
					bestR=r;
				}
			}
			out.println(bestL+1+" "+(bestR+1));
//			System.out.println(bestL+" "+bestR);
			//then extract answer
			int nToPrint=k;
			int at=0, count=0;
			int start=0;
			for (int i=0; i<a.length; i++) a[i]--;
			while (nToPrint>1) {
				//include at
				if (a[at]>=bestL && a[at]<=bestR)
					count++;
				else count--;
				if (count>0) {
					out.println((start+1)+" "+(at+1));
					count=0;
					at++;
					start=at;
					nToPrint--;
				}
				else {
					at++;
				}
			}
			out.println(at+1+" "+n);
		}
		out.close();
	}
	
	static int getMinR(int[] cs, int start, int n, int k) {
		int needed=((n-k+1)/2+k);
//		System.out.println("Needed: "+needed);
		int min=start, max=n;
		if (cs[n]-cs[start]<needed) return Integer.MAX_VALUE/2;
		while (min!=max) {
			int mid=(min+max)/2;
			if (cs[mid+1]-cs[start]>=needed) {
				max=mid;
			}
			else {
				min=mid+1;
			}
		}
		return min;
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