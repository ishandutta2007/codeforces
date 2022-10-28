import java.io.*;
import java.util.*;

public class GoodBye15qE {

	static TreeMap<Integer,Integer> map;
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		int d[] = new int[3];
		for(int i = 0; i < 3; i++)
			d[i] = in.nextInt();
		
		Arrays.sort(d);
		
		map = new TreeMap<Integer,Integer>();
		
		for(int i = 0; i < n; i++)
			add(in.nextInt());
		
		int a = d[0], b = d[1], c = d[2];
		
		if(map.lastKey() > a + b + c){
			System.out.println(-1);
			return;
		}
		
		int ans = 0;
		
		while(!map.isEmpty()){
			int key = map.lastKey();
			if(key > b + c) {
				//System.out.println("ans " + ans);
				rem(key); //a + b + c
			}
			else if(key > a + c){ //b + c to defeat
				rem(key);
				Integer val = map.floorKey(a);
				//System.out.println(val + " " + map);
				if(val != null)
					rem(val);
			}
			else if(key > a + b && key > c){ // a + c to defeat
				rem(key);
				Integer val = map.floorKey(b);
				if(val != null)
					rem(val);
			}
			else if(key > c && key <= a + b){ // a + b to defeat
				rem(key);
				Integer val = map.floorKey(c);
				if(val != null)
					rem(val);
			}
			else
				break;
			ans++;
			//System.out.println(ans + " " + map);
		}
		
		//System.out.println(ans + " " + map);
		
		if(!map.isEmpty() && map.lastKey() > c)
			throw new RuntimeException();
		
		while(!map.isEmpty()){
			int key = map.lastKey();
			rem(key);
			ans++;
			if(map.isEmpty())
				break;
			Integer key2 = map.floorKey(b);
			if(key2 != null)	rem(key2);
			Integer key3 = map.floorKey(a);
			if(key3 != null)	rem(key3);
			if(key2 == null || key3 == null){
				if(key2 != null)	add(key2);
				if(key3 != null)	add(key3);
				Integer proKey = map.floorKey(a + b);
				if(proKey != null)
					rem(proKey);
			}
		}
		w.println(ans);
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