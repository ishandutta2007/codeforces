import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class R277qDValidSets {

	static int n,d;
	static ArrayList<Integer> g[];
	static int a[];
	static long mod = (long)(1e9 + 7);
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    d = ip(st1.nextToken());
		n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    g = new ArrayList[n];
		for(int i=0;i<n;i++)
			g[i] = new ArrayList<Integer>();
		for(int i=1;i<n;i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int u = ip(st.nextToken()) - 1;
			int v = ip(st.nextToken()) - 1;
			g[u].add(v);
			g[v].add(u);
		}
		
		long ans = 0;
		for(int i=0;i<n;i++){
			ans += dfs(i,-1,i) + mod - 1;
			if(ans >= mod)	ans %= mod;
		}
		
		w.println(ans);
	    w.close(); 
	}
	
	public static long dfs(int curr,int prev,int minID){
		if(a[curr] < a[minID])	return 1;
		if(a[curr] == a[minID] && curr < minID)	return 1;
		if(a[curr] > a[minID] + d)	return 1;
		
		long ret = 1;
		int s = g[curr].size();
		for(int i=0;i<s;i++){
			if(g[curr].get(i) == prev)	continue;
			ret *= dfs(g[curr].get(i),curr,minID);
			if(ret >= mod)	ret %= mod;
		}
		
		return ret + 1;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}