import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class R57qDEternalVictory {
	
	static int n;
	static ArrayList<Integer> g[];
	static long dist[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter p = new PrintWriter(System.out);
	    
	    n = ip(br.readLine());
	    
	    g = new ArrayList[n];
	    for(int i=0;i<n;i++)
	    	g[i] = new ArrayList<Integer>();
	    
	    for(int i=1;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	int x = ip(st2.nextToken()) - 1;
	    	int y = ip(st2.nextToken()) - 1;
	    	int w = ip(st2.nextToken());
	    	g[x].add(y);
	    	g[x].add(w);
	    	g[y].add(x);
	    	g[y].add(w);
	    }
	    
	    dist = new long[n];
	    dist[0] = 0;
	    long ans = dfs(0,-1);
	    long max = 0;
	    for(int i=1;i<n;i++)
	    	max = Math.max(max, dist[i]);
	    ans -= max;
	    p.println(ans);
	    p.close(); 
	}
	
	public static long dfs(int curr,int parent){
		int s = g[curr].size();
		long ans = 0;
		for(int i=0;i<s;){
			int nxt = g[curr].get(i++);
			int w = g[curr].get(i++);
			if(nxt != parent){
				dist[nxt] = dist[curr] + w;
				ans += 2*w + dfs(nxt,curr);
			}
		}
		return ans;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}