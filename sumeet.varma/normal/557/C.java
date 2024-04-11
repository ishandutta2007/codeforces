import java.io.*;
import java.util.*;

public class R311qC {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		
		MyArrayList list[] = new MyArrayList[100001];
		for(int i=1;i<=100000;i++)
			list[i] = new MyArrayList();
		
		int n = in.nextInt();
		
		int l[] = new int[n];
		
		for(int i=0;i<n;i++)
			l[i] = in.nextInt();
		
		int cum[] = new int[100001];
		
		int c,cost = 0;
		for(int i=0;i<n;i++){
			c = in.nextInt();
			cum[l[i]] += c;
			list[l[i]].add(c);
			cost += c;
		}
		
		
		int ans = Integer.MAX_VALUE;
		int sum = 0;
		int count[] = new int[201];
		
		for(int max = 1;max <= 100000;max++){
			if(list[max].actSize != 0){
				int curr = sum;
				int canKeep = list[max].actSize - 1;
				
				int t;
				
				for(int i=200;i>=1 && canKeep > 0;i--){
					t = Math.min(count[i],canKeep);
					canKeep -= t;
					curr -= i * t;
				}
				
				for(int i=0;i<list[max].actSize;i++){
					count[list[max].myStore[i]]++;
				}
					
				cost -= cum[max];
				sum  += cum[max];
				
				
				ans = Math.min(ans, curr + cost);
			}
		}
	
		w.println(ans);
		w.close();
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