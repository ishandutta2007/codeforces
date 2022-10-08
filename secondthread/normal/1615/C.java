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

1
5
11010
11010

1
3
000
101

1
9
100010111
101101100

1
2
10
00

1
2
11
01


1
2
10
01
 */
public class C {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[] a=fs.next().toCharArray(), b=fs.next().toCharArray();
			int _00=0, _01=0, _10=0, _11=0;
			for (int i=0; i<n; i++) {
				if (a[i]=='0') {
					if (b[i]=='0') _00++;
					else _01++;
				}
				else {
					if (b[i]=='0') _10++;
					else _11++;
				}
			}
			int ans=Integer.MAX_VALUE/2;
			if (_01==_10) {
				ans=_01*2;
			}
			if (_11!=0) {
				if ((_00+1)==_11) {
					ans=Math.min(ans, 1+_00*2);
				}
//				if ((_00-1)==_11) {
//					ans=Math.min(ans, 1+_11*2);
//				}
			}
			if (_10!=0) {
				//never needed?
			}
			if (ans!=Integer.MAX_VALUE/2) {
				out.println(ans);
			}
			else {
				out.println(-1);
			}
		}
		out.close();
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