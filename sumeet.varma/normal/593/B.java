import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class R329qBAntonAndLines {
	
	static int n;
	static int x1,x2;
	static int k[],b[];
	static Pair p[],q[];

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
		x1 = in.nextInt();
		x2 = in.nextInt();
		
		k = new int[n];
		b = new int[n];
		
		for(int i=0;i<n;i++){
			k[i] = in.nextInt();
			b[i] = in.nextInt();
		}
		
		p = new Pair[n];
		q = new Pair[n];
		
		for(int i=0;i<n;i++){
			p[i] = new Pair(i,b[i],k[i],x1);
			q[i] = new Pair(i,b[i],k[i],x2);
		}
		
		Arrays.sort(p);
		Arrays.sort(q);
		
		//System.out.println(Arrays.deepToString(p));
		//System.out.println(Arrays.deepToString(q));
		
		boolean yes = true;
		for(int i=0;i<n;i++)
			yes = yes & (p[i].idx == q[i].idx);
			
		w.println(!yes ? "Yes" : "No");
		w.close();
	}
	
	static class Pair implements Comparable<Pair>{
		int idx,b,k,x;
		Pair(int i,int B,int K,int X){
			idx = i;
			b = B;
			k = K;
			x = X;
		}
		public int compareTo(Pair o){
			long y1 = k * 1L * x + b;
			long y2 = o.k * 1L * o.x + o.b;
			if(y1 != y2)
				return Long.compare(y1, y2);
			int other = x1 + x2 - x;
			y1 = k * 1L * other + b;
			y2 = o.k * 1L * other + o.b;
			return Long.compare(y1, y2);
		}
		public String toString(){
			long y1 = k * 1L * x + b;
			return idx + " " + b + " " + k + " " + x + " " + y1;
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