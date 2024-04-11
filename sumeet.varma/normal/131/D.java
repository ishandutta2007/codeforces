import java.io.*;
import java.util.*;

public class R95qDSubway {

	static ArrayList<Integer> g[];
	static boolean vis[],inRing[];
	static int n,depth[],parent[];
	static int left,right;
		
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		
	    g = new ArrayList[n+1];
	    for(int i=1;i<=n;i++)
	    	g[i] = new ArrayList<Integer>();
	    
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	int u = ip(st2.nextToken());
	    	int v = ip(st2.nextToken());
	    	g[u].add(v);
	    	g[v].add(u);
	    }
	    
	    inRing = new boolean[n+1];
	    depth = new int[n+1];
	    parent = new int[n+1];
	    vis = new boolean[n+1];
	    left = right = -1;
	    vis[1] = true;
	    dfs(1,-1);
	   
	    if(left == -1 || right == -1)	throw new Exception();
	    makeRing();
	  
	    Arrays.fill(vis, false);
	    Arrays.fill(depth, 0);
	    
	    for(int i=1;i<=n;i++)
	    	if(inRing[i] == true)
	    		dfs(i,-1);
	    
	    for(int i=1;i<=n;i++)
	    	w.print(depth[i] + " ");
	    
	    w.close(); 
	}
	
	public static void dfs(int curr,int prev){
		int s = g[curr].size();
		for(int i=0;i<s;i++){
			int nxt = g[curr].get(i);
			if(nxt == prev || inRing[nxt])	continue;
			if(vis[nxt]){
				left = curr;
				right = nxt;
				return;
			}
			vis[nxt] = true;
			parent[nxt] = curr;
			depth[nxt] = depth[curr] + 1;
			dfs(nxt,curr);
		}
	}
	
	public static void makeRing(){
		inRing[left] = true;
		inRing[right] = true;
		
		int dl = depth[left],dr = depth[right];
		
		while(dr > dl){
			right = parent[right];
			dr--;
			inRing[right] = true;
		}
		
		while(dl > dr){
			left = parent[left];
			dl--;
			inRing[left] = true;
		}
		
		while(right != left){
			left = parent[left];
			right = parent[right];
			inRing[left] = inRing[right] = true;
		}
		
		return;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}