import java.io.*;
import java.util.*;


public class R310QgCaseOfComputerNetwork {

	static int n,m,q;
	static MyArrayList g[],g2[],roots,treeSizes;
	static boolean vis[],yes;
	static int disc[],low[],id[],root[],parent[];
	static int bridgeParent[],bridgeLevel[];
	static int P[][][];
	static int time,total,currRoot;
	static int count[][];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		m = in.nextInt();
		q = in.nextInt();
		
		g = new MyArrayList[n + 1];
		for(int i=1;i<=n;i++)
			g[i] = new MyArrayList();
		
		int u,v;
		for(int i=1;i<=m;i++){
			u = in.nextInt();
			v = in.nextInt();
			g[u].add(v);
			g[v].add(u);
		}
		
		vis = new boolean[n + 1];
		disc = new int[n + 1];
		low = new int[n + 1];
		parent = new int[n + 1];
		time = 0;
		
		vis[1] = true;
		dfs(1);
		
		//System.out.println(Arrays.toString(parent));
		//System.out.println(Arrays.toString(disc));
		//System.out.println(Arrays.toString(low));
		
		g2 = new MyArrayList[n + 1];
		for(int i=1;i<=n;i++)
			g2[i] = new MyArrayList();
		
		roots = new MyArrayList();
		treeSizes = new MyArrayList();
		
		Arrays.fill(vis, false);
		total = 0;
		id = new int[n + 1];
		root = new int[n + 1];
		bridgeParent = new int[n + 1];
		bridgeLevel = new int[n + 1];
		
		int start;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i] = true;
				start = total;
				id[i] = ++total;
				currRoot = roots.size();
				roots.add(i);
				dfs2(i,id[i]);
				treeSizes.add(total - start);
			}
		}
		
		//System.out.println(Arrays.toString(id));
		//System.out.println(Arrays.toString(bridgeLevel));
		//System.out.println(Arrays.toString(bridgeParent));
		//System.out.println(roots);
		//System.out.println(Arrays.toString(root));
		
		int ss = roots.size();
		P = new int[ss][][];
		for(int i=0;i<ss;i++)
			buildLCA(roots.get(i),i);
		
		count = new int[total + 1][2];
		
		yes = true;
		int s,d,lca;
		while(q-- > 0 && yes){
			s = in.nextInt();
			d = in.nextInt();
			if(root[s] != root[d])
				yes = false;
			else{
				count[id[s]][0]++;
				count[id[d]][1]++;
				//System.out.println(id[s] + " " + id[d] + " " + root[s]);
				lca = getLCA(id[s],id[d],root[s]);
				count[lca][0]--;
				count[lca][1]--;
			}
		}
		
		vis = new boolean[total + 1];
		
		s = roots.size();
		for(int i=0;i<s && yes;i++){
			vis[roots.get(i)] = true;
			dfs3(roots.get(i));
		}
		
		w.println(yes ? "Yes" : "No");
		w.close();
	}
	
	public static void dfs3(int curr){
		if(!yes)	return;
		int s = g2[curr].size(),x;
		for(int i=0;i<s;i++){
			x = g2[curr].get(i);
			if(!vis[x]){
				dfs3(x);
				count[curr][0] += count[x][0];
				count[curr][1] += count[x][1];
			}
		}
		if(count[curr][0] > 0 && count[curr][1] > 0)
			yes = false;
	}
	
	
	public static void buildLCA(int root,int rootId){
		bridgeParent[root] = root;
		
		int N = treeSizes.get(rootId);
		P[rootId] = new int[20][N + 1];
	
		for(int j=0;1<<j<N;j++)
			for(int i=1;i<=N;i++)
				P[rootId][j][i] = -1;
		
		for(int i=1;i<=N;i++)
			P[rootId][0][i] = bridgeParent[i];
		
		for(int j=1;(1<<j) < N;++j)
			for(int i=1;i<=N;++i)
				if(P[rootId][j-1][i] != -1)
					P[rootId][j][i] = P[rootId][j-1][P[rootId][j-1][i]];
		
	}
	
	public static int getLCA(int p,int q,int rootId){
		int tmp,log,i;
		if(bridgeLevel[p] < bridgeLevel[q]){
			tmp = p;
			p = q;
			q = tmp;
		}
		
		for(log=1;1<<log <= bridgeLevel[p];log++);
		log--;
		
		for(i = log; i >= 0; i--)
			if(bridgeLevel[p] - (1<<i) >= bridgeLevel[q])
				p = P[rootId][i][p];
		
		if(p == q)	return p;
		
		for(i = log; i >= 0; i--)
			if(P[rootId][i][p] != -1 && P[rootId][i][p] != P[rootId][i][q]){
				p = P[rootId][i][p];
				q = P[rootId][i][q];
			}
		
		return bridgeParent[p];
	}
	
	
	static public void dfs(int curr){
		disc[curr] = low[curr] = time++;
		boolean notParent = false;
		int s = g[curr].size(),x;
		for(int i=0;i<s;i++){
			x = g[curr].get(i);
			if(vis[x]){
				if(x != parent[curr])
					low[curr] = Math.min(low[curr], disc[x]);
				else{
					if(notParent)
						low[curr] = Math.min(low[curr],disc[x]);
					else
						notParent = true;
				}
			}
			else{
				vis[x] = true;
				parent[x] = curr;
				dfs(x);
				low[curr] = Math.min(low[x], low[curr]);
			}
		}
	}

	static public void dfs2(int curr,int type){
		id[curr] = type;
		root[curr] = currRoot;
		int s = g[curr].size(),x;
		for(int i=0;i<s;++i){
			x = g[curr].get(i);
			if(!vis[x]){
				vis[x] = true;
				if(low[x] > disc[curr]){
					total++;
					bridgeLevel[total] = bridgeLevel[type] + 1;
					bridgeParent[total] = type;
					g2[type].add(total);
					dfs2(x,total);
				}
				else
					dfs2(x,type);
			}
		}
	}
	
	static public class MyArrayList {
		 
	    private int[] myStore;
	    private int actSize = 0;
	     
	    public MyArrayList(){
	        myStore = new int[5];
	    }
	     
	    public int get(int index){
	        if(index < actSize)
	            return myStore[index];
	         else 
	            throw new ArrayIndexOutOfBoundsException();
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