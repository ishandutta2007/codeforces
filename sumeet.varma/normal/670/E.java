import java.io.*;
import java.util.*;

public class R350qE {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		int p = in.nextInt();
		
		char s[] = in.readString().toCharArray();
		int x[] = new int[n];
		
		int stack[] = new int[n + 5];
		int head = -1;
		
		for(int i = 0; i < n; i++){
			if(s[i] == '(')
				stack[++head] = i;
			else{
				x[stack[head]] = i;
				x[i] = stack[head];
				head--;
			}
		}

		char t[] = in.readString().toCharArray();
		p--;
		
		int next[] = new int[n + 5];
		int prev[] = new int[n + 5];
		boolean d[] = new boolean[n + 5];
		
		for(int i = 0; i < n; i++){
			next[i] = i + 1;
			prev[i] = i - 1;
		}
		prev[0] = n + 2;
		next[n - 1] = n + 3;
		
		for(int i = 0; i < m; i++){
			if(t[i] == 'R')
				p = next[p];
			else if(t[i] == 'L')
				p = prev[p];
			else{
				int l = x[p];
				int r = p;
				if(l > r){
					int temp = l;
					l = r;
					r = temp;
				}
				
				int before = prev[l];
				int after = next[r];
				int curr = l;
				
				while(curr <= r){
					d[curr] = true;
					curr = next[curr];
				}
				
				next[before] = after;
				prev[after] = before;
				
				if(after >= 0 && after < n)
					p = after;
				else
					p = before;
			}
		}
		
		for(int i = 0; i < n; i++)
			if(!d[i])
				w.print(s[i]);
		
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