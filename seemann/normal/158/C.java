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
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		Path path = new Path();
		for (int i = 0; i < n; i++) {
			String s = in.next();
			if (s.equals("pwd")) {
				out.println(path.toString());
			}
			if (s.equals("cd")) {
				String arg = in.next();
				path.cd(arg);
			}
		}
	}
}

class Path extends ArrayList<String> {
	public void cd(String dir) {
		StringTokenizer tokenizer = new StringTokenizer(dir, "/");
		if (dir.charAt(0) == '/') {
			this.clear();
		}
		while (tokenizer != null && tokenizer.hasMoreTokens()) {
			String s = tokenizer.nextToken();
			if (s.equals("..")) {
				this.remove(this.size() - 1);
			} else {
				this.add(s);
			}
		}
	}
	public String toString() {
		StringBuffer stringBuffer = new StringBuffer();
		stringBuffer.append('/');
		for (String str : this) {
			stringBuffer.append(str);
			stringBuffer.append('/');
		}
		return stringBuffer.toString();
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