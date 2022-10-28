import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R196qDBookOfEvil {

	static int n,m,d;
	static boolean marked[];
	static ArrayList<Integer> g[];
	static int distUp[],distDown[];
	static int oo = (int)1e8;
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		m = ip(st1.nextToken());
	    d = ip(st1.nextToken());  
		
		marked = new boolean[n+1];
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    for(int i=0;i<m;i++)
	    	marked[ip(st2.nextToken())] = true;
	        
	    g = new ArrayList[n+1];
		for(int i=1;i<=n;i++)
			g[i] = new ArrayList<Integer>();
		
		for(int i=1;i<n;i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int u = ip(st.nextToken());
			int v = ip(st.nextToken());
			g[u].add(v);
			g[v].add(u);
		}
	    
		distDown = new int[n+1];
		Arrays.fill(distDown, -oo);
		dfs1(1,0);
		
		distUp = new int[n+1];
		Arrays.fill(distUp, -oo);
		dfs2(1,0);
		
		/*for(int i=1;i<=n;i++)
			System.out.print((distDown[i] < 0 ? -1 : distDown[i]) + " ");
		System.out.println();
		for(int i=1;i<=n;i++)
			System.out.print((distUp[i] < 0 ? -1 : distUp[i]) + " ");;
		System.out.println();*/
		
		int ans = 0;
		for(int i=1;i<=n;i++)
			if(distUp[i] <= d && distDown[i] <= d)	ans++;
		
		w.println(ans);
		w.close(); 
	}
	
	public static int dfs1(int curr,int prev){
		int s = g[curr].size();
		
		for(int i=0;i<s;i++)
			if(g[curr].get(i) != prev)
				distDown[curr] = Math.max(distDown[curr], dfs1(g[curr].get(i),curr) + 1);
		
		if(marked[curr])
			distDown[curr] = Math.max(distDown[curr],0);
		return distDown[curr];
	}
	
	public static void dfs2(int curr,int prev){
		if(distUp[curr] < 0 && marked[curr])
			distUp[curr] = 0;
		
		int s = g[curr].size();
		
		int max1 = -1, max2 = -1;
			
		for(int i=0;i<s;i++){
			int nxt = g[curr].get(i);
			if(nxt == prev)	continue;
			if(max1 == -1 || distDown[nxt] > distDown[max1]){
				max2 = max1;
				max1 = nxt;
			}	
			else if(max2 == -1 || distDown[nxt] > distDown[max2])
				max2 = nxt;
		}
			
		if(max1 != -1 && max2 != -1){
			for(int i=0;i<s;i++){
				int nxt = g[curr].get(i);
				if(nxt == prev)	continue;
				if(nxt == max1)	distUp[nxt] = 2 + distDown[max2];
				else			distUp[nxt] = 2 + distDown[max1];
			}
		}
		
		for(int i=0;i<s;i++){
			int nxt = g[curr].get(i);
			if(nxt == prev)	continue;
			distUp[nxt] = Math.max(distUp[nxt], distUp[curr] + 1);
			dfs2(nxt,curr);
		}
	
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}

/*
 *       1
 *   10     3
 *       5     8
 *     4   7
 *   2 6 9 
 * 
 * 
 */