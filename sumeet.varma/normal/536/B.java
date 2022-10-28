import java.io.*;
import java.util.*;

public class R299TaskB {

	public static void main(String args[] ) throws Exception {
		   
		InputReader in = new InputReader(System.in);
	    PrintWriter w = new PrintWriter(System.out);
	    
	    int n = in.nextInt();
	    int m = in.nextInt();      
		
		int z[] = zFunction(in.readString().toCharArray());
		
		int y[] = new int[m];
		for(int i=0;i<m;i++)
			y[i] = in.nextInt();
		
	    boolean broken = false;
	    int len = z.length;
	    
	    if(m != 0)
	    	n -= len;
	    
	    for(int i=1;i<m && !broken;i++){
	    	if(y[i] - y[i-1] >= len)
	    		n -= len;
	    	else{
	    		int x = y[i] - y[i-1];
	    		if(z[x] >= len - x)
	    			n -= x;
	    		else
	    			broken = true;
	    	}
	    }
	    
	    if(broken)
	    	w.println(0);
	    else
	    	w.println(pow(26,n,(int)1e9+7));
	    
	    w.close(); 
	}
	
	public static long pow(int a,int b,int mod){
		if(b == 0)	return 1;
		if(b == 1)	return a;
		long t = pow(a,b/2,mod);
		t = (t * t) % mod;
		if((b & 1) == 1)
			t = (t * a) % mod;
		return t;
	}
	
	public static int[] zFunction(char pat[]){
		int n = pat.length;
		int z[] = new int[n];
		
		int l = 0,r = 0;
		for(int i=1;i<n;i++){
			if(i > r){
				l = r = i;
				while(r < n && pat[r-l] == pat[r]) r++;
				z[i] = r - l;
				r--;
			}
			else{
				int k = i - l;
				if(z[k] < r - i + 1)	z[i] = z[k];
				else{
					l = i;
					while(r < n && pat[r-l] == pat[r]) r++;
					z[i] = r - l;
					r--;
				}
			}
		}
		
		z[0] = n;
		return z;
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