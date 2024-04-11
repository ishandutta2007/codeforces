import java.io.*;
import java.util.*;

public class ZeptoLabqETransmittingLevels {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		int q = in.nextInt();
		
		int a[] = new int[n];
		for(int i=0;i<n;i++)
			a[i] = in.nextInt();
		
		while(q-- > 0){
			long b = in.nextLong();
			
			int lastCut[] = new int[n + 1];
			lastCut[n] = n;
			
			int ans[] = new int[n + 1];
			ans[n] = 0;
			
			long sum = 0;
			int r = n-1;
			for(int i=n-1;i>=0;i--){
				sum += a[i];
				while(sum > b){
					sum -= a[r];
					r--;
				}
				ans[i] = 1 + ans[r + 1];
				lastCut[i] = ans[i] == 1 ? i : lastCut[r + 1];
			}
			
			int finalAns = ans[0];
			
			if(finalAns == 1)
				w.println(finalAns);
			
			else{
				
				sum = 0;
				r = n;
				long pre = 0;
				
				for(int i=0;i<n-1;i++){
					sum += a[i];
					pre += a[i];
					if(pre > b)
						break;
					
					while(true){
						if(sum + a[r-1] > b)
							break;
						r--;
						sum += a[r];
					}
					
					while(sum > b){
						sum -= a[r];
						r++;
					}
					
					int nowAns = 1 + ans[i + 1];
					if(lastCut[i+1] >= r)
						nowAns--;
					
					finalAns = Math.min(finalAns, nowAns);
				}
				
				w.println(finalAns);
			}
		}
		
		
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