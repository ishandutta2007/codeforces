import java.io.*;
import java.util.*;

public class Yandex2011Qualification2 {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int N = n * (n - 1) / 2;
		
		int a[][] = new int[N][];
		for(int i = 0; i < N; i++)
			a[i] = in.nextIntArray(in.nextInt());

		if(N == 1){
			w.println(1 + " " + a[0][0]);
			w.print(a[0].length - 1);
			for(int i = 1; i < a[0].length; i++)
				w.print(" " + a[0][i]);
			w.println();
			w.close();
			return;
		}
		
		ArrayList<Integer> ans[] = new ArrayList[n];
		for(int i = 0; i < ans.length; i++)
			ans[i] = new ArrayList<Integer>();
		
		boolean x[] = new boolean[201];
		Arrays.fill(x, true);
		
		for(int i = 0; i < N; i++){
			boolean there = false;
			for(int j = 0; j < a[i].length; j++)
				there |= a[i][j] == a[0][0];
			if(there){
				boolean y[] = new boolean[201];
				for(int j = 0; j < a[i].length; j++)
					y[a[i][j]] = true;
				for(int j = 1; j <= 200; j++)
					x[j] &= y[j];
			}
		}
		
		for(int i = 1; i <= 200; i++)
			if(x[i])
				ans[0].add(i);
		int k = 1;
		
		for(int i = 0; i < N; i++){
			boolean there = false;
			for(int j = 0; j < a[i].length; j++)
				there |= a[i][j] == a[0][0];
			if(there){
				for(int X : a[i])
					if(!x[X])
						ans[k].add(X);
				k++;
			}
		}
		
		for(ArrayList<Integer> X : ans){
			w.print(X.size());
			for(int Y : X)
				w.print(" " + Y);
			w.println();
		}
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