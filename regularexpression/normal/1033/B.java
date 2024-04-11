import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
		stok = null;
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(System.out);
		int t = nextInt();
		for (int test = 0; test < t; test++) {
			BigInteger a = new BigInteger(nextToken()), b = new BigInteger(nextToken());
			BigInteger c = a.multiply(a).subtract(b.multiply(b));
			if (c.isProbablePrime(100000)) {
				pw.println("YES");
			} else {
				pw.println("NO");
			}
		}
		pw.flush();
		pw.close();
	}
	
	static StringTokenizer stok;
	static BufferedReader br;
	static PrintWriter pw;
	
	static String nextToken() throws IOException {
		while (stok == null || !stok.hasMoreTokens()) {
			stok = new StringTokenizer(br.readLine());
		}
		return stok.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
}