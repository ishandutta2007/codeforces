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
	private static final int L = 10;
	private int[] months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	public boolean isDate(String s) {
		if (s == null)
			return false;
		if (s.length() != L)
			return false;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '-') {
				if (i == 2 || i == 5)
					continue;
				else
					return false;
			}
		}
		StringTokenizer tok = new StringTokenizer(s, "-");
		int day, month, year;
		try{
			day = Integer.parseInt(tok.nextToken());
			month = Integer.parseInt(tok.nextToken());
			year = Integer.parseInt(tok.nextToken());
		} catch(Exception e) {
			return false;
		}
		if (month < 1 || month > 12)
			return false;
		month--;
		if (day < 1 || day > months[month])
			return false;
		if (year < 2013 || year > 2015)
			return false;
		return true;
	}
	public void solve(InputReader in, PrintWriter out) {
		String text;
		text = in.next();
		TreeMap<String, Integer> use = new TreeMap<String, Integer>();
		for (int i = 0; i <= text.length() - L; i++) {
			String sub = text.substring(i, i + L);
			if (isDate(sub)) {
				if (use.containsKey(sub)) {
					use.put(sub, use.get(sub) + 1);
				} else {
					use.put(sub, 1);
				}
			}
		}
		String ans = "";
		int mx = -1;
		for (Map.Entry<String, Integer> entry : use.entrySet()) {
			if (entry.getValue() > mx) {
				mx = entry.getValue();
				ans = entry.getKey();
			}
		}
		out.println(ans);
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