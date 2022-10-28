import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;


public class R176qCLuckyPermutation {

	static int ans[];
	
	public static void main(String args[]) throws Exception {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		ans = new int[n + 1];
		if(n % 4 == 0 || n % 4 == 1){
			solve(1,n);
			
			if(!get(ans))
				throw new Exception();
				
			for(int i=1;i<=n;i++)
				w.print(ans[i] + " ");
			w.println();
		}
		else
			w.println(-1);
		
		w.close();
	}
	
	static public void solve(int l,int r){
		if(l > r)
			return;
		if(l == r)
			ans[l] = l;
		else{
			ans[l] = l + 1;
			ans[l + 1] = r;
			ans[r] = r - 1;
			ans[r-1] = l;
			solve(l+2,r-2);
		}
	}
	
	static public void go(int i,int arr[],boolean state[],int n){
		if(i == n+1){
			if(get(arr))
				System.out.println(Arrays.toString(arr));
		}
		else{
			for(int j=1;j<=n;j++){
				if(!state[j]){
					state[j] = true;
					arr[i] = j;
					go(i+1,arr,state,n);
					state[j] = false;
				}
			}
		}
	}
	
	static public boolean get(int check[]){
		boolean hmm = true;
		for(int i=1;i<check.length;i++)
			if(check[check[i]] != check.length - i){
				hmm = false;
				//System.out.println(i);
			}
		return hmm;
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