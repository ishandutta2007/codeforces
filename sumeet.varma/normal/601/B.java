import java.io.*;
import java.util.*;

public class R333qB {

	static int N;
	static int a[];
	static int b[];
	static int n,q;
	static RmqSparseTable rmq;
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
	
		N = in.nextInt();
		q = in.nextInt();
		
		a = new int[N];
		for(int i=0;i<N;i++)
			a[i] = in.nextInt();
		
		n = N - 1;
		b = new int[n];
		for(int j=0;j<n;j++)
			b[j] = Math.abs(a[j + 1] - a[j]);
		
		rmq = new RmqSparseTable(b);
		
		while(q-- > 0)
			w.println(go(in.nextInt() - 1,in.nextInt() - 1));
		
		w.close();
	}
	
	public static long go(int l,int r){
		if(l >= r)
			return 0;
		int idx = rmq.maxPos(l,r-1);
		long left = (idx - l + 1);
		long right = (r - l + 1) - left;
		return go(l,idx) + go(idx + 1,r) + b[idx] * left * right;
	}
	
	/*
	static class Brute{
		int a[];
		Brute(int b[]){
			a = new int[b.length];
			for(int i=0;i<b.length;i++)
				a[i] = b[i];
		}
		long query(int l,int r){
			long ans = 0;
			for(int i=l;i<=r;i++){
				for(int j=i;j<=r;j++){
					ans += wow(i,j);
				}
			}
			return ans;
		}
		long wow(int l,int r){
			long max = 0;
			for(int i=l;i<=r;i++)
				for(int j=i+1;j<=r;j++)
					max = Math.max (max, (long)(Math.ceil( (Math.abs(a[j] - a[i]) * 1.0 / (j - i) )) + 0.00001) );
			return max;
		}
	}*/
	
	public static class RmqSparseTable {

		  int[] logTable;
		  int[][] rmq;
		  int[] a;

		  public RmqSparseTable(int[] a) {
		    this.a = a;
		    int n = a.length;

		    logTable = new int[n + 1];
		    for (int i = 2; i <= n; i++)
		      logTable[i] = logTable[i >> 1] + 1;

		    rmq = new int[logTable[n] + 1][n];

		    for (int i = 0; i < n; ++i)
		      rmq[0][i] = i;

		    for (int k = 1; (1 << k) < n; ++k) {
		      for (int i = 0; i + (1 << k) <= n; i++) {
		        int x = rmq[k - 1][i];
		        int y = rmq[k - 1][i + (1 << k - 1)];
		        rmq[k][i] = a[x] >= a[y] ? x : y;
		      }
		    }
		  }

		  public int maxPos(int i, int j) {
		    int k = logTable[j - i];
		    int x = rmq[k][i];
		    int y = rmq[k][j - (1 << k) + 1];
		    return a[x] >= a[y] ? x : y;
		  }
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