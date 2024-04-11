import java.util.*;
import java.io.*;

public class R255FFQC {

	public static void main(String args[] ) throws Exception {
		
		InputReader in = new InputReader(System.in);
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int n = in.readInt();
	    int a[] = new int[n+2];
	    for(int i=1;i<=n;i++)
	    	a[i] = in.readInt();
	    
	    int ans = 0;
	    
	    a[0] = Integer.MAX_VALUE;
	    a[n+1] = -1*a[0];
	    
	    int l[] = new int[n+2];
	    for(int i=1;i<=n;i++){
	    	if(a[i] > a[i-1])
	    		l[i] = l[i-1] + 1;
	    	else
	    		l[i] = 1;
	    }
	    
	    int r[] = new int[n+2];
	    for(int i=n;i>=1;i--){
	    	if(a[i] < a[i+1])
	    		r[i] = r[i+1] + 1;
	    	else
	    		r[i] = 1;
	    }
	    
	    for(int i=1;i<=n;i++){
	    	if(a[i-1] + 1 < a[i+1])
	    		ans = Math.max(l[i-1] + r[i+1] + 1,ans);
	    	ans = Math.max(ans,l[i-1] + 1);
	    	ans = Math.max(ans,r[i+1] + 1);
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;
	public InputReader(InputStream stream) {
		this.stream = stream;
	}
	
	public int sread() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int readInt() {
		int c = sread();
		while (isSpaceChar(c))
			c = sread();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = sread();
		}

		int res = 0;

		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = sread();
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