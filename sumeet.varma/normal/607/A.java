import java.io.*;
import java.util.*;


public class R336qA {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		Pair p[] = new Pair[n];
		for(int i = 0;i < n; i++){
			int a = in.nextInt();
			int b = in.nextInt();
			p[i] = new Pair(b,a);
		}
		
		Arrays.sort(p);
		
		//left
		int suf[] = new int[n];
		suf[0] = 1;
		for(int i = 1;i < n; i++){
			int start = 0,end = i;
			int ans = -1;
			//last that is saved
			while(start < end){
				int mid = (start + end) >> 1;
				if(p[i].val - p[mid].val > p[i].idx){
					ans = mid;
					start  = mid + 1;
				}
				else
					end = mid;
			}
			//System.out.println(i + " " + ans);
			if(ans != -1)
				suf[i] = 1 + suf[ans];
			else
				suf[i] = 1;
		}
		
		int ans = Integer.MAX_VALUE;	
		for(int i = 0; i < n; i++)
			ans = Math.min(ans , n - suf[i]);
	
		w.println(ans);
		w.close();
	}
	
	static class Pair implements Comparable<Pair>{
		int idx,val;
		Pair(int i,int v){
			idx = i;
			val = v;
		}
		public int compareTo(Pair o){
			if(val != o.val)
				return Integer.compare(val, o.val);
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