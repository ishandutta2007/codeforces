import java.io.*;
import java.util.*;

public class R346qB {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		Pair p[] = new Pair[n];
		for(int i = 0; i < n; i++)
			p[i] = new Pair(in.readString() , in.nextInt()  , in.nextInt());
		
		Arrays.sort(p);
		
		ArrayList<Pair> ans[] = new ArrayList[m + 1];
		for(int i = 1; i <= m; i++)
			ans[i] = new ArrayList<Pair>();
		
		boolean s[] = new boolean[m + 1];
		Arrays.fill(s, true);
		
		for(int i = 0; i < n; i++){
			if(ans[p[i].reg].size() < 2)
				ans[p[i].reg].add(p[i]);
			else{
				if(p[i].pt == ans[p[i].reg].get(1).pt)
					s[p[i].reg] = false;
			}
		}
		
		for(int i = 1; i <= m; i++){
			if(s[i])
				w.println(ans[i].get(0).name + " " + ans[i].get(1).name);
			else
				w.println("?");
		}
		
		w.close();
	}
	
	static class Pair implements Comparable<Pair>{
		String name;
		int reg, pt;
		Pair(String name, int reg, int pt){
			this.name = name;
			this.reg = reg;
			this.pt = pt;
		}
		public int compareTo(Pair o){
			return Integer.compare(o.pt, pt);
		}
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