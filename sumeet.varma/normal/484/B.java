import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class R276qBMaximumValue {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		
		//long start = System.currentTimeMillis();
		
		int a[] = new int[n + 1];
		for(int i=1;i<=n;i++)
			a[i] = in.nextInt();
		
		Arrays.sort(a);
		PriorityQueue<Pair> pq = new PriorityQueue<Pair> (new PairComp());
		pq.add(new Pair(a[1]));
		int ans = 0;
		
		for(int i=2;i<=n;i++){
			if(a[i] == a[i-1])
				continue;
			else{
				while(true){
					Pair first = pq.peek();
					int diff = a[i] - first.val;
					if(diff >= first.orig){
						pq.remove();
						first.val = (a[i] / first.orig) * first.orig;
						pq.add(first);
					}
					else{
						ans = Math.max(ans, diff);
						break;
					}
				}
			}
			pq.add(new Pair(a[i]));
		}
		
		w.println(ans);
		//System.out.println(System.currentTimeMillis()- start);
		w.close();
	}
	
	static class Pair{
		int val,orig;
		Pair(int x){
			val = orig = x;
		}
	}
	
	static class PairComp implements Comparator<Pair>{
		public int compare(Pair a,Pair b){
			if(a.val != b.val)
				return Integer.compare(a.val, b.val);
			return Integer.compare(a.orig, b.orig);
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