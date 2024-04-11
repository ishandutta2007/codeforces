import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Random;
import java.util.StringTokenizer;
/*


0000
0000
0001
0001
0010

000
001
002
011
022

One set is just a bit string of length 20 (can happen multiple times)

If we have two bit strings which differ in only one position, they can be a meta set

5 4
0 0 0 0
0 0 0 1
0 0 0 2
1 1 0 0
2 2 0 0


 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		// int T=fs.nextInt();
		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=fs.nextInt();
			int[][] cards=new int[n][];
			for (int i=0; i<n; i++) cards[i]=fs.readArray(k);
			int[] maskCount=new int[1<<k];
			// for (int[] a:cards) map.add(toL(a));
			
			int[] partOf=new int[n];
			for (int i=0; i<n; i++) {
				HashSet<Long> map=new HashSet<>();
				for (int j=0; j<n; j++) {
					if (j==i) continue;
					// int mask=0;
					// for (int bit=0; bit<k; bit++) {
					// 	if (cards[i][bit]!=cards[j][bit]) mask+=1<<bit;
					// }
					int[] o=match(cards[i], cards[j]);
					if (map.contains(toL(o))) {
						partOf[i]++;
					}
					map.add(toL(cards[j]));
				}
			}
			// System.out.println(Arrays.toString(partOf));
			long ans=0;
			for (int i=0; i<n; i++) {
				ans+=partOf[i]*(long)(partOf[i]-1)/2;
			}

			// for (int start=0; start<1<<k; start++) {
			// 	for (int bit=0; bit<k; bit++) {
			// 		int end=start^(1<<bit);
			// 		if (end>start) continue;
			// 		ans+=maskCount[start]*maskCount[end];
			// 	}
			// }
			out.println(ans);
		}
		out.close();
	}

	static int[] match(int[] a, int[] b) {
		int[] res=new int[a.length];
		for (int i=0; i<a.length; i++) res[i]=o(a[i], b[i]);
		return res;
	}
	static long toL(int[] a) {
		long ans=0;
		for (int i:a) ans=ans*3+i;
		return ans;
	}
	static int o(int a, int b) {
		if (a==b) return a;
		return a^b^3;
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