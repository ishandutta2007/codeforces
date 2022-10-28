import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class R216qCValeraAndSubtree {

	static ArrayList<Integer> g[],list;
	static boolean badThere[];
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
	    g = new ArrayList[n];
	    for(int i=0;i<n;i++)
			g[i] = new ArrayList<Integer>();
	    
		for(int i=1;i<n;i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int u = ip(st.nextToken()) - 1;
			int v = ip(st.nextToken()) - 1;
			int t = ip(st.nextToken());
			g[u].add(v);
			g[u].add(t);
			g[v].add(u);
			g[v].add(t);
		}
		
		badThere = new boolean[n];
		dfs1(0,-1);
	   
		list = new ArrayList<Integer>();
		dfs2(0,-1,false);
	    
	    int ans = list.size();
	    w.println(ans);
	    for(int i=0;i<ans;i++)
	    	w.print((list.get(i)+1) + " ");
	    
	    w.close(); 
	}
	
	
	public static boolean dfs1(int curr,int prev){
		int s = g[curr].size();
		boolean ret = false;
		for(int i=0;i<s;){
			int nxt = g[curr].get(i++);
			int type = g[curr].get(i++);
			if(nxt == prev)	continue;
			if(type == 2)	ret = true;
			ret |= dfs1(nxt,curr);
		}
		badThere[curr] = ret;
		return ret;
	}
	
	public static void dfs2(int curr,int prev,boolean need){
		int s = g[curr].size();
		
		if(badThere[curr] == false){
			if(need)
				list.add(curr);
			return;
		}
		
		for(int i=0;i<s;){
			int nxt = g[curr].get(i++);
			int type = g[curr].get(i++);
			if(nxt == prev)	continue;
			if(type == 1)
				dfs2(nxt,curr,false);
			else
				dfs2(nxt,curr,true);
		}
		
		return;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}