import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class R24qARingRoad {

	static int clock,antiClock;
	static ArrayList<Integer> g[];
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
	    g = new ArrayList[n+1];
	    for(int i=1;i<=n;i++)
	    	g[i] = new ArrayList<Integer>(4);
	    
	    
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	int a = ip(st2.nextToken());
	    	int b = ip(st2.nextToken());
	    	int c = ip(st2.nextToken());
	    	g[a].add(b);
	    	g[a].add(c);
	    	g[b].add(a);
	    	g[b].add(-1*c);
	    }
	    
	    clock = antiClock = 0;
	    dfs(1,-1);
	    w.println(Math.min(clock,antiClock));
	    
	    w.close(); 
	}
	
	public static void dfs(int curr,int prev){
		int s = g[curr].size();
		for(int i=0;i<s;){
			int nxt = g[curr].get(i++);
			int weg = g[curr].get(i++);
			if(nxt == prev)	continue;
			if(weg > 0)	clock += weg;
			else	antiClock += -1*weg;
			if(nxt == 1)	break;
			dfs(nxt,curr);
			break;
		}
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	public static long lp(String s){
		return Long.parseLong(s);
	}
}