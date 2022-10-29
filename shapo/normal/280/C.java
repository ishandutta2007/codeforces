import java.util.*;
import java.io.*;

public class Task {	
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		int n = in.nextInt();
		ArrayList < ArrayList < Integer > > edge = new ArrayList < ArrayList < Integer > >();
		ArrayList < Integer > empty = new ArrayList < Integer >();
		for (int i = 0; i < n; ++i)
			edge.add(new ArrayList < Integer >());
		boolean[] used = new boolean[n];
		int[] h = new int[n];
		for (int i = 1; i < n; ++i) {
			int a = in.nextInt(), b = in.nextInt();
			--a;
			--b;
			edge.get(a).add(b);
			edge.get(b).add(a);
		}
		int[] q = new int[n];
		int beg = 0, en = -1;
		q[++en] = 0;
		used[0] = true;
		double ans = 0.0;
		h[0] = 1;
		while (beg <= en) {
			int cur = q[beg++];
			ans += 1. / h[cur];
			for (int to : edge.get(cur))
				if (!used[to]) {
					q[++en] = to;
					used[to] = true;
					h[to] = h[cur] + 1;
				}
		}
		out.printf("%.15f\n", ans);
		out.close();
	}
}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;
	
	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}
	
	public String nextString() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}
	
	public int nextInt() {
		return Integer.parseInt(nextString());
	}
}