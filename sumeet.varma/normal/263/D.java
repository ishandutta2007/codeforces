import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R161qDCyclesInGraph {

	static ArrayList<Integer> g[],ans;
	static int vis[],parent[];
	static boolean cycleFound;
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	    //int k = ip(st1.nextToken());
	          
	    g = new ArrayList[n];
	    for(int i=0;i<n;i++)
			g[i] = new ArrayList<Integer>();
		
	    for(int i=0;i<m;i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int u = ip(st.nextToken()) - 1;
			int v = ip(st.nextToken()) - 1;
			g[u].add(v);
			g[v].add(u);
		}
	    
	    vis = new int[n];
	    Arrays.fill(vis, -1);
	    cycleFound = false;
	    
	    parent = new int[n];
	    
	    for(int i=0;i<n && !cycleFound;i++){
	    	if(vis[i] == -1){
	    		vis[i] = 1;
	    		parent[i] = -1;
	    		dfs(i);
	    	}
	    }
	    
	    w.println(ans.size());
	    for(int v : ans)
	    	w.print((v+1) + " ");
	    w.println();
	    
	    w.close(); 
	}
	
	public static void dfs(int curr){

		if(cycleFound)	return;
		
		boolean found = false;
		int s = g[curr].size();
		for(int j=0;j<s;j++){
			int nxt = g[curr].get(j);
			if(vis[nxt] == -1){
				vis[nxt] = vis[curr] + 1;
				parent[nxt] = curr;
				dfs(nxt);
				found = true;
			}
		}
		
		if(!found){
			cycleFound = true;
			int min = g[curr].get(0);
			for(int j=0;j<s;j++){
				int nxt = g[curr].get(j);
				if(vis[nxt] < vis[min])
					min = nxt;
			}
			
			ans = new ArrayList<Integer>();
			while(curr != parent[min]){
				ans.add(curr);
				curr = parent[curr];
			}
			
		}
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}