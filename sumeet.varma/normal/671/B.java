import java.io.*;
import java.util.*;

public class R352qB {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int k = in.nextInt();
		int[] a = in.nextIntArray(n);
		
		int start = 1, end = (int)1e9 + 1000;
		int x = 1;
		
		while(start < end){
			int mid = (start + end) >> 1;
			long need = 0;
			long give = 0;
			for(int i = 0; i < n; i++){
				if(a[i] < mid){
					need += mid - a[i];
				}
				else{
					give += a[i] - mid;
				}
			}
			if(give >= need && need <= k){
				x = mid;
				start = mid + 1;
			}
			else
				end = mid;
		}
		
		start = 1; end = (int)1e9 + 1000;
		int y = 1;
		
		while(start < end){
			int mid = (start + end) >> 1;
			long need = 0;
			long give = 0;
			for(int i = 0; i < n; i++){
				if(a[i] < mid){
					need += mid - a[i];
				}
				else{
					give += a[i] - mid;
				}
			}
			if(need >= give && give <= k){
				y = mid;
				end = mid;
			}
			else
				start = mid + 1;
		}
		
		/*//System.out.println(x + " " + y);
		
		//w.println(y - x);
		if(brute(a,n,k) != y - x)
			System.out.println("fuck");
		//System.out.println(brute(a, n, k));
		}*/
		
		w.println(y - x);
		w.close();
	}
	
	static int brute(int[] a, int n, int k){
		TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
		for(int x : a){
			if(map.containsKey(x))
				map.put(x, map.get(x) + 1);
			else
				map.put(x, 1);
		}
		for(int i = 0; i < k; i++){
			int larg = map.lastKey();
			if(map.get(larg) == 1)
				map.remove(larg);
			else
				map.put(larg, map.get(larg) - 1);
			if(map.containsKey(larg - 1))
				map.put(larg - 1, map.get(larg - 1) + 1);
			else
				map.put(larg - 1, 1);
			larg = map.firstKey();
			if(map.get(larg) == 1)
				map.remove(larg);
			else
				map.put(larg, map.get(larg) - 1);
			if(map.containsKey(larg + 1))
				map.put(larg + 1, map.get(larg + 1) + 1);
			else
				map.put(larg + 1, 1);
		}
		return map.lastKey() - map.firstKey();
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