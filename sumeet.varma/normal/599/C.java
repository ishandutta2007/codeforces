import java.io.*;
import java.util.*;

public class R332qC {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		
		TreeSet<Integer> set = new TreeSet<Integer>();
		
		int h[] = new int[n];
		for(int i=0;i<n;i++){
			h[i] = in.nextInt();
			set.add(h[i]);
		}
		
		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
		Iterator<Integer> it = set.iterator();
		int cnt = 0;
		while(it.hasNext()){
			cnt++;
			map.put(it.next(), cnt);
		}
		
		for(int i=0;i<n;i++)
			h[i] = map.get(h[i]);
		
		int count[] = new int[cnt + 1];
		int prefix[] = new int[cnt + 1];
		int last[] = new int[n];
	
		for(int i=0;i<n;i++)
			count[h[i]]++;
		
		for(int i=1;i<=cnt;i++){
			prefix[i] = prefix[i-1] + count[i];
			for(int j=prefix[i-1];j<prefix[i];j++)
				last[j] = i;
		}
		
		int ans = 0;
		
		int nowCount[] = new int[cnt + 1];
		int max = -1;
		
		for(int i=0;i<n;i++){
			
			nowCount[h[i]]++;
			max = Math.max(max, h[i]);
			
			if(max > last[i])
				continue;
			else if(max == last[i]){
				int left = i + 1 - nowCount[last[i]];
				if(left == prefix[last[i] - 1])
					ans++;
			}
			else
				throw new RuntimeException();
		}
		
		w.println(ans);
		w.close();
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