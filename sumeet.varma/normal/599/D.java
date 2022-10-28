import java.io.*;
import java.util.*;

public class R332qD {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		/*
		for(int n=1;n<=300;n++)
			for(int m=1;m<=300;m++)
				if(get(n,m) != get2(n,m))
					System.out.println(n + " " + m);
		System.out.println("ac");
		*/
		
		long x = in.nextLong();
		
		ArrayList<Pair> ans = new ArrayList<Pair>();
		//System.out.println(get(1450000,1450000));
		
		for(long n=1;n<=1500000;n++){
			long m = get3(n,x);
			if(m != -1){
				ans.add(new Pair(n,m));
				if(n != m)
					ans.add(new Pair(m,n));
			}
		}
		
		Collections.sort(ans);
	
		int s = ans.size();
		w.println(s);
		for(int i=0;i<s;i++)
			w.println(ans.get(i).n + " " + ans.get(i).m);
		
		w.close();
	}
	
	public static long get(long n,long m){
		long ans = 0;
		for(long k=0;k<Math.min(n, m);k++)
			ans += (n - k) * (m - k);
		return ans;
	}
	
	public static long get2(long n,long m){
		if(n > m){
			long t = n;
			n = m;
			m = t;
		}
		
		//return n*m + n*m*n - (n+m)*n*(n+1)/2 + n*(n+1)*(2*n+1)/6;
		return m*(n*n + n)/2 - n*n*(n+1)/2 + n*(n+1)*(2*n+1)/6;
	}
	
	public static long get3(long n,long x){
		//x = m*(n*n + n)/2 - n*n*(n+1)/2 + n*(n+1)*(2*n+1)/6;
		long left = x + n*n*(n+1)/2 - n*(n+1)*(2*n+1)/6;
		left *= 2;
		left /= n*n + n;
		if(left >= n && get2(n,left) == x)
			return left;
		else
			return -1;
	}
	
	static class Pair implements Comparable<Pair>{
		long n,m;
		Pair(long n,long m){
			this.n = n;
			this.m = m;
		}
		public int compareTo(Pair o){
			if(n != o.n)
				return Long.compare(n,o.n);
			return Long.compare(m, o.m);
		}
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
		
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
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

	}

}