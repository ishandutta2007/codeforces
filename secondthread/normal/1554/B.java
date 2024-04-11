import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

/*
1
3 3
1 1 3
 */
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int nBits=Integer.numberOfTrailingZeros(Integer.highestOneBit(n))+1;
			int k=fs.nextInt();
			int[] a=fs.readArray(n);
			P[] biggestIndexOfSubmask=new P[1<<nBits];
			Arrays.fill(biggestIndexOfSubmask, new P(-1, -1));
			for (int i=0; i<n; i++)
				biggestIndexOfSubmask[a[i]]=combine(biggestIndexOfSubmask[a[i]], new P(i, -1));
			for(int i = 0;i < nBits; ++i) 
				for(int mask = 0; mask < (1<<nBits); ++mask) {
					if((mask & (1<<i))!=0)
						biggestIndexOfSubmask[mask] = combine(biggestIndexOfSubmask[mask], biggestIndexOfSubmask[mask^(1<<i)]);
			}
			long ans=Long.MIN_VALUE;
			for (int or=0; or<1<<nBits; or++) {
				P p=biggestIndexOfSubmask[or];
//				System.out.println("Considering or "+or+" val: "+p);
				if (p.a>=0 && p.b>=0) {
					ans=Math.max(ans, or*(long)-k  + (p.a+1)*(long)(p.b+1));
				}
			}
			System.out.println(ans);
		}
	}

	static class P {
		int a, b;
		public P(int a, int b) {
			this.a=a;
			this.b=b;
		}
		public String toString() {
			return "("+a+", "+b+")";
		}
	}
	
	static P combine(P a, P b) {
		int[] vals= {a.a, a.b, b.a, b.b};
		Arrays.sort(vals);
//		System.out.println("Combining "+a+" "+b);
		return new P(vals[2], vals[3]);
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