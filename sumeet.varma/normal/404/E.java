import java.io.*;
import java.util.*;

public class R237qEMaze1D {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		char s[] = in.readString().toCharArray();
		int n = s.length;
		
		int cntOrig[] = new int[2*n+5];
		int currOrig = 0;
		for(int i=0;i<n;i++){
			cntOrig[currOrig + n]++;
			if(s[i] == 'R')
				currOrig++;
			else
				currOrig--;
		}
		
		if(cntOrig[currOrig + n] == 0){
			System.out.println(1);
			return;
		}
		
		int start = 1,end = n + 5;
		int ans1 = 0;
		
		while(start < end){
			int mid = (start + end) >> 1;
			int cnt[] = new int[2*n + 5];
			int curr = 0;
			for(int i=0;i<n;i++){
				cnt[n + curr]++;
				if(s[i] == 'R'){
					curr++;
					if(curr == mid)
						curr--;
				}
				else{
					curr--;
					if(curr == mid)
						curr++;
				}
			}
			if(cnt[n + curr] == 0){
				ans1 = mid;
				start = mid + 1;
			}
			else
				end = mid;
		}
		
		int ans2 = 0;
		start = -n-5;
		end = 0;
		
		while(start < end){
			int mid = (start + end) >> 1;
			int cnt[] = new int[2*n + 5];
			int curr = 0;
			for(int i=0;i<n;i++){
				cnt[n + curr]++;
				if(s[i] == 'R'){
					curr++;
					if(curr == mid)
						curr--;
				}
				else{
					curr--;
					if(curr == mid)
						curr++;
				}
			}
		
			if(cnt[n + curr] == 0){
				ans2 = -mid;
				end = mid;	
			}
			else
				start = mid + 1;
		}
		
		
		w.println(ans1 + ans2);
		w.close();
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