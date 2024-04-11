import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class R261D2TEPashmakAndGraph {	
	
	static Edge e[];
	static int dp[];
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter p = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	          
		e = new Edge[m];
		
		for(int i=0;i<m;i++){
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			int u = ip(st2.nextToken());
			int v = ip(st2.nextToken());
			int w = ip(st2.nextToken());
			e[i] = new Edge(u,v,w);
		}
	        
		Arrays.sort(e);
		dp = new int[n+1];
		
		for(int i=0;i<m;){
			int end = i;
			while(end < m && e[end].w == e[i].w)
				end++;
			
			ArrayList<Integer> updates = new ArrayList<Integer>();
			for(int j=i;j<end;j++){
				updates.add(e[j].v);
				updates.add(dp[e[j].u] + 1);
			}
			
			for(int j=0;j<updates.size();j++){
				int x = updates.get(j);
				int v = updates.get(++j);
				dp[x] = Math.max(dp[x],v);
			}
			
			i = end;
		}
		
		int ans = 1;
		for(int i=1;i<=n;i++)
			ans = Math.max(dp[i], ans);
	    
		p.println(ans);
	    p.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}

class Edge implements Comparable<Edge>{
	int u,v,w;
	Edge(int x,int y,int c){
		u = x;
		v = y;
		w = c;
	}
	public int compareTo(Edge e){
		return w - e.w;
	}
}