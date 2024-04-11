import java.io.*;
import java.util.*;

public class R245QDWorkingOut {

	public static void main(String args[] ) throws Exception {
		
		InputReader in = new InputReader(System.in);
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int n = in.readInt();
	    int m = in.readInt();    
	    
	    int a[][] = new int[n+2][m+2];
	    for(int i=1;i<=n;i++)
	    	for(int j=1;j<=m;j++)
	    		a[i][j] = in.readInt();
	    
	    long topLeft[][] = new long[n+2][m+2];
	    long topRight[][] = new long[n+2][m+2];
	    long downLeft[][] = new long[n+2][m+2];
	    long downRight[][] = new long[n+2][m+2];
	    
	    for(int i=1;i<=n;i++)
	    	for(int j=1;j<=m;j++)
	    		topLeft[i][j] = Math.max(topLeft[i-1][j],topLeft[i][j-1]) + a[i][j];
	    
	    for(int i=n;i>=1;i--)
	    	for(int j=m;j>=1;j--)
	    		downRight[i][j] = Math.max(downRight[i+1][j], downRight[i][j+1]) + a[i][j];
	    
	    for(int i=1;i<=n;i++)
	    	for(int j=m;j>=1;j--)
	    		topRight[i][j] = Math.max(topRight[i-1][j],topRight[i][j+1]) + a[i][j];
	    
	    for(int i=n;i>=1;i--)
	    	for(int j=1;j<=m;j++)
	    		downLeft[i][j] = Math.max(downLeft[i+1][j], downLeft[i][j-1]) + a[i][j];
	    
	    long ans = 0;
	    for(int i=2;i<n;i++){
	    	for(int j=2;j<m;j++){
	    		ans = Math.max(ans, topLeft[i][j-1] + downRight[i][j+1] + topRight[i-1][j] + downLeft[i+1][j]);
	    		ans = Math.max(ans, topLeft[i-1][j] + downLeft[i][j-1] + downRight[i+1][j] + topRight[i][j+1]);
	    	}
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