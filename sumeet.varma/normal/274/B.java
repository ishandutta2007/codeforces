import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class R168qDZeroTree {

	static int n;
	static long v[];
	static ArrayList<Integer> g[];
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    n = ip(br.readLine());
		
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
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    v = new long[n];
	    for(int i=0;i<n;i++)
	    	v[i] = ip(st2.nextToken());
	        
	    Node ans = dfs(0,-1);
	    w.println(ans.inc + ans.dec);
	    w.close(); 
	}
	
	public static Node dfs(int curr,int prev){
		Node ret = new Node(0L,0L);
		
		int s = g[curr].size();
		for(int j=0;j<s;j++){
			if(g[curr].get(j) == prev)	continue;
			Node back = dfs(g[curr].get(j),curr);
			ret.inc = Math.max(ret.inc, back.inc);
			ret.dec = Math.max(ret.dec, back.dec);
		}
		
		v[curr] = v[curr] + ret.inc - ret.dec;
		if(v[curr] > 0)	ret.dec += v[curr];
		if(v[curr] < 0)	ret.inc -= v[curr];
		
		return ret;
	}
	
	static public class Node{
		long inc,dec;
		Node(long i,long d){
			inc = i;
			dec = d;
		}
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}