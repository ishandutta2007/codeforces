import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;


public class R307GukizHatesBoxes {

	static int n,m;
	static int p[];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		m = in.nextInt();
		
		p = new int[n + 1];
		for(int i=1;i<=n;i++)
			p[i] = in.nextInt();
		
		//System.out.println(go(4));
		w.println(binarySearch(1,(long)1e18));
		w.close();
	}
	
	static public long binarySearch(long start,long end){
		long ret = -1;
		long mid;
		while(start < end){
			mid = (start + end) >> 1;
			boolean res = go(mid);
			if(res)
				ret = end = mid;
			else
				start = mid + 1;
		}
		return ret;
	}
	
	static public boolean go(long mid){
		
		int a[] = new int[n+1];
		for(int i=1;i<=n;i++)
			a[i] = p[i];
			
		int curr = 1;
		for(int j=1;j<=m;j++){
			long now = curr;
			if(now > mid)	break;
			while(curr <= n){
				long t = Math.min(a[curr],mid - now);
				now += t;
				a[curr] -= t;
				if(a[curr] == 0)	curr++;
				now++;
				if(now >= mid)		break;
			}
		}
		
		for(int i=1;i<=n;i++)
			if(a[i] != 0)	return false;
		
		return true;
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[1024];
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