import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class R87qAParty {

	static ArrayList<Integer> g[];
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	        
	    g = new ArrayList[n];
	    for(int i=0;i<n;i++)
	    	g[i] = new ArrayList<Integer>();
	    
	    ArrayList<Integer> roots = new ArrayList<Integer>();
	    
	    for(int i=0;i<n;i++){
	    	int p = ip(br.readLine());
	    	if(p != -1)
	    		g[p - 1].add(i);
	    	else
	    		roots.add(i);
	    }
	    
	    int ans = 0;
	    for(int root : roots)
	    	ans = Math.max(ans, dfs(root));
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int dfs(int curr){
		int s = g[curr].size();
		int ans = 0;
		for(int i=0;i<s;i++)
			ans = Math.max(ans,dfs(g[curr].get(i)));
		ans++;
		return ans;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}