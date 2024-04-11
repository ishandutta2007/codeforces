import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class LookseryQBLookseryParty {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		
		char s[][] = new char[n][n];
		for(int i=0;i<n;i++)
			s[i] = in.readString().toCharArray();
		
		int a[] = new int[n];
		for(int i=0;i<n;i++)
			a[i] = in.nextInt();
		
		boolean inSet[] = new boolean[n];
		Arrays.fill(inSet, true);
		
		ArrayList<Integer> ans = new ArrayList<Integer>();
		
		while(true){
			int min = n + 1,minIndex = -1;
			for(int j=0;j<n;j++){
				if(inSet[j]){
					if(a[j] < min){
						min = a[j];
						minIndex = j;
					}
				}
			}
			
			if(min > 0 || minIndex == -1)
				break;
			
			ans.add(minIndex + 1);
			inSet[minIndex] = false;
			
			for(int i=0;i<n;i++)
				if(s[minIndex][i] == '1')
					a[i]--;
				
		}
		
		w.println(ans.size());
		for(int x : ans)
			w.print(x + " ");
		w.println();
		
		w.close();
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