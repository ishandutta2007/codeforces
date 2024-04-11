import java.io.*;
import java.util.*;

public class R338qE {

	public static void main(String args[]) throws Exception {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		long n = in.nextLong();
		
		if(n == 0){
			System.out.println(0 + " " + 0);
			return;
		}
		
		long ans = 0, start = 0, end = (int)1e9;
		
		while(start < end){
			long mid = (start + end) >> 1;
			if((mid) * (mid + 1) * 3 >= n){
				ans = mid;
				end = mid;
			}
			else
				start = mid + 1;
		}
		
		//System.out.println(ans);
		
		long x = 2*ans - 1;
		long y = 2;
		
		//System.out.println(3 * (ans) * (ans - 1));
		n = n - 3 * (ans) * (ans - 1);
		//System.out.println(n);
		
		//System.out.println(n);
		
		if(n > ans){
			x -= ans - 1;
			y += 2 * (ans - 1);
			n -= ans - 1;
		}
		
		else{
			x -= n - 1;
			y += 2 * (n - 1);
			System.out.println(x + " " + y);
			return;
		}
		
		if(n > ans + 1){
			x -= 2 * ans;
			n -= ans;
		}
		
		else{
			x -= 2 * (n - 1);
			System.out.println(x + " " + y);
			return;
		}
		
		if(n > ans + 1){
			x -= ans;
			y -= 2 * ans;
			n -= ans;
		}
		
		else{
			x -= (n - 1);
			y -= 2 * (n - 1);
			System.out.println(x + " " + y);
			return;
		}
		
		if(n > ans + 1){
			x += ans;
			y -= 2 * ans;
			n -= ans;
		}
		
		else{
			x += (n - 1);
			y -= 2 * (n - 1);
			System.out.println(x + " " + y);
			return;
		}
		
		//System.out.println(n + " -5 " + x + " 5- " + y);
		
		if(n > ans + 1){
			x += 2 * ans;
			n -= ans;
		}
		
		else{
			x += 2 * (n - 1);
			System.out.println(x + " " + y);
			return;
		}
		
		//System.out.println(n + " - " + x + " - " + y);
		if(n > ans + 1){
			x += ans;
			y += 2 * ans;
			n -= ans;
		}
		
		else{
			x += (n - 1);
			y += 2 * (n - 1);
			System.out.println(x + " " + y);
			return;
		}
		

		w.println(x + " " + y);
		w.close();
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar, snumChars;
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

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
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