import java.io.*;
import java.util.*;

public class R323qA {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		int a[] = new int[n*n];
		for(int i=0;i<a.length;i++)
			a[i] = -1 * in.nextInt();
		Arrays.sort(a);
		for(int i=0;i<a.length;i++)
			a[i] *= -1;
		
		int ans[] = new int[n];
		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
		
		int wow = 0;
		for(int i=0;i<a.length;i++){
			if(map.containsKey(a[i])){
				int freq = map.get(a[i]);
				if(freq == 1)
					map.remove(a[i]);
				else
					map.put(a[i], freq - 1);
			}
			else{
				ans[wow] = a[i];
				for(int j=0;j<wow;j++){
					int gcd = gcd(ans[j],a[i]);
					if(map.containsKey(gcd))
						map.put(gcd, map.get(gcd) + 2);
					else
						map.put(gcd, 2);
				}
				wow++;
			}
		}
		
		for(int i=0;i<n;i++)
			w.print(ans[i] + " ");
		w.println();
		
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

	public static int lcm(int a,int b){
		return a*b / gcd(a,b) ;
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