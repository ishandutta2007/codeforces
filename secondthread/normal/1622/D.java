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


   1     1      1      1
   
 4 bars, 10 0s, 14 choose 10 ways to distribute
 
//not enough 1s to do even one op => 1
 
//overcount if we don't put a zero in the leftmost place

//first one-gap that changes -> define our window

possible that it's too far to the right to be valid in the problem, but that should be okay
we have some bars, and x zeros, BF number of zeros in first group != original
 
 */
public class D {

	
	public static void main(String[] args) {
		precomp();
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt(), k=fs.nextInt();
		char[] line=fs.next().toCharArray();
		ArrayList<Integer> inGap=new ArrayList<>();
		int count=0;
		for (char c:line) {
			if (c=='1') {
				inGap.add(count);
				count=0;
			}
			else {
				count++;
			}
		}
		inGap.add(count);
		if (inGap.size()-1<k || k==0) {
			System.out.println(1);
			return;
		}
		int[] cs=new int[inGap.size()+1];
		for (int i=1; i<cs.length; i++) cs[i]=cs[i-1]+inGap.get(i-1);
		long total=1;
		for (int l=0; l+1<inGap.size(); l++) {
			int r=Math.min(inGap.size()-1, l+k);
			total=add(total, nWays(l, r, inGap.get(l), cs));
		}
		System.out.println(total);
		
	}
	static long nWays(int start, int end, int startOrignalSize, int[] cs) {
		int nZeros=cs[end+1]-cs[start];
		long ans=0;
		for (int startSize=0; startSize<=nZeros; startSize++) {
			if (startSize==startOrignalSize) continue;
			int nLeft=nZeros-startSize;
			int nBars=end-start-1;
//			System.out.println("For startSize "+startSize+" "+nLeft+" "+nBars);
			ans=add(ans, nCk(nLeft+nBars, nBars));
		}
//		System.out.println("nWays returning "+ans+" for start: "+start+" -> "+end);
		return ans;
	}
	
	static final Random random=new Random();
	static final int mod=998244353;
	
	static long[] facts=new long[10_001];
	static long[] invFacts=new long[10_001];
	static void precomp() {
		facts[0]=invFacts[0]=1;
		for (int i=1; i<facts.length; i++) {
			facts[i]=mul(facts[i-1], i);
			invFacts[i]=inv(facts[i]);
		}
	}
	static long nCk(int n, int k) {
		return mul(facts[n], mul(invFacts[k], invFacts[n-k]));
	}
	
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
	static long exp(long base, long e) {
		if (e==0) return 1;
		long half=exp(base, e/2);
		if (e%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	static long inv(long x) {
		return exp(x, mod-2);
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