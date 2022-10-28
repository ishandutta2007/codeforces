import java.io.*;
import java.util.*;

public class R244TEPolicePatrol {
	
	public static void main(String args[] ) throws Exception {
	    InputReader3 in = new InputReader3(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.readInt();
		int m = in.readInt();
		
		long a[] = new long[n];
		for(int i=0;i<n;i++)
			a[i] = in.readInt();
		
		long ans = 0;
		for(int i=0,j=n-1;i<j;i+=m,j-=m)
			ans += a[j] - a[i];
		
		w.println(2*ans);
		w.close();
	}
}

class InputReader3 {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;
	public InputReader3(InputStream stream) {
		this.stream = stream;
	}
	
	public int read() {
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
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}

		int res = 0;

		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
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