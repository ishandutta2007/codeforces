import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;


public class R121qEFoolsAndRoads {

	static int n,k;
	static ArrayList<Integer> g[];
	static int P[][];
	static int L[],T[],ans[],count[];
	static final int LOGMAXN = 20;
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    n = ip(br.readLine());
	    
	    g = new ArrayList[n];
	    for(int i=0;i<n;i++)
	    	g[i] = new ArrayList<Integer>();
	    
	    int u,v;
	    for(int i=1;i<n;i++){
	    	StringTokenizer st1 = new StringTokenizer(br.readLine());
	    	u = ip(st1.nextToken()) - 1;
	    	v = ip(st1.nextToken()) - 1;
	    	g[u].add(v);
	    	g[u].add(i);
	    	g[v].add(u);
	    	g[v].add(i);
	    }
	    
	    preprocess();
	    
	    count = new int[n];
	    ans = new int[n];
	    
	    k = ip(br.readLine());
	    for(int i=0;i<k;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	int a = ip(st2.nextToken()) - 1;
	    	int b = ip(st2.nextToken()) - 1;
	    	int lca = getLCA(a,b);
	    	count[lca] -= 2;
	    	count[a] += 1;
	    	count[b] += 1;
	    }
	    
	    dfs2(0,-1);
	    
	    for(int i=1;i<n;i++)
	    	w.print(ans[i] + " ");
	    w.println();
	    w.close(); 
	}
	
	public static void dfs2(int curr,int prev){
		int s = g[curr].size();
		for(int i=0;i<s;){
			int nxt = g[curr].get(i++);
			int edge = g[curr].get(i++);
			if(nxt == prev)	continue;
			dfs2(nxt,curr);
			ans[edge] += count[nxt];
			count[curr] += count[nxt];
		}
	}
	
	public static void preprocess(){
		L = new int[n];
		T = new int[n];
		dfs(0,-1);
		T[0] = 0;
		
		P = new int[LOGMAXN][n];
	
		for(int j=0;1<<j<n;j++)
			for(int i=0;i<n;i++)
				P[j][i] = -1;
		
		for(int i=0;i<n;i++)
			P[0][i] = T[i];
		
		for(int j=1;(1<<j) < n;++j)
			for(int i=0;i<n;++i)
				if(P[j-1][i] != -1)
					P[j][i] = P[j-1][P[j-1][i]];
		
	}
	
	public static void dfs(int curr,int prev){
		T[curr] = prev;
		int s = g[curr].size();
		for(int i=0;i<s;i+=2){
			int nxt = g[curr].get(i);
			if(nxt != prev){
				L[nxt] = L[curr] + 1;
				dfs(nxt,curr);
			}
		}
	}
	
	public static int getLCA(int p,int q){
		int tmp,log,i;
		if(L[p] < L[q]){
			tmp = p;
			p = q;
			q = tmp;
		}
		
		for(log=1;1<<log <= L[p];log++);
		log--;
		
		for(i = log; i >= 0; i--)
			if(L[p] - (1<<i) >= L[q])
				p = P[i][p];
		
		if(p == q)	return p;
		
		for(i = log; i >= 0; i--)
			if(P[i][p] != -1 && P[i][p] != P[i][q]){
				p = P[i][p];
				q = P[i][q];
			}
		
		return T[p];
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}