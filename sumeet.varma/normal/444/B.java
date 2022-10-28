import java.io.*;
import java.util.*;

public class R254qBDZYLovesFFT {

	static long x;
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int i;
		int n = in.nextInt();
		int d = in.nextInt();
		x = in.nextLong();
		
		int a[] = new int[n];
		for(i = 0; i < n; i = i + 1)
	        a[i] = i + 1;
	    
	    for(i = 0; i < n; i = i + 1){
	    	int t = a[i];
	    	int j = (int)(getNextX() % (i + 1));
	    	a[i] = a[j];
	    	a[j] = t;
	    }
	    
	    int b[] = new int[n + 1];
	    for(i = 0; i < n; i = i + 1){
	        if (i < d)
	            b[i] = 1;
	        else
	            b[i] = 0;
	    }
	    
	    for(i = 0; i < n; i = i + 1){
	    	int t = b[i];
	    	int j = (int)(getNextX() % (i + 1));
	    	b[i] = b[j];
	    	b[j] = t;
	    }
	    
	    int pos[] = new int[d];
	    int lol = 0;
	    for(i=0;i<n;i++)
	    	if(b[i] == 1)
	    		pos[lol++] = i;
	    
	    int rev[] = new int[n + 1];
	    for(i=0;i<n;i++)
	    	rev[a[i]] = i;
	    
	    
	    final int s = Math.min(234, n);
	    final int limit = n - s;
	   
	    for(i=0;i<n;i++){
	    	int ans = 0;
	    	for(int j=n;j>limit;j--){
	    		if(rev[j] <= i && b[i - rev[j]] == 1){
	    			ans = j;
	    			break;
	    		}
	    	}
	    	if(ans == 0)
	    		for(int j=0;j<d && pos[j]<=i;j++)
	    			ans = Math.max(ans, a[i - pos[j]]);
	    	w.println(ans);
	    }
	    
		w.close();
	}
	
	static long getNextX() {
	    x = (x * 37 + 10007) % 1000000007;
	    return x;
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