import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
1
a
 */
public class G {
	
	static final long mod=998244353;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[][] input=new int[n][];
		for (int i=0; i<n; i++) input[i]=toCount(fs.next());
		
		//minAtBit[letter][mask]
		int[][] minAtLetter=new int[26][1<<n];
		for (int letter=0; letter<26; letter++) {
			Arrays.fill(minAtLetter[letter], Integer.MAX_VALUE/3);
			for (int mask=1; mask<1<<n; mask++) {
				if (Integer.bitCount(mask)==1) {
					minAtLetter[letter][mask]=input[Integer.numberOfTrailingZeros(mask)][letter];
				}
				else {
					int lastGuy=Integer.numberOfTrailingZeros(mask);
					minAtLetter[letter][mask]=Math.min(minAtLetter[letter][mask-(1<<lastGuy)], 
							input[lastGuy][letter]);
				}
			}
		}
//		for (int i=0; i<2; i++) {
//			System.out.println("Min at letter: "+Arrays.toString(minAtLetter[i]));
//		}
		
		long[] waysOfDoingMask=new long[1<<n];
		for (int mask=1; mask<1<<n; mask++) {
			long ways=1;
			for (int letter=0; letter<26; letter++) {
				ways=mul(ways, 1+minAtLetter[letter][mask]);
			}
			waysOfDoingMask[mask]=ways;
		}
//		System.out.println(Arrays.toString(waysOfDoingMask));
		
		
		long[] realValues=new long[1<<n];
		for (int mask=1; mask<1<<n; mask++) {
			realValues[mask]=Integer.bitCount(mask)%2==0?-waysOfDoingMask[mask]:waysOfDoingMask[mask];
		}
		//memory optimized, super easy to code.
		long[] F=new long[1<<n];
		for(int i = 0; i<(1<<n); ++i)
			F[i] = realValues[i];
		for(int i = 0;i < n; ++i) for(int mask = 0; mask < (1<<n); ++mask){
			if((mask & (1<<i))!=0)
				F[mask] += F[mask^(1<<i)];
		}
		long ans=0;
		for (int mask=1; mask<1<<n; mask++) {
			long curAns=sub(F[mask], 0);
			long multiplier=0;
			for (int i=0; i<n; i++) {
				if ((mask&(1<<i))!=0) {
					multiplier+=i+1;
				}
			}
			multiplier*=Integer.bitCount(mask);
			ans^=curAns*multiplier;
		}
		System.out.println(ans);
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
	
	static int[] toCount(String line) {
		int[] cs=new int[26];
		for (char c:line.toCharArray()) cs[c-'a']++;
		return cs;
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