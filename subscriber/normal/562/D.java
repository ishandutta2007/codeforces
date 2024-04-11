import java.io.*;
import java.util.*;

public class D {

	int[] p;

	int get(int x) {
		return p[x] == x ? x : (p[x] = get(p[x]));
	}

	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x != y) {
			p[x] = y;
		}
	}

	class Segment implements Comparable<Segment> {
		int x, y;

		public Segment(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Segment o) {
			if (x == o.x) {
				return Integer.compare(y, o.y);
			}
			return Integer.compare(x, o.x);
		}

	}

	private void solve() {
		int n = in.nextInt();
		p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
		int q = in.nextInt();
		TreeSet<Segment> ts = new TreeSet<D.Segment>();
		for (int i = 0; i < n; i++) {
			ts.add(new Segment(i, i));
		}
		for (int i = 0; i < q; i++) {
			int type = in.nextInt();
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			if (type == 1) {
				unite(x, y);
			} else {
				if (type == 2) {
					ArrayList<Segment> all = new ArrayList<D.Segment>();
					Segment need = new Segment(y, Integer.MAX_VALUE);
					while (true) {
						Segment tmp = ts.lower(need);
						if (tmp == null) {
							break;
						}
						if (tmp.y < x) {
							break;
						}
						all.add(tmp);
						ts.remove(tmp);
					}
					int min = Integer.MAX_VALUE;
					int max = -1;
					for (Segment s : all) {
						min = Math.min(min, s.x);
						max = Math.max(max, s.y);
					}
					for (Segment s : all) {
						unite(x, s.x);
					}
					ts.add(new Segment(min, max));
				} else {
					out.println(get(x) == get(y) ? "YES" : "NO");
				}
			}
		}
	}

	class FastScanner {
		StringTokenizer st;
		BufferedReader br;

		FastScanner(String file) {
			try {
				br = new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return null;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					return null;
				}
			}
			return st.nextToken();
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return false;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					return false;
				}
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

	}

	FastScanner in;
	PrintWriter out;

	void runFile() {
		in = new FastScanner("a.in");
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	public static void main(String[] args) {
		new D().run();
	}
}