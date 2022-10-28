import java.io.*;
import java.util.*;

public class R344qC {
	
	static TreeMap<Integer, Integer> map;

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		int a[] = in.nextIntArray(n);
		
		T p[] = new T[m];
		for(int i = 0; i < m; i++)
			p[i] = new T(i , in.nextInt() , in.nextInt() - 1);
		
		Arrays.sort(p);
		
		int state = 0;
		int maxTime = -1;
		int pos = n - 1;
		
		int ans[] = new int[n];
		
		map = new TreeMap<Integer, Integer>();
		for(int x : a)
			add(x);
		
		for(int i = 0; i < m; i++){
			if(p[i].time > maxTime && p[i].y <= pos){
				if(state == 0){
					for(int j = pos; j > p[i].y; j--){
						ans[j] = a[j];
						rem(a[j]);
					}
				}
				else if(state == 1){
					for(int j = pos; j > p[i].y; j--){
						ans[j] = map.lastKey();
						rem(map.lastKey());
					}
				}
				else{
					for(int j = pos; j > p[i].y; j--){
						ans[j] = map.firstKey();
						rem(map.firstKey());
					}
				}
				state = p[i].t;
				pos = p[i].y;
				maxTime = p[i].time;
				//System.out.println(state + " " + pos + " " + maxTime + " " + Arrays.toString(ans));
			}
		}
		
		if(state == 0){
			for(int i = pos; i >= 0; i--){
				ans[i] = a[i];
				rem(a[i]);
			}
		}
		
		else if(state == 1){
			for(int j = pos; j >= 0; j--){
				ans[j] = map.lastKey();
				rem(map.lastKey());
			}
		}
		
		else{
			for(int j = pos; j >= 0; j--){
				ans[j] = map.firstKey();
				rem(map.firstKey());
			}
		}
		
		for(int x : ans)
			w.print(x + " ");
		w.println();
		
		w.close();
	}
	
	static void add(int x){
		if(map.containsKey(x))
			map.put(x, map.get(x) + 1);
		else
			map.put(x, 1);
	}
	
	static void rem(int x){
		if(map.get(x) == 1)
			map.remove(x);
		else
			map.put(x, map.get(x) - 1);
	}

	static class T implements Comparable<T>{
		int y,t,time;
		T(int time, int t, int y){
			this.y = y;
			this.t = t;
			this.time = time;
		}
		public int compareTo(T o){
			if(y != o.y)
				return Integer.compare(o.y, y);
			return Integer.compare(time, o.time);
		}
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