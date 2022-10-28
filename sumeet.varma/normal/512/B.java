import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class R290qbFoxAndJumping {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		
		int l[] = new int[n];
		for(int i=0;i<n;i++)
			l[i] = in.nextInt();
		
		int c[] = new int[n];
		for(int i=0;i<n;i++)
			c[i] = in.nextInt();
		
		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
		
		for(int i=0;i<n;i++){
			HashMap<Integer,Integer> next = new HashMap<Integer,Integer>();
			next.putAll(map);
			
			Iterator<Integer> it = map.keySet().iterator();
			while(it.hasNext()){
				int curr = it.next();
				int cost = map.get(curr);
				curr = gcd(curr,l[i]);
				cost += c[i];
				if(next.containsKey(curr))
					next.put(curr, Math.min(next.get(curr), cost));
				else
					next.put(curr, cost);
			}
			
			if(next.containsKey(l[i]))
				next.put(l[i], Math.min(next.get(l[i]),c[i]));
			else
				next.put(l[i], c[i]);
			
			map.clear();
			map.putAll(next);
		}
		
		if(map.containsKey(1))
			w.println(map.get(1));
		else
			w.println(-1);
		
		w.close();
	}
	
	public static int gcd(int a,int b){
		int temp=0;
		while(b!=0){
			temp = b;
			b = a%b;
			a = temp;
		}
		return a;
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