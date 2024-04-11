import java.io.*;
import java.util.*;

public class R347qA {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter w = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());
		
		String a[] = new String[st.countTokens() + 1];
		for(int i = 1; i < a.length; i++)
			a[i] = st.nextToken();
		a[0] = "+";
		
		int n = a.length;
		int N = Integer.parseInt(a[a.length - 1]);
		
		long max = 0;
		long min = 0;
		for(int i = 1; i < n - 2; i += 2){
			if(a[i - 1].equals("+")){
				max += N;
				min += 1;
			}
			else{
				max -= 1;
				min -= N;
			}
		}
		
		//System.out.println(max + " " + min);
		
		if(N <= max && N >= min){
			w.println("Possible");
			long ans[] = new long[n];
			for(int i = 1; i < n - 2; i += 2){
				if(a[i - 1].equals("+")){
					ans[i] = 1;
					long e = Math.min(N - 1, N - min);
					min += e;
					ans[i] += e;
				}
				else{
					ans[i] = N;
					long e = Math.min(N - 1, N - min);
					min += e;
					ans[i] -= e;
				}
			}
			for(int i = 1; i < n; i++){
				if(i < n - 2 && i % 2 == 1)
					w.print(ans[i] + " ");
				else
					w.print(a[i] + " ");
			}
			w.println();
		}
		else
			w.println("Impossible");
		
		
		w.close();
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar, snumChars;
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

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
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