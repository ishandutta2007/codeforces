import java.io.*;
import java.util.*;

//java.is.awesome

public class R22qDSegments {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		Pair p[] = new Pair[n];
		for(int i = 0; i < n; i++)
			p[i] = new Pair(in.nextInt() , in.nextInt());
		
		Arrays.sort(p);
		
		int L = -100000, R = -100000;
		int ans = 0;
		ArrayList<Integer> wow = new ArrayList<Integer>();
		
		for(int i = 0 ; i < n; i++){
			int L2 = Math.max(L, p[i].x);
			int R2 = Math.min(R , p[i].y);
			if(L2 <= R2){
				L = L2;
				R = R2;
			}
			else{
				ans++;
				wow.add(R);
				L = p[i].x;
				R = p[i].y;
			}
		}
		
		wow.add(L);
		wow.remove(0);
		w.println(ans);
		for(int x : wow)
			w.print(x + " ");
		w.println();
		w.close();
	}
	
	static class Pair implements Comparable<Pair>{
		int x,y;
		Pair(int x,int y){	this.x = Math.min(x, y); this.y = Math.max(x, y); }
		public int compareTo(Pair o){
			if(x != o.x)
				return Integer.compare(x, o.x);
			return Integer.compare(y, o.y);
		}
		public String toString(){
			return x + " " + y;
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