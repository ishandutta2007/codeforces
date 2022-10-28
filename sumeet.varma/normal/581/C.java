import java.io.*;
import java.util.*;


public class R322qC {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		int k = in.nextInt();
		
		int a[] = new int[n];
		for(int i=0;i<n;i++)
			a[i] = in.nextInt();
		
		Pair p[] = new Pair[n];
		for(int i=0;i<n;i++)
			p[i] = new Pair(i,a[i]);
		Arrays.sort(p);
		
		for(int i=0;i<n;i++){
			if(k >= p[i].diff && p[i].val != 100){
				k -= p[i].diff;
				a[p[i].idx] += p[i].diff;
			}
		}
		
		for(int i=0;i<n;i++){
			while(k >= 10 && a[i] < 100){
				a[i] += 10;
				k -= 10;
			}
		}
		
		int ans = 0;
		for(int x : a)
			ans += x/10;
		
		w.println(ans);
		w.close();
	}

	static class Pair implements Comparable<Pair>{
		int idx,val;
		int diff;
		Pair(int i,int v){
			idx = i;
			val = v;
			int ceil = val/10 + 1;
			ceil *= 10;
			diff = ceil - val;
		}
		public int compareTo(Pair o){
			if(diff != o.diff)
				return Integer.compare(diff, o.diff);
			return Integer.compare(idx, o.idx);
		}
		public String toString(){
			return idx + " " + val;
		}
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