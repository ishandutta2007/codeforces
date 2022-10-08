import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
1
5 2
4 4 3 3 2

1
3 2
10 1 0

1
5 2
1000000000 1000000000 1 0 0
 */
public class B {

	static long mod=1_000_000_007;
	
	public static void main(String[] args) {
//		System.out.println(fastPow2(2, 10));
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), p=fs.nextInt();
			int[] a=fs.readArray(n);
			if (p==1) {
				if (n%2==0)
					out.println(0);
				else
					out.println(1);
				continue;
			}
			sort(a);
			long[] csToPow=new long[n+1];
			for (int i=1; i<=n; i++) csToPow[i]=add(csToPow[i-1], fastPow2(p, a[i-1]));
			
			//decreasing
			long min=0;
			int index=0;
			for (int power=a[0]; power>=0; power--) {
				min*=p;
				if (min>n) {
					//fast forward to end
					min=mul(min, fastPow2(p, power));
					long afterThis=sub(csToPow[n], csToPow[index]);
					min=sub(min, afterThis);
					break;
				}
				int nOfPower=0;
				while (index<n && a[index]==power) {
					index++;
					nOfPower++;
				}
				if (nOfPower%2==min%2) {
					min=(min-nOfPower);
					if (min<0) min%=2;
				}
				else {
					min=(min-nOfPower);
					if (min<0) min%=2;
					if (min==-1) min=1;
				}
				
				if (min==0) {
					if (index==n) break;
					power=a[index]+1;
				}
			}
			out.println((min%mod+mod)%mod);
		}
		out.close();
	}
	
	static long fastPow(long base, long e) {
		if (e==0) return 1;
		long half=fastPow(base, e/2);
		if (e%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	
	static long fastPow2(long base, int e) {
		long ans=1;
		for (int i=0; 1<<i <=e; i++) {
			if ((e&(1<<i))!=0) {
				ans=mul(ans, base);
			}
			base=mul(base, base);
		}
		return ans;
	}
	
	static long mul(long a, long b) {
		return a*b%mod;
	}
	
	static long add(long a, long b) {
		long ans=(a+b);
		if (ans>=mod) ans-=mod;
		return ans;
	}
	static long sub(long a, long b) {
		long ans=a-b;
		if (ans<0) ans+=mod;
		return ans;
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(a.length-1-i);
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