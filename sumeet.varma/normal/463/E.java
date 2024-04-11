import java.io.*;
import java.util.*;


public class R264qECaisaAndTree {

	static final int N = 2 * 1000 * 1000;
	static int n,q;
	static int a[];
	static MyArrayList g[];
	static int ans[];
	static MyArrayList list[];
	static int maxPrime[],wowPrime[];
	static int depth[];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
		q = in.nextInt();
		
		a = new int[n + 1];
		for(int i=1;i<=n;i++)
			a[i] = in.nextInt();
		
		g = new MyArrayList[n + 1];
		for(int i=1;i<=n;i++)
			g[i] = new MyArrayList();
		
		for(int i=1;i<n;i++){
			int u = in.nextInt();
			int v = in.nextInt();
			g[u].add(v);
			g[v].add(u);
		}
		
		list = new MyArrayList[N + 1];
		
		maxPrime = new int[N + 1];
		maxPrime[1] = 1;
		wowPrime = new int[N + 1];
		wowPrime[1] = 1;
				
		for(int i=2;i<=N;i++){
			if(maxPrime[i] == 0){
				list[i] = new MyArrayList();
				for(int j=i;j<=N;j+=i){
					if(wowPrime[j] != 0)
						continue;
					int num = j;
					maxPrime[j] = 1;
					while(num % i == 0){
						num /= i;
						maxPrime[j] *= i;
					}
					wowPrime[j] = i;
				}
				if(wowPrime[i] == i)
					list[i] = new MyArrayList();
			}
		}
		
		depth = new int[n + 1];
		assignDepths(1,0);
		
		ans = new int[n + 1];
		process();
		
		while(q-- > 0){
			int type = in.nextInt();
			if(type == 1){
				int x = in.nextInt();
				w.println(ans[x] == 0 ? -1 : ans[x]);
			}
			else{
				int x = in.nextInt();
				int v = in.nextInt();
				a[x] = v;
				process();
			}
		}
		
		w.close();
	}
	
	static void process(){
		for(int i=2;i<=N;i++)
			if(wowPrime[i] == i)
				list[i].actSize = 0;
		Arrays.fill(ans, 0);
		dfs(1,0);
	}
	
	
	static void dfs(int curr,int prev){
		
		int wow = a[curr];
		while(wow != 1){
			int prime = wowPrime[wow];
			wow /= maxPrime[wow];
			if(list[prime].size() != 0){
				int next = list[prime].get(list[prime].size() - 1);
				if(depth[next] > depth[ans[curr]])
					ans[curr] = next;
			}
			list[prime].add(curr);
		}
		
		int s = g[curr].size();
		for(int i=0;i<s;i++){
			int x = g[curr].get(i);
			if(x != prev)
				dfs(x,curr);
		}
		
		wow = a[curr];
		while(wow != 1){
			int prime = wowPrime[wow];
			wow /= maxPrime[wow];
			list[prime].actSize--;
		}
		
	}
	
	static void assignDepths(int curr,int prev){
		depth[curr] = depth[prev] + 1;
		int s = g[curr].size();
		for(int i=0;i<s;i++){
			int x = g[curr].myStore[i];
			if(x != prev)
				assignDepths(x,curr);
		}
	}
	
	static public class MyArrayList {
		 
	    private int[] myStore;
	    private int actSize = 0;
	     
	    public MyArrayList(){
	        myStore = new int[5];
	    }
	     
	    public int get(int index){
	        return myStore[index];
	    }
	     
	    public void add(int obj){
	        if(myStore.length-actSize <= 1)
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
			
			int res = 0;

			do {
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res;
		}
		
		public boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

	}

}