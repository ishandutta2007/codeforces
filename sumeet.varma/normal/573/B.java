import java.io.*;
import java.util.*;

public class R318qA {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		
		Pair p[] = new Pair[n];
		for(int i=0;i<n;i++)
			p[i] = new Pair(i + 1,in.nextInt());
		
		Arrays.sort(p);
		
		int ans[] = new int[n + 2];
		for(int i=1;i<=n;i++)
			ans[i] = Math.min(i, n + 1 - i);
		for(int i=0;i<n;i++)
			ans[p[i].idx] = Math.min(ans[p[i].idx],p[i].val);
		
		TreeSet<Integer> set = new TreeSet<Integer>();
		set.add(0);
		set.add(n + 1);
		
		for(int i=0;i<n;i++){
			int left = set.lower(p[i].idx);
			int right = set.higher(p[i].idx);
			ans[p[i].idx] = Math.min(ans[p[i].idx], ans[left] + p[i].idx - left);
			ans[p[i].idx] = Math.min(ans[p[i].idx], ans[right] + right - p[i].idx);
			set.add(p[i].idx);
		}
		
		//System.out.println(Arrays.toString(ans));
		
		int finalAns = ans[1];
		for(int i=1;i<=n;i++)
			finalAns = Math.max(finalAns, ans[i]);
		
		w.println(finalAns);
		w.close();
	}
	
	static class Pair implements Comparable<Pair>{
		int idx,val;
		Pair(int idx,int val){
			this.idx = idx;
			this.val = val;
		}
		public String toString(){
			return idx + " " + val;
		}
		public int compareTo(Pair o){
			if(val != o.val)
				return Integer.compare(val, o.val);
			return Integer.compare(idx, o.idx);
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