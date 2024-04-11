import java.io.*;
import java.util.*;

public class R283qCDistrubtingParts {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		boolean yes = true;
		int n = in.nextInt();
		
		int ans[] = new int[n + 1];
		ArrayList<Pair> list = new ArrayList<Pair>();
		
		for(int i=1;i<=n;i++)
			list.add(new Pair(in.nextInt(),in.nextInt(),i,false));
		
		int m = in.nextInt();
		int k[] = new int[m + 1];
		for(int i=1;i<=m;i++){
			list.add(new Pair(in.nextInt(),in.nextInt(),i,true));
			k[i] = in.nextInt();
		}
		
		Collections.sort(list);
		
		TreeSet<Pair> set = new TreeSet<Pair>(new PairComp());
		
		for(Pair p : list){
			if(!p.type){
				p.b--;
				Pair first = set.higher(p);
				if(first == null){
					yes = false;
					break;
				}
				k[first.idx]--;
				if(k[first.idx] == 0)
					set.remove(first);
				ans[p.idx] = first.idx;
			}
			else
				set.add(p);
		}
		
		if(yes){
			w.println("YES");
			for(int i=1;i<=n;i++)
				w.print(ans[i] + " ");
			w.println();
		}
		else
			w.println("NO");
		w.close();
	}
	
	static class Pair implements Comparable<Pair>{
		int a,b,idx;
		boolean type;
		Pair(int a,int b,int idx,boolean type){
			this.a = a;
			this.b = b;
			this.idx = idx;
			this.type = type;
		}
		public int compareTo(Pair o){
			if(a != o.a)
				return Integer.compare(a, o.a);
			return Boolean.compare(o.type, type);
		}
		public String toString(){
			return type + " " + idx + " " + a + " " + b;
		}
	}
	
	static class PairComp implements Comparator<Pair>{
		public int compare(Pair a,Pair b){
			if(a.b != b.b)
				return Integer.compare(a.b, b.b);
			if(a.type != b.type){
				if(a.type == false)
					return 1;
				if(b.type == false)
					return -1;
			}
			return Integer.compare(a.idx, b.idx);
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