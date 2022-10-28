import java.io.*;
import java.util.*;

public class R335qA {

	static int u[],v[];
	static int a[],b[];
	static int n,m;
	static Pair p[];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		m = in.nextInt();

		u = new int[m];
		v = new int[m];
		a = new int[m];
		b = new int[m];
		
		p = new Pair[n - 1];
		int cnt = 1;

		TreeSet<Pair> set = new TreeSet<Pair>();
		
		for (int i = 0; i < m; i++) {
			a[i] = in.nextInt();
			b[i] = in.nextInt();
			if (b[i] == 1) {
				u[i] = 0;
				v[i] = cnt;
				p[cnt - 1] = new Pair(cnt, a[i]);
				cnt++;
			} else
				set.add(new Pair(i, a[i]));
		}

		Arrays.sort(p);

		for (int j = 0; j < p.length; j++) {
			for (int k = j + 1; k < p.length; k++) {
				Pair higher = set.higher(new Pair(-1, p[k].val));
				if (higher == null)
					break;
				set.remove(higher);
				u[higher.idx] = p[j].idx;
				v[higher.idx] = p[k].idx;
			}
		}

		if (set.isEmpty()) {
			for (int j = 0; j < m; j++)
				w.println((u[j] + 1) + " " + (v[j] + 1));
		} else
			w.println(-1);

		w.close();
	}

	static class Pair implements Comparable<Pair> {
		int idx, val;

		Pair(int i, int v) {
			idx = i;
			val = v;
		}

		public int compareTo(Pair o) {
			if (val != o.val)
				return Integer.compare(val, o.val);
			return Integer.compare(idx, o.idx);
		}

		public String toString() {
			return idx + " " + val;
		}
	}

	static boolean mst(){
		int m = u.length;
		DisjointSet ds = new DisjointSet(n);
		Pair pro[] = new Pair[m];
		long wow = 0;
		for(int i = 0; i < m; i++){
			if(i < n -1 )
				wow += a[i];
			pro[i] = new Pair(i,a[i]);
		}
		
		Arrays.sort(pro);
		long now = 0;
		for(int i = 0; i < m;i++){
			int j = pro[i].idx;
			if(ds.find(u[j]) != ds.find(v[j])){
				ds.merge(u[j], v[j]);
				now += pro[i].val;
			}
		}
		return now == wow;
	}
	
	static public class DisjointSet {

		public int rank[],parent[],size[];
		public int n,comp;
		
		public DisjointSet(int n){
		    this.n = n;
			makeSet();
		}
		
		public void makeSet(){
			rank = new int[n];
			parent = new int[n];
			for(int i=0;i<n;i++)
				parent[i] = i;
			size = new int[n];
			Arrays.fill(size, 1);
			comp = n;
		}
		
		public int find(int x){
			if(parent[x] != x)
				parent[x] = find(parent[x]);
			return parent[x];
		}
		
		public void merge(int x,int y){
			int xRoot = find(x);
			int yRoot = find(y);
			
			if(xRoot == yRoot)
				return;
			
			size[xRoot] = size[yRoot] = size[xRoot] + size[yRoot];
			
			if(rank[xRoot] < rank[yRoot])
				parent[xRoot] = yRoot;
			else{
				parent[yRoot] = xRoot;
				if(rank[xRoot] == rank[yRoot]){
					parent[yRoot] = xRoot;
					rank[xRoot]++;
				}
			}
			comp--;
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