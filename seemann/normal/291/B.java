import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws Exception{
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
	public void solve(InputReader in, PrintWriter out) throws Exception{
		String s = in.nextLine();
		StringBuffer cur = new StringBuffer();
		boolean open = false;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '"') {
				if (open) {
					open = false;
					out.println("<" + cur.toString() + ">");
					cur = new StringBuffer();
				} else {
					open = true;
				}
				continue;
			}
			
			if (open) {
				cur.append(s.charAt(i));
				continue;
			}
				
			if (s.charAt(i) == ' ') {
				if (cur.length() > 0) {
					out.println("<" + cur.toString() + ">");
					cur = new StringBuffer();
				}
				continue;
			}
			cur.append(s.charAt(i));
		}
		if (cur.length() > 0)
			out.println("<" + cur.toString() + ">");
		
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
	public String nextLine() throws Exception{
		return reader.readLine();
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