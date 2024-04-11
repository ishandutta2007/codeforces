import java.io.*;
import java.util.*;

public class R256qEDivisors {

	static InputReader in;
	static PrintWriter w;
	static int cnt = 0;
	static ArrayList<Long> divisors[];
	static HashMap<Long,Integer> hash;
	static long k;
	
	@SuppressWarnings("unchecked")
	public static void main(String args[]) {
		in = new InputReader(System.in);
		w = new PrintWriter(System.out);
		
		long x = in.nextLong();
		k = in.nextLong();
		
		divisors = new ArrayList[7001];
		hash = new HashMap<Long,Integer>();
		int cnt1 = 0;
		divisors[0] = new ArrayList<Long>();
		hash.put(x, cnt1);
		
		for(long i=1;i*i<=x;i++){
			if(x % i == 0){
				divisors[0].add(i);
				if(i*i != x)
					divisors[0].add(x/i);
			}
		}
		
		Collections.sort(divisors[0]);
		
		for(long y : divisors[0]){
			cnt1++;
			hash.put(y, cnt1);
			divisors[cnt1] = new ArrayList<Long>();

			for(int j=0;j<cnt1;j++)
				if(y % divisors[0].get(j) == 0)
					divisors[cnt1].add(divisors[0].get(j));
		}
		
		if(k >= 100000){
			if(x == 1)
				w.print(1);
			else
				for(int i=1;i<=100000;i++)
					w.print("1 ");
		}
		else		
			dfs(x,0);
		w.println();
		
		w.close();
	}
	
	static void dfs(long x,int level){
		if(cnt >= 100000 || level > k)
			return;
		if(x == 1 || level == k){
			w.print(x + " ");
			cnt++;
		}
		else{
			int map = hash.get(x);
			for(long y : divisors[map]){
				dfs(y,level+1);
				if(cnt >= 100000)
					return;
			}
		}
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			int res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}
		
		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			long res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}
		
		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}