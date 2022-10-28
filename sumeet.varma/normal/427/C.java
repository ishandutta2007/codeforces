import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Stack;

public class R244QCCheckPostsSCC {
	
	static int n;
	static ArrayList<Integer> g[],r[];
	static int cost[];
	static long ans = 1,mod = (long)(1e9 + 7),money = 0;
	static boolean vis[];
	static Stack<Integer> st;
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
	    
	    cost = new int[n+1];
	    g = new ArrayList[n+1];
	    r = new ArrayList[n+1];
	   
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    for(int i=1;i<=n;i++){
	    	cost[i] = ip(st2.nextToken());
	    	g[i] = new ArrayList<Integer>();
	    	r[i] = new ArrayList<Integer>();
	    }
	    
	    int M = ip(br.readLine());
	    for(int m=0;m<M;m++){
	    	StringTokenizer st3 = new StringTokenizer(br.readLine());
	    	int u = ip(st3.nextToken());
	    	int v = ip(st3.nextToken());
	    	g[u].add(v);
	    	r[v].add(u);
	    }
	    
	    vis = new boolean[n+1];
	    st = new Stack<Integer>();
	    
	    for(int i=1;i<=n;i++)
	    	if(!vis[i])
	    		dfsRev(i);
	    
	    Arrays.fill(vis, false);
	    
	    while(!st.isEmpty()){
	    	int curr = st.pop();
	    	if(!vis[curr])
	    		ans = (ans * dfsVisit(curr)) % mod;
	    }
	    
	    w.println(money + " " + ans);
	    w.close(); 
	}
	
	
	private static void dfsRev(int curr) {
		int s = r[curr].size();
		vis[curr] = true;
		for(int i=0;i<s;i++){
			int nxt = r[curr].get(i);
			if(!vis[nxt]){
				vis[nxt] = true;
				dfsRev(nxt);
			}
		}
		st.push(curr);
	}

	private static long dfsVisit(int curr){
		long ans = 0;
		ArrayList<Integer> scc = new ArrayList<Integer>();
		vis[curr] = true;
		dfs(curr,scc);
		long min = cost[curr];
		
		int s = scc.size();
		for(int i=0;i<s;i++)
			min = Math.min(cost[scc.get(i)], min);
	
		money += min;
		
		for(int i=0;i<s;i++)
			if(cost[scc.get(i)] == min)
				ans++;
		
		return ans;
	}
	
	private static void dfs(int curr,ArrayList<Integer> scc){
		int s = g[curr].size();
		for(int i=0;i<s;i++){
			int nxt = g[curr].get(i);
			if(!vis[nxt]){
				vis[nxt] = true;
				dfs(nxt,scc);
			}
		}
		scc.add(curr);
	}

	public static int ip(String s){
		return Integer.parseInt(s);
	}
}