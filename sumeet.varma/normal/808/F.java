import java.io.*;
import java.util.*;

public class ER21qF {

	static boolean p[];
	
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		init();
		
		int n = in.nextInt();
		int k = in.nextInt();

		Card c[] = new Card[n];
		for (int i = 0; i < n; i++) {
			c[i] = new Card(in.nextInt(), in.nextInt(), in.nextInt());
		}
		Arrays.sort(c);

		int start = 0, end = n;
		int best = -1;
		while (start < end) {
			int mid = (start + end) >> 1;
			if (P(c, mid + 1) >= k) {
				best = c[mid].l;
				end = mid;
			} else {
				start = mid + 1;
			}
		}

		w.println(best);
		w.close();
	}

	static int P(Card c[], int n) {
		int max1 = 0;
		ArrayList<Integer> tE = new ArrayList<Integer>();
		ArrayList<Integer> tO = new ArrayList<Integer>();
		ArrayList<Integer> pE = new ArrayList<Integer>();
		ArrayList<Integer> pO = new ArrayList<Integer>();
		
		ArrayList<Integer> t1E = new ArrayList<Integer>();
		ArrayList<Integer> t1O = new ArrayList<Integer>();
		ArrayList<Integer> p1E = new ArrayList<Integer>();
		ArrayList<Integer> p1O = new ArrayList<Integer>();
		
		for (int i = 0; i < n; i++) {
			if (c[i].c == 1) {
				max1 = Math.max(max1, c[i].p);
			} else if (c[i].c % 2 == 0) {
				if (!p[c[i].c + 1]) {
					t1E.add(c[i].c);
					p1E.add(c[i].p);
				}
				tE.add(c[i].c);
				pE.add(c[i].p);
			} else {
				if (!p[c[i].c + 1]) {
					t1O.add(c[i].c);
					p1O.add(c[i].p);
				}
				tO.add(c[i].c);
				pO.add(c[i].p);
			}
		}
		
		return Math.max(max1 + flow(t1E, t1O, p1E, p1O), flow(tE, tO, pE, pO));
	}
	
	
	static int flow(ArrayList<Integer> tE, ArrayList<Integer> tO, ArrayList<Integer> pE, ArrayList<Integer> pO) {
		
		int tot = 0;
		for (int x : pE)
			tot += x;
		for (int x : pO)
			tot += x;
		
		int n = 2 + tE.size() + tO.size();
		MF mf = new MF();
		mf.init(n);
		
		for (int i = 0; i < tE.size(); i++)
			mf.addEdge(0, i + 1, pE.get(i));
		
		for (int i = 0; i < tO.size(); i++)
			mf.addEdge(tE.size() + 1 + i, n - 1, pO.get(i));
		
		int inf = (int)1e9;
		for (int i = 0; i < tE.size(); i++) {
			for (int j = 0; j < tO.size(); j++) {
				if(p[tE.get(i) + tO.get(j)]) {
					mf.addEdge(i + 1, tE.size() + 1 + j, inf);
				}
			}
		}
		
		return (int)(tot - mf.maxFlow(0, n - 1));
	}

	static void init() {
		p = new boolean[300100];
		Arrays.fill(p, true);
		p[0] = p[1] = false;
		for (int i = 2; i < p.length; i++) {
			if (p[i]) {
				for (int j = i + i; j < p.length; j += i) {
					p[j] = false;
				}
			}
		}
	}

	static class Card implements Comparable<Card> {
		int p, c, l;

		Card(int p, int c, int l) {
			this.p = p;
			this.c = c;
			this.l = l;
		}

		public int compareTo(Card o) {
			return Integer.compare(l, o.l);
		}
	}

	static public class MF {

		  long[][] cap;

		  public void init(int nodes) {
		    cap = new long[nodes][nodes];
		  }

		  public void addEdge(int s, int t, int capacity) {
		    cap[s][t] = capacity;
		  }

		  public long maxFlow(int s, int t) {
		    int n = cap.length;

		    int[] h = new int[n];
		    h[s] = n - 1;

		    int[] maxh = new int[n];

		    long[][] f = new long[n][n];
		    long[] e = new long[n];

		    for (int i = 0; i < n; ++i) {
		      f[s][i] = cap[s][i];
		      f[i][s] = -f[s][i];
		      e[i] = cap[s][i];
		    }

		    for (int sz = 0;;) {
		      if (sz == 0) {
		        for (int i = 0; i < n; ++i)
		          if (i != s && i != t && e[i] > 0) {
		            if (sz != 0 && h[i] > h[maxh[0]])
		              sz = 0;
		            maxh[sz++] = i;
		          }
		      }
		      if (sz == 0)
		        break;
		      while (sz != 0) {
		        int i = maxh[sz - 1];
		        boolean pushed = false;
		        for (int j = 0; j < n && e[i] != 0; ++j) {
		          if (h[i] == h[j] + 1 && cap[i][j] - f[i][j] > 0) {
		            long df = Math.min(cap[i][j] - f[i][j], e[i]);
		            f[i][j] += df;
		            f[j][i] -= df;
		            e[i] -= df;
		            e[j] += df;
		            if (e[i] == 0)
		              --sz;
		            pushed = true;
		          }
		        }
		        if (!pushed) {
		          h[i] = Integer.MAX_VALUE;
		          for (int j = 0; j < n; ++j)
		            if (h[i] > h[j] + 1 && cap[i][j] - f[i][j] > 0)
		              h[i] = h[j] + 1;
		          if (h[i] > h[maxh[0]]) {
		            sz = 0;
		            break;
		          }
		        }
		      }
		    }

		    long flow = 0;
		    for (int i = 0; i < n; i++)
		      flow += f[s][i];

		    return flow;
		  }	  
	}
	
	static class InputReader {

		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, snumChars;

		public InputReader(InputStream st) {
			this.stream = st;
		}

		public int read() {
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
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			return a;
		}

		public String readString() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public String nextLine() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

	}

}