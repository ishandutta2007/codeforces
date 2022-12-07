import java.io.*;
import java.util.*;

public class A {
	FastScanner in;
	PrintWriter out;

	int readTime() {
		// hh:mm:ss
		String s = in.next();
		int hh = (s.charAt(0) - '0') * 10 + s.charAt(1) - '0';
		int mm = (s.charAt(3) - '0') * 10 + s.charAt(4) - '0';
		int ss = (s.charAt(6) - '0') * 10 + s.charAt(7) - '0';
		return hh * 60 * 60 + mm * 60 + ss;
	}

	class Event implements Comparable<Event> {
		int id;
		int time;
		int type;

		public Event(int id, int time, int type) {
			super();
			this.id = id;
			this.time = time;
			this.type = type;
		}

		@Override
		public int compareTo(Event o) {
			if (time != o.time) {
				return Integer.compare(time, o.time);
			}
			if (type == o.type) {
				return Integer.compare(id, o.id);
			}
			return Integer.compare(type, o.type);
		}

		@Override
		public String toString() {
			return "Event [id=" + id + ", time=" + time + ", type=" + type
					+ "]";
		}

	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int t = in.nextInt();
		TreeSet<Event> ts = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			ts.add(new Event(i, readTime(), 1));
		}
		boolean noSolution = true;
		int cntOnline = 0;
		TreeSet<Event> curOnlineTS = new TreeSet<>();
		int[] res = new int[n];
		int userCount = 0;
		while (ts.size() > 0) {
			Event e = ts.pollFirst();
			if (e.type == 1) {
				if (cntOnline < m) {
					cntOnline++;
					Event ee = new Event(e.id, e.time + t, -1);
					ts.add(ee);
					curOnlineTS.add(ee);
					res[e.id] = userCount++;
					if (cntOnline == m) {
						noSolution = false;
					}
				} else {
					Event lastOnline = curOnlineTS.pollLast();
					ts.remove(lastOnline);
					int nowUser = res[lastOnline.id];
					res[e.id] = nowUser;
					Event ee = new Event(e.id, e.time + t, -1);
					ts.add(ee);
					curOnlineTS.add(ee);
				}
			} else {
				cntOnline--;
				curOnlineTS.remove(e);
			}
		}
		if (noSolution) {
			out.println("No solution");
			return;
		}
		out.println(userCount);
		for (int i = 0; i < n; i++) {
			out.println(1 + res[i]);
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("A.in"));
			out = new PrintWriter(new File("A.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
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

	public static void main(String[] args) {
		new A().runIO();
	}
}