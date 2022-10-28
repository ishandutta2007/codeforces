import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;


public class Colourfulgraph {

	static ArrayList<Integer> g[][];
	static boolean color[];
	static int n,m;
	static boolean reached;
	
	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int t = 1;
	    
	    while(t-- > 0) {
	    	StringTokenizer st1 = new StringTokenizer(br.readLine());
	    	n = ip(st1.nextToken());
	        m = ip(st1.nextToken());
	         
	    	g = new ArrayList[n+1][m+1];
	    	for(int i=1;i<=n;i++){
	    		for(int j=1;j<=m;j++)
	    			g[i][j] = new ArrayList();
	    	}
	    		
	    	
	    	for(int i=0;i<m;i++){
	    		StringTokenizer st2 = new StringTokenizer(br.readLine());
	    		int u = ip(st2.nextToken());
	    		int v = ip(st2.nextToken());
	    		int c = ip(st2.nextToken());
	    		g[u][c].add(v);
	    		g[v][c].add(u);
	    	}
	    	
	    	int Q = ip(br.readLine());
	    	for(int q=0;q<Q;q++){
	    		StringTokenizer st3 = new StringTokenizer(br.readLine());
	    		int u = ip(st3.nextToken());
	    		int v = ip(st3.nextToken());
	    		
	    		int ans = 0;
	    		for(int i=1;i<=m;i++){
	    			if(query(u,v,i))
	    				ans++;
	    		}
	    		
	    		w.println(ans);
	    	}
	  
	    }
	        
	    w.close();
	        
	}
	
	public static boolean query(int u,int v,int c){
	
		Stack<Integer> s = new Stack<Integer>();
		s.push(u);
		
		boolean visited[] = new boolean[n+1];
		visited[u] = true;
		
		while(!s.isEmpty()){
			int curr = s.pop();
			if(curr==v)	return true;
			int len = g[curr][c].size();
			for(int i=0;i<len;i++){
				if(visited[g[curr][c].get(i)] == false){
					s.push(g[curr][c].get(i));
					visited[g[curr][c].get(i)] = true;
				}
			}
		}
		
		return false;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}