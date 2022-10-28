import java.io.*;
import java.util.*;

public class R349qB {
	
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		MyArrayList g[] = new MyArrayList[n];
		MyArrayList r[] = new MyArrayList[n];
		
		for(int i = 0; i < n; i++){
			g[i] = new MyArrayList();
			r[i] = new MyArrayList();
		}
		
		for(int i = 0; i < m; i++){
			int u = in.nextInt() - 1;
			int v = in.nextInt() - 1;
			g[u].add(v);
			r[v].add(u);
		}
		
		int d[][] = new int[n][n];
		
		for(int i = 0; i < n; i++){
			Arrays.fill(d[i], -1);
			
			d[i][i] = 0;
			Queue<Integer> q = new ArrayDeque<Integer>();
			q.add(i);
			
			while(!q.isEmpty()){
				int c = q.remove();
				for(int j = 0; j < g[c].size(); j++){
					int cc = g[c].get(j);
					if(d[i][cc] == -1){
						d[i][cc] = d[i][c] + 1;
						q.add(cc);
					}
				}
			}
			
		}
		
		int mx[][] = new int[n][3];
		int vl[][] = new int[n][3];
		
		for(int i = 0; i < n; i++){
			
			int max[] = new int[3];
			int val[] = new int[3];
			Arrays.fill(max, -1);
			Arrays.fill(val, -1);
			
			for(int j = 0; j < n; j++){
				int x = d[i][j];
				if(i == j)
					continue;
				if(x == -1)
					continue;
				if(x > val[0]){
					
					val[2] = val[1];
					max[2] = max[1];
					
					max[1] = max[0];
					val[1] = val[0];
					
					max[0] = j;
					val[0] = x;
				}
				
				else if(x > val[1]){
					val[2] = val[1];
					max[2] = max[1];
					
					val[1] = x;
					max[1] = j;
				}
				
				else if(x > val[2]){
					val[2] = x;
					max[2] = j;
				}
			}
		
			for(int j = 0;j < 3; j++){
				mx[i][j] = max[j];
				vl[i][j] = val[j];
			}
			
		}
		
		int mx1[][] = new int[n][3];
		int vl1[][] = new int[n][3];
		
		for(int i = 0; i < n; i++){
			
			int max[] = new int[3];
			int val[] = new int[3];
			Arrays.fill(max, -1);
			Arrays.fill(val, -1);
			
			for(int j = 0; j < n; j++){
				if(i == j)
					continue;
				int x = d[j][i];
				if(x == -1)
					continue;
				if(x > val[0]){
					
					val[2] = val[1];
					max[2] = max[1];
					
					max[1] = max[0];
					val[1] = val[0];
					
					max[0] = j;
					val[0] = x;
				}
				
				else if(x > val[1]){
					val[2] = val[1];
					max[2] = max[1];
					
					val[1] = x;
					max[1] = j;
				}
				
				else if(x > val[2]){
					val[2] = x;
					max[2] = j;
				}
			}
		
			for(int j = 0;j < 3; j++){
				mx1[i][j] = max[j];
				vl1[i][j] = val[j];
			}
			
		}
		
		//System.out.println(Arrays.toString(mx1[0]));
		//System.out.println(Arrays.toString(vl1[0]));
		
		int ans[] = new int[4];
		int val = -1;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				
				if(i == j || d[i][j] == -1)
					continue;
				
				for(int a = 0; a <= 2 && vl1[i][a] >= 0; a++){
					for(int b = 0; b <= 2 && vl[j][b] >= 0; b++){
						int curr = 0;
						if(mx1[i][a] == i || mx1[i][a] == j || mx1[i][a] == mx[j][b])
							continue;
						if(mx[j][b] == i || mx[j][b] == j || mx[j][b] == mx1[i][a])
							continue;
						curr = d[mx1[i][a]][i] + d[i][j] + d[j][mx[j][b]];
						
						if(curr >= val){
							val = curr;
							ans[0] = mx1[i][a];
							ans[1] = i;
							ans[2] = j;
							ans[3] = mx[j][b];
							//System.out.println(Arrays.toString(ans) + " " + curr);
						}
					}
				}
				
			}
		}
		
	//	System.out.println(val);
		w.println((1+ans[0]) + " " + (1+ans[1]) + " " + (1+ans[2]) + " " + (1+ans[3]));
		w.close();
	}
	
	static public class MyArrayList {
		 
	    private int[] myStore;
	    private int actSize = 0;
	     
	    public MyArrayList(){
	        myStore = new int[2];
	    }
	     
	    public int get(int index){
	        if(index < actSize)
	            return myStore[index];
	         else 
	            throw new ArrayIndexOutOfBoundsException();
	    }
	     
	    public void add(int obj){
	        if(myStore.length - actSize <= 1)
	            increaseListSize();
	        myStore[actSize++] = obj;
	    }
	   
	    public int size(){
	        return actSize;
	    }
	    
	    public void clear(){
	    	actSize = 0;
	    }
	    
	    private void increaseListSize(){
	        myStore = Arrays.copyOf(myStore, myStore.length*2);
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