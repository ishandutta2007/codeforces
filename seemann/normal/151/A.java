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
		int n, k, l, c, d, p, nl, np;
		n = in.nextInt();
		k = in.nextInt();
		l = in.nextInt();
		c = in.nextInt();
		d = in.nextInt();
		p = in.nextInt();
		nl = in.nextInt();
		np = in.nextInt();
		int ans = Math.min(Math.min(k*l/nl/n, c*d/n), p/np/n);
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