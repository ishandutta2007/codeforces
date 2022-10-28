import java.io.*;
import java.util.*;

public class R323qB {

	static int MAX = (int)2e5 + 500, MOD = (int)1e9 + 7;

	static int BIT[] = new int[505] ;
	static int A[] = new int[MAX];
	static int freq[] = new int[MAX];
	static int DP[] = new int[MAX];
	static int other[] = new int[30 * MAX];
	static int N , T;

	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		N = in.nextInt();
		T = in.nextInt();
		
		for(int i=1;i<=N;i++)
			A[i] = in.nextInt();
	
		for(int i=1;i<=N;i++)
			freq[A[i]]++;
		
		 if( T <= ( N << 1) ){
		    	
		    	int ans = 0;

		    	while(T-- > 0){
		    		for(int i = 1 ; i <= N ; ++i){
		              int x = query(A[i]) + 1;
		              ans = Math.max(ans , x);
		              update(A[i] , x);
		            }
		    	}

		    	w.println(ans);
		 }
		 
		 else{
				for( int i = 0 ; i < N ; i++ )
		    		for( int j = 1 ; j <= N ; j++)
		    			other[i * N + j] = A[j];
		    	
		    	T -= ( N << 1 );
		    	
		    	for( int i = 1 ; i <= N * N ; i++){
		    		int val = 0;
		    		for( int j = 1 ; j <= other[i] ; j++)
		    			val = Math.max( val , DP[j] );
		    		DP[other[i]] = val + 1;
		    	}
		    	
		    	int magic = 0;
		    	
		    	for( int i = 0 ; i <= 400 ; i++){
		    		magic = Math.max( magic , DP[i]);
		    		DP[i] = magic + T * freq[i];
		    	}

		    	for( int i = 1 ; i <= N * N ; i++){
		    		int v = 0;
		    		for( int j = 1 ; j <= other[i] ; j++)
		    			v = Math.max(v,DP[j]);
		    		DP[other[i]] = v + 1;
		    	}

		    	int finalAns = 0;
		    	for( int i = 0 ; i <= 400; i++) 
		    		finalAns = Math.max(finalAns,DP[i]);
		        
		        w.println(finalAns); 
		 }
		
		w.close();
	}
	
	static void update(int idx , int val){
	    while(idx < 505){
	        BIT[idx] = Math.max(BIT[idx] , val);
	        idx += idx & -idx;
	    }
	}
	
	static int query(int idx){
	    int res = 0;
	    while(idx >= 1){
	        res = Math.max(res , BIT[idx]);
	        idx -= idx & -idx;
	    }
	    return res;
	}
	
	static int LIS(int a[]){
		int n = a.length;
		int dp[][] = new int[n + 1][301];
		Arrays.fill(dp[n], 0);
		for(int i=n-1;i>=0;i--){
			for(int x=0;x<=300;x++){
				dp[i][x] = dp[i+1][x];
				if(a[i] >= x)
					dp[i][x] = Math.max(dp[i][x], 1 + dp[i+1][a[i]]);
			}
		}
		return dp[0][0];
	}
	
	public static int ceilIndex(int tailTable[], int l, int r, int key) {
	    while( r - l > 1 ) {
	        int m = l + (r - l)/2;
	        if(tailTable[m] >= key)
	        	r = m;
	        else
	        	l = m;
	    }
	    return r;
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