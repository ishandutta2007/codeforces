import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		/*
		try {
			inputStream = new FileInputStream("a.in");
		//	outputStream = new FileOutputStream("a.out");
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}*/
		
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		solver.solve(in, out);
		out.close();
	}
}

class Solver {
	int mn = Integer.MAX_VALUE;
	int MAX = 105;
	public void solve(InputReader in, PrintWriter out) {
		int hy = in.nextInt();
		int ay = in.nextInt();
		int dy = in.nextInt();
		int hm = in.nextInt();
		int am = in.nextInt();
		int dm = in.nextInt();
		int hc = in.nextInt();
		int ac = in.nextInt();
		int dc = in.nextInt();
		for (int da = 0; da < 205; da++) {
			int an = ay + da;
			int damy = Math.max(an - dm, 0);
			if (damy == 0)
				continue;
			for (int dd = 0; dd < 105; dd++) {
				int dn = dy + dd;
				int damm = Math.max(am - dn, 0);
				int num = (hm + damy - 1) / damy;
				//hy + dh - damm * num > 0
				int dh = Math.max(damm * num - hy + 1, 0); 
				//for (int dh = 0; dh < ; dh++) {
					int hn = hy + dh;
					
					
					
					
					
					
					if (hn - damm * num > 0) {
						mn = Math.min(mn, dh * hc + da * ac + dd * dc);
					}
				//}
			}
		}
		out.println(mn);
		
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