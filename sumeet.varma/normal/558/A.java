import java.io.*;
import java.util.*;

public class R312qA {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		ArrayList<Pair> pos = new ArrayList<Pair>();
		ArrayList<Pair> neg = new ArrayList<Pair>();
		
		for(int i=0;i<n;i++){
			int x = in.nextInt();
			int a = in.nextInt();
			if(x < 0)
				neg.add(new Pair(x,a));
			else
				pos.add(new Pair(x,a));
		}
		
		Collections.sort(pos);
		Collections.sort(neg);
		Collections.reverse(neg);
		
		int nc = neg.size();
		int pc = pos.size();
		
		int ans = 0;
		
		if(pc >= nc){
			for(int i=0;i<Math.min(pc, nc + 1);i++)
				ans += pos.get(i).a;
			for(int i=0;i<nc;i++)
				ans += neg.get(i).a;
		}
		else{
			for(int i=0;i<Math.min(nc, pc + 1);i++)
				ans += neg.get(i).a;
			for(int i=0;i<pc;i++)
				ans += pos.get(i).a;
		}

		w.println(ans);
		w.close();
	}
	
	static class Pair implements Comparable<Pair>{
		int x,a;
		Pair(int x,int a){
			this.x = x;
			this.a = a;
		}
		public int compareTo(Pair o){
			return Integer.compare(x, o.x);
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