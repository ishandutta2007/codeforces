import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*

1
10 7 12

 */
public class E {
	
	public static void main(String[] args) throws InterruptedException {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			long m=fs.nextInt(), d=fs.nextInt(), w=fs.nextInt();
			long countUpTo=Math.min(d, m);
			long realMod=w/gcd(w, d-1);
			long nBigger=countUpTo%realMod;
			long smallerSize=countUpTo/realMod;
			long nSmaller=realMod-nBigger;
			long ans=nC2(smallerSize)*nSmaller + nC2(smallerSize+1)*nBigger;
			System.out.println(ans);
		}
	}
	
	static long gcd(long a, long b) {
		return b==0?a:gcd(b, a%b);
	}
	
	static long nC2(long n) {
		return n*(n-1)/2;
	}
	
	void sort(int[] a) {
		ArrayList<Integer> list=new ArrayList<>();
		for (int i:a) list.add(i);
		Collections.sort(list);
		for (int i=0; i<a.length; i++) a[i]=list.get(i);
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