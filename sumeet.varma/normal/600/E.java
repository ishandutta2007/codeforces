import java.io.*;
import java.util.*;

public class Ed2qE {

	static int n;
	static ArrayList<Integer> g[];
	static int time,count;
	static int discovery[],begin[],end[],level[],rev[];
	static int color[];
	static long ans[];
	static Query q[];
	static int cnt[];
	static int maxCnt[];
	static long maxSum[];
	static int maximum;
	static int bound;
	
	@SuppressWarnings("unchecked")
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
		
		color = new int[n];
		for(int i=0;i<n;i++)
			color[i] = in.nextInt();
	
		g = new ArrayList[n];
		for(int i=0;i<n;i++)
			g[i] = new ArrayList<Integer>();
		
		for(int i=1;i<n;i++){
			int u = in.nextInt() - 1;
			int v = in.nextInt() - 1;
			g[u].add(v);
			g[v].add(u);
		}
		
		count = 0;
	    time = -1;
	    discovery = new int[n];
	    begin = new int[n];
	    end = new int[n];
	    level = new int[n];
	    rev = new int[n];
	    
	    dfs(0,-1);
	    for(int i=0;i<n;i++)
	    	rev[discovery[i]] = i;
		
	    ans = new long[n];
	    Query.nsqrt = (int)(Math.sqrt(n) + 0.001);
	    
	    q = new Query[n];
	    for(int i=0;i<n;i++)
	    	q[i] = new Query(begin[i],end[i],i);
		
	    Arrays.sort(q);
	    
	    bound = 3*n + 7;
	    
	    cnt = new int[n + 1];
	    Arrays.fill(cnt, bound);
	  
	    maxCnt = new int[6*n + 15];
	    maxSum = new long[6*n + 15];
	    
	    maxCnt[bound] = n;
	    maxSum[bound] = n * 1L * (n + 1) / 2;
	    maximum = bound;
	    
	    int left = 0,right = -1;
	    
	    for(int i=0;i<n;i++){
	    	int x = q[i].l;
	    	int y = q[i].r;
	    	
	    	while(left < x)
	    		remove(color[discovery[left++]]);
	    	
	    	while(left > x)
	    		add(color[discovery[--left]]);
	    	
	    	while(right < y)
	    		add(color[discovery[++right]]);
	    	
	    	while(right > y)
	    		remove(color[discovery[right--]]);
	    	
	    	ans[q[i].id] = maxSum[maximum];
	    }
	   
	    
	    for(int i=0;i<n;i++)
	    	w.print(ans[i] + " ");
	    w.println();
		w.close();
	}
	
	public static void add(int c){
		//System.out.println(c);
		maxSum[cnt[c]] -= c;
		maxCnt[cnt[c]]--;
		cnt[c]++;
		maxSum[cnt[c]] += c;
		maxCnt[cnt[c]]++;
		
		if(maxCnt[maximum + 1] > 0)
			maximum++;
	}
	
	public static void remove(int c){
		//System.out.println("rem " + c + " " + cnt[c]);
		maxSum[cnt[c]] -= c;
		maxCnt[cnt[c]]--;
		cnt[c]--;
		maxSum[cnt[c]] += c;
		maxCnt[cnt[c]]++;
		
		if(maxCnt[maximum] == 0)
			maximum--;
	}
	
	public static void dfs(int curr,int prev){
		int s = g[curr].size();
		time++;
		discovery[count++] = curr; 
		begin[curr] = time;
	
		for(int i=0;i<s;i++){
			int nxt = g[curr].get(i);
			if(nxt == prev)	continue;
			level[nxt] = level[curr] + 1;
			dfs(nxt,curr);
		}
	
		end[curr] = time;
	}
	
	static class Query implements Comparable<Query>{
		int l,r,block,id;
		static int nsqrt;
		
		public Query(int l,int r,int id){
			this.l = l;
			this.r = r;
			block = l / nsqrt ;
			this.id = id;
		}
		
		public int compareTo(Query b){
			if(block != b.block)
				return block - b.block;
			return r - b.r;
		}
		
		public String toString(){
			return id + " " + l + " " + r + " " + block;
		}
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