import java.util.*;
import java.io.*;
public class C {
	// @formatter:off
	static long mod=(int)(1e9)+7;
	static FastScanner in;
	static class FastScanner{
		private InputStream stream;
		private byte[] buf = new byte[1 << 16];
		private int curChar;
		private int numChars;

		// standard input
		public FastScanner() { this(System.in); }

		public FastScanner(InputStream i) {
			stream = i;
		}
		
		// file input
		public FastScanner(String i) throws IOException {
			stream = new FileInputStream(i);
		}

		// throws InputMismatchException() if previously detected end of file
		private int nextByte() {
			if (numChars == -1) {
				throw new InputMismatchException();
			}
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars == -1) {
					return -1;  // end of file
				}
			}
			return buf[curChar++];
		}

		// to read in entire lines, replace c <= ' '
		// with a function that checks whether c is a line break
		public String next() {
			int c;
			do {
				c = nextByte();
			} while (c <= ' ');

			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = nextByte();
			} while (c > ' ');
			return res.toString();
		}

		public int nextInt() {  // nextLong() would be implemented similarly
			int c;
			do {
				c = nextByte();
			} while (c <= ' ');
			
			int sgn = 1;
			if (c == '-') { 
				sgn = -1;
				c = nextByte(); 
			}

			int res = 0;
			do {
				if (c < '0' || c > '9') {
					throw new InputMismatchException();
				}
				res = 10 * res + c - '0';
				c = nextByte();
			} while (c > ' ');
			return res * sgn;
		}
		
		public long nextLong() {  
			int c;
			do {
				c = nextByte();
			} while (c <= ' ');
			
			int sgn = 1;
			if (c == '-') { 
				sgn = -1;
				c = nextByte(); 
			}

			long res = 0;
			do {
				if (c < '0' || c > '9') {
					throw new InputMismatchException();
				}
				res = 10 * res + c - '0';
				c = nextByte();
			} while (c > ' ');
			return res * sgn;
		}
		public double nextDouble() { return Double.parseDouble(next()); }
	}
	static void setIO() {try {in=new FastScanner("test.in");}catch(Exception e) {in=new FastScanner(System.in);}}// @formatter:on

	public static void main(String[] args) throws Exception{
		setIO();
		PrintWriter out=new PrintWriter(System.out);
		int t=in.nextInt();
		StringBuilder sb=new StringBuilder();
		for(int k=0;k<t;k++) out.println(solve()?"Yes":"No");
		out.close();
	}
	static boolean solve()throws Exception{
		int n=in.nextInt(),c=in.nextInt();
		int[]a1=new int[n];for(int i=0;i<n;i++)a1[i]=in.nextInt();
		int[]p=new int[c+1];
		for(int i=0;i<n;i++)p[a1[i]]++;
		for(int i=1;i<p.length;i++) p[i]+=p[i-1];
		boolean[]values=new boolean[c+1];
		for(int val:a1)values[val]=true;
		int mx=c;
		// first x that fails
		for(int x=1;x<=c;x++) {
			if(values[x]) continue;
			int upper=mx/x;
			for(int a=1;a<=upper;a++) {
				if(!values[a]) continue;
				int low=a*x;
				if(low>c) break;
				int high=low+a-1; // inclusive
				int count=p[Math.min(high, c)]-p[low-1]; // might have index out of bounds for low=0
				if(count>0) {
					return false;
				}
			}
		}
		return true;
	}
}