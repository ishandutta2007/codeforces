import java.io.*;
import java.util.*;

public class R140NaughtyStonePiles {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		int a[] = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();

		Arrays.sort(a);
		
		long pre[] = new long[n];
		pre[0] = a[0];
		for(int i=1;i<n;i++)
			pre[i] = pre[i-1] + a[i];
		
		long ans1 = 0;
		for(int i=n-2,j=1;i>=0;i--,j++)
			ans1 += j * 1L * a[i];
		
		
		int Q = in.nextInt();
		
		while(Q-- > 0){
			int k = in.nextInt();
			if(n == 1)
				w.print(0 + " ");
			else if(k == 1)
				w.print(ans1 + " ");
			else{
				long ans = 0;
				long length = 1,count = 0;
				long l = n - 1,r = n - 1;
				boolean control = true;
				while(control){
					length *= k;
					count++;
					r = l - 1;
					l = l - length;
					if(l <= 0){
						control = false;
						l = 0;
					}
					ans += count*1L * (pre[(int)r] - (l == 0 ? 0 : pre[(int)l-1])); 
				}
				w.print(ans + " ");
			}
			
		}
		w.println();
		w.close();
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[1024];
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