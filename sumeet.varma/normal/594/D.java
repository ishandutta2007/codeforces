import java.io.*;
import java.util.*;

public class R330qA {

	static long segtree[];
	static final int mod = (int)1e9 + 7;
	
	@SuppressWarnings("unchecked")
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		final int m = (int)1e6;
		int n = in.nextInt();
		
		int a[] = new int[n + 1];
		for(int i=1;i<=n;i++)
			a[i] = in.nextInt();
		
		boolean prime[] = sieve(m);
		
		ArrayList<Integer> primeFactors[] = new ArrayList[m + 1];
		for(int i=1;i<=m;i++)
			primeFactors[i] = new ArrayList<Integer>();
		
		for(int i=2;i<=m;i+=2)
			primeFactors[i].add(2);
		
		for(int i=3;i<=m;i+=2)
			if(prime[i])
				for(int j=i;j<=m;j+=i)
					primeFactors[j].add(i);
		
		int q = in.nextInt();
		
		ArrayList<Integer> g[] = new ArrayList[n + 1];
		for(int r=1;r<=n;r++)
			g[r] = new ArrayList<Integer>();
		
		for(int i=1;i<=q;i++){
			int l = in.nextInt();
			int r = in.nextInt();
			g[r].add(i);
			g[r].add(l);
		}
		
		int ans[] = new int[q + 1];
		int last[] = new int[m + 1];
		segtree = new long[4*n];
		Arrays.fill(segtree, 1);
		
		for(int i=1;i<=n;i++){
			for(int x : primeFactors[a[i]]){
				if(last[x] != 0){
					a[last[x]] /= x - 1;
					a[last[x]] *= x;
					upd(1,n,0,last[x],a[last[x]]);
				}
				last[x] = i;
				a[i] /= x;
				a[i] *= x - 1;
			}
			upd(1,n,0,i,a[i]);
			int s = g[i].size();
			for(int j=0;j<s;){
				int idx = g[i].get(j++);
				int left = g[i].get(j++);
				ans[idx] = (int)find(1,n,0,left,i);
			}
		}
		
		for(int i=1;i<=q;i++)
			w.println(ans[i]);
		
		w.close();
	}
	
	public static int inv(int x){
		return (int)pow(x,mod-2);
	}
	
	public static long pow(int a,int b){
		if(b == 0)
			return 1;
		long t = pow(a,b >> 1);
		t = (t * t) % mod;
		if((b & 1) == 1)
			t = (t * a) % mod;
		return t;
	}
	
	public static boolean[] sieve(int n){
		boolean prime[] = new boolean[n+1];
		Arrays.fill(prime,true);
		prime[0] = prime[1] = false;
		
		for(int i=2;i*i<=n;i++)
			if(prime[i]) 
				for(int k=i*i;k<=n;k+=i) 
					prime[k] = false;
		
		return prime;
	}
	
		
	static void upd(int s,int e,int c,int x,int v){
		if(s == e)
			segtree[c] = v;
		else{
			int m = (s + e) >> 1;
			if(x <= m)
				upd(s,m,2*c+1,x,v);
			else
				upd(m+1,e,2*c+2,x,v);
			segtree[c] = (segtree[2*c+1] * segtree[2*c + 2]) % mod;
		}
	}
	
	static long find(int s,int e,int c,int l,int r){
		if(s == l && e == r)
			return segtree[c];
		int m = (s + e) >> 1;
		if(r <= m)
			return find(s,m,2*c+1,l,r);
		if(l > m)
			return find(m+1,e,2*c+2,l,r);
		return (find(s,m,2*c+1,l,m) * find(m+1,e,2*c+2,m+1,r)) % mod;
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			int res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}
		
		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			long res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}
		
		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}