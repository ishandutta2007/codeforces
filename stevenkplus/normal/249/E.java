import java.util.*;
import java.io.*;
import java.math.*;

public class E {
	public static void main(String[] args) throws Exception {
		new E().go();
	}
	BufferedReader r;
	StringTokenizer st;
	String next() throws Exception {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(r.readLine());
		}
		return st.nextToken();
	}
	int nextInt() throws Exception {
		return Integer.parseInt(next());
	}
	
	void go() throws Exception {
		r = new BufferedReader(new InputStreamReader(System.in));

		int T = nextInt();
		for(int i = 0; i < T; ++i) {
			int a = nextInt(), b = nextInt(), c = nextInt(), d = nextInt();
			BigInteger b1 = comp(c, d).subtract(comp(a - 1, d).add(comp(c, b - 1)).subtract( comp(a - 1, b - 1)));
			String ans = b1.toString();
			if (ans.length() > 10) {
				ans = "..." + ans.substring(ans.length() - 10);
			}
			System.out.println(ans);
		}
	}
	
	BigInteger sumsq(int k) {
		BigInteger x = BigInteger.valueOf(k);
		BigInteger y = x.add(BigInteger.ONE);
		BigInteger z = y.add(x);
		return x.multiply(y).multiply(z).divide(BigInteger.valueOf(6));
	}
	
	BigInteger valAt(int a, int b) {
		int c = a > b ? a : b;
		BigInteger under = BigInteger.valueOf(c - 1);
		under = under.multiply(under);
		int over = (b == c) ? a : (2 * c - b);
		return under.add(BigInteger.valueOf(over));
	}
	
	BigInteger comp(int a, int b) {
		int c = a < b ? a : b;
		BigInteger bi = BigInteger.valueOf(c);
		bi = bi.multiply(bi);
		BigInteger x = bi.multiply(bi.add(BigInteger.ONE)).divide(BigInteger.valueOf(2));
		BigInteger other = BigInteger.ZERO; 
		if (a > b) {
			BigInteger height = BigInteger.valueOf(a - b);
			BigInteger width = BigInteger.valueOf(b);
			BigInteger j = sumsq(a).subtract(sumsq(b));
			BigInteger k = j.subtract(width.subtract(BigInteger.ONE).multiply(height));
			other = j.add(k).multiply(width).divide(BigInteger.valueOf(2));
		} else {
			BigInteger length = BigInteger.valueOf(b - a);
			BigInteger rows = BigInteger.valueOf(a);
			BigInteger j = sumsq(b - 1).subtract(sumsq(a - 1));
			j = j.add(length);
			BigInteger k = j.add(length.multiply(rows.subtract(BigInteger.ONE)));
			other = j.add(k).multiply(rows).divide(BigInteger.valueOf(2));
		}
		return x.add(other);
	}
}