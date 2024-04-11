import java.io.*;
import java.util.*;

public class R311qD {
	
	static MyArrayList g[];
	static int n,m;
	static long ans = 0;
	static long ones = 0,twos = 0;
	static long l,r;
	static boolean oddCycle = false,ansIsTwo = true;
	static int color[];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		m = in.nextInt();
		
		g = new MyArrayList[n];
		for(int i=0;i<n;i++)
			g[i] = new MyArrayList();
		
		if(m == 0){
			long ans1 = (long)n * (n - 1) * (n - 2) / 6;
			System.out.println(3 + " " + ans1);
			return;
		}
		
		int a,b;
		while(m-- > 0){
			a = in.nextInt() - 1;
			b = in.nextInt() - 1;
			g[a].add(b);
			g[b].add(a);
		}
		
		color = new int[n];
		for(int i=0;i<n;i++){
			if(color[i] == 0){
				color[i] = 1;
				l = 0;
				r = 0;
				int size = dfs(i);
				if(size == 1)
					ones++;
				else if(size == 2)
					twos++;
				else
					ansIsTwo = false;
				ans +=  1l * r * (r - 1) / 2 + l * 1L * (l - 1)  / 2;
			}
		}
		
		if(oddCycle)
			w.println("0 1");
		else if(ansIsTwo){
			long ans2 = ones * 1L * twos + twos * (twos - 1) * 2L;
			w.println("2 " + ans2);
		}
		else
			w.println("1 " + ans);

		w.close();
	}
	
	static public int dfs(int curr){
		if(color[curr] == 1)
			l++;
		else
			r++;
		int size = 1;
		for(int i=0;i<g[curr].size();i++){
			int nxt = g[curr].get(i);
			if(color[nxt] == 0){
				color[nxt] = -1 * color[curr];
				size += dfs(nxt);
			}
			else if(color[nxt] == color[curr])
				oddCycle = true;
		}
		return size;
	}
	
	static public class MyArrayList {
		 
	    private int[] myStore;
	    private int actSize = 0;
	     
	    public MyArrayList(){
	        myStore = new int[10];
	    }
	     
	    public int get(int index){
	        if(index < actSize)
	            return myStore[index];
	         else 
	            throw new ArrayIndexOutOfBoundsException();
	    }
	     
	    public void add(int obj){
	        if(myStore.length-actSize <= 5)
	            increaseListSize();
	        myStore[actSize++] = obj;
	    }
	   
	    public int size(){
	        return actSize;
	    }
	     
	    private void increaseListSize(){
	        myStore = Arrays.copyOf(myStore, myStore.length*2);
	    }
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