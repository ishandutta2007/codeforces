import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		solver.solve(in, out);
		out.close();
	}
}


class Solver {
	char[] good;
	int[] num;
	ArrayList<String> ans;
	int[] d;
	boolean good(String s) {
		if (s.length() == 0)
			return false;
		if (s.length() > 1 && s.charAt(0) == '0')
			return false;
		int w = Integer.parseInt(s);
		if (w > 255)
			return false;
		return true;
	}
	void split(String s, int p, int cd) {
		if (cd == 3) {
			if (s.length() - p > 3)
				return;
			if (!good(s.substring(d[3])))
				return;
			StringBuffer res = new StringBuffer();
			for (int i = 0; i < 3; i++) {
				res.append(s.substring(d[i], d[i + 1]));
				res.append('.');
			}
			res.append(s.substring(d[3]));
			ans.add(res.toString());
			return;
		}
		for (int i = 1; i <= 3; i++) {
			if (p + i > s.length())
				break;
			if (good(s.substring(d[cd], d[cd] + i))) {
				d[cd + 1] = d[cd] + i;
				split(s, p + i, cd + 1);
			}
		}
		return;
	}
	void check(String s) {
//		System.err.println(s);
		for (int i = 0; i < num.length; i++) {
			if (num[i] == 0)
				return;
		}
		split(s, 0, 0);
	}
	void gen(int l, StringBuffer s) {
		if (l == 0) {
			String w = s.toString() + s.reverse().toString();
			check(w);
			w = s.toString() + s.reverse().substring(1);
			check(w);
			return;
		}
		for (int i = 0; i < good.length; ++i) {
			s.append(good[i]);
			num[i]++;
			gen(l - 1, s);
			s.deleteCharAt(s.length() - 1);
			num[i]--;
		}
	}
	public void solve(InputReader in, PrintWriter out) {
		int c = in.nextInt();
		good = new char[c];
		num = new int[c];
		for (int i = 0; i < c; i++) {
			good[i] = new Integer(in.nextInt()).toString().charAt(0);
		}
		ans = new ArrayList<String>();
		d = new int[4];
		for (int l = 2; l <= 6; ++l) {
			gen(l, new StringBuffer());
		}
		out.println(ans.size());
		for (String s : ans) {
			out.println(s);
		}
		
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}