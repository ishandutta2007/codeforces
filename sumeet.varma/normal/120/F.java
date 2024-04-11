import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class RSaratovqFSpiders {

	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
	    
	    int ans = 0;
	    int t = ip(br.readLine());
	 
	    while(t-- > 0){
	    
	    	StringTokenizer st1 = new StringTokenizer(br.readLine());
	    	int n = ip(st1.nextToken());
	    	
	    	ArrayList<Integer> g[] = new ArrayList[n];
	 		for(int i=0;i<n;i++)
	 			g[i] = new ArrayList<Integer>();
	 		for(int i=1;i<n;i++){
	 			int u = ip(st1.nextToken()) - 1;
	 			int v = ip(st1.nextToken()) - 1;
	 			g[u].add(v);
	 			g[v].add(u);
	 		}
	 		
	 		int max = 0;
	 		
			for(int i=0;i<n;i++){
				boolean vis[] = new boolean[n];
				vis[i] = true;
				int dist[] = new int[n];
				dist[i] = 0;
				Queue<Integer> q = new LinkedList<Integer>();
				q.add(i);
				
				while(!q.isEmpty()){
					int curr = q.remove();
					int s = g[curr].size();
					for(int j=0;j<s;j++){
						int nxt = g[curr].get(j);
						if(!vis[nxt]){
							vis[nxt] = true;
							dist[nxt] = dist[curr] + 1;
							q.add(nxt);
						}
					}
				}
				
				for(int j=0;j<n;j++)
					max = Math.max(max, dist[j]);
			}
	    
	    	ans += max;
	    }
	
	    w.println(ans);
	    w.close();
	    br.close();
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}