import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class R324qC {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		int diff = in.nextInt();
		int same = n - diff;
		
		char s1[] = in.readString().toCharArray();
		char s2[] = in.readString().toCharArray();
		char ans[] = new char[n];
		
		int x = 0;
		for(int i=0;i<n;i++)
			if(s1[i] == s2[i])
				x++;
		
		
		int maxSame = x + (n - x)/2;
		if(same > maxSame){
			System.out.println(-1);
			return;
		}
		
		for(int i=0;i<n;i++){
			if(s1[i] == s2[i]){
				if(same > 0){
					ans[i] = s1[i];
					same--;
				}
				else
					ans[i] = findDiff(s1[i],s2[i]);
			}
		}
		
		int a = same,b = same;
		for(int i=0;i<n;i++){
			if(s1[i] == s2[i])	continue;
			if(a == 0 && b == 0)
				ans[i] = findDiff(s1[i],s2[i]);
			else if(a >= b){
				a--;
				ans[i] = s1[i];
			}
			else{
				b--;
				ans[i] = s2[i];
			}
		}
		
		int aDiff = 0,bDiff = 0;
		for(int i=0;i<n;i++){
			if(ans[i] != s1[i])		aDiff++;
			if(ans[i] != s2[i])		bDiff++;
		}
		//System.out.println(aDiff + " " + bDiff);
		
		w.println(new String(ans));
		w.close();
	}
	
	static char findDiff(char x,char y){
		if(x != 'a' && y != 'a' )
			return 'a';
		if(x != 'b' && y != 'b')
			return 'b';
		return 'c';
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