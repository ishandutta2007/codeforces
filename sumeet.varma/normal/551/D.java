import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;

public class R307qDBinaryOp {

	static long ans[],orig[][];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		//System.out.println(brute4() + " " + brute3());
		
		ans = new long[]{8,5,3,2};
		
		orig = new long[][]{
				{0,1,2,1},
				{1,0,0,0},
				{0,1,0,0},
				{0,0,1,0}
		};
		
		long n = in.readLong();
		long k = in.readLong();
		int l = in.nextInt();
		int m = in.nextInt();
		
		if(l < 63 && k >= (1L << l)){
			System.out.println("0");
			return;
		}
		
		long pow2n = pow(2,n,m);
		
		long ansZero = p(n,m);
		long ansOne = ((pow2n - ansZero) % m + m) % m;
		
		int ones = setBits(k,l);
		int zeroes = l - ones;
		
		long ans = 1 % m;
		for(int i=1;i<=zeroes;i++)
			ans = (ans * ansZero) % m;
		for(int i=1;i<=ones;i++)
			ans = (ans * ansOne) % m;
		
		w.println(ans);
		w.close();
	}
	
	public static long p(long n,int m){
		if(n <= 4)
			return ans[4-(int)n];
		long F[][] = new long[][]{
				{0,1,2,1},
				{1,0,0,0},
				{0,1,0,0},
				{0,0,1,0}
		};
		power(F,n-4,m);
		return (F[0][0] * ans[0] + F[0][1] * ans[1] + F[0][2] * ans[2] + F[0][3] * ans[3]) % m;
	}
	
	public static void power(long F[][],long b,int m){
		if(b <= 1)	return;
		power(F,b/2,m);
		multiply(F,F,m);
		if((b & 1) != 0)
			multiply(F,orig,m);
	}
	
	public static void multiply(long a[][],long b[][],int m){
		long c[][] = new long[4][4];
		
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				for(int k=0;k<4;k++)
					c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % m;
		
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				a[i][j] = c[i][j];
	}
	
	public static long pow(int a,long b,int mod){
		if(b == 0)	return 1 % mod;
		if(b == 1)	return a % mod;
		long t = pow(a,b/2,mod);
		t = (t * t) % mod;
		if((b & 1) != 0)
			t = (t * a) % mod;
		return t;
	}
	
	public static int setBits(long x,int l){
		int count = 0;
		for(int i=0;i<l;i++)
			if((x & 1L << i) != 0)	count++;
		return count;
	}
	
	public static int brute4(){
		int ans = 0,now = 0;
		for(int a=0;a<=1;a++)
			for(int b=0;b<=1;b++)
				for(int c=0;c<=1;c++)
					for(int d=0;d<=1;d++){
						now = (a & b) | (b & c) | (c & d);
						if(now == 0)	ans++;
					}
		return ans;
	}
	
	public static int brute3(){
		int ans = 0,now = 0;
		for(int a=0;a<=1;a++)
			for(int b=0;b<=1;b++)
				for(int c=0;c<=1;c++){
					now = (a & b) | (b & c);
					if(now == 0)	ans++;
				}
		return ans;
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
		
		 public long readLong() {
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