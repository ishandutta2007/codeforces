import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.ArrayList;

public class R225QEPropogatingTree {

	static ArrayList<Integer> g[];
	static int n,m;
	static int a[],discovery[],begin[],end[],rev[],level[],aux[];
	static int segtree[];
	static int time,count;
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		m = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
		g = new ArrayList[n];
	    for(int i=0;i<n;i++)
	    	g[i] = new ArrayList<Integer>();
	    
	    for(int i=1;i<n;i++){
	    	StringTokenizer st3 = new StringTokenizer(br.readLine());
	    	int v = ip(st3.nextToken()) - 1;
	    	int u = ip(st3.nextToken()) - 1;
	    	g[u].add(v);
	    	g[v].add(u);
	    }
	    
	    discovery = new int[n];
	    begin = new int[n];
	    end = new int[n];
	    level = new int[n];
	    aux = new int[n];
	    time = -1;
	    count = 0;
	    level[0] = 0;
	    dfs(0,-1);
	    
	   // System.out.println(Arrays.toString(discovery));
	   // System.out.println(Arrays.toString(begin));
	   // System.out.println(Arrays.toString(end));
	   // System.out.println(Arrays.toString(level));
	    rev = new int[n];
	    for(int i=0;i<n;i++)
	    	rev[discovery[i]] = i;
	    
	   // System.out.println(Arrays.toString(rev));
	    segtree = new int[4*n];
	    
	    for(int i=1;i<=m;i++){
	    	StringTokenizer st4 = new StringTokenizer(br.readLine());
	    	int type = ip(st4.nextToken());
	    	int x = ip(st4.nextToken()) - 1;
	    	
	    	if(type == 1){
	    		int val = ip(st4.nextToken());
	    		if(level[x] % 2 != 0)
	    			val *= -1;
	    		update(0,n-1,0,begin[x],val);
	    		if(end[x] + 1 != n)
	    			update(0,n-1,0,end[x] + 1,-1*val);
	    	}
	    	
	    	else{
	    		int ans = find(0,n-1,0,0,rev[x]);
	    		w.println(a[x] +( (level[x] % 2 == 0) ? ans : -1*ans));
	    	}
	    	
	    }
	    
	   // System.out.println(Arrays.toString(segtree));
	
	    
	    w.close(); 
	}
	
	public static void dfs(int curr,int parent){
		int s = g[curr].size();
		time++;
		discovery[count++] = curr; 
		begin[curr] = time;
		
		for(int i=0;i<s;i++){
			int nxt = g[curr].get(i);
			if(nxt != parent){
				level[nxt] = level[curr] + 1;
				dfs(nxt,curr);
			}
		}
		
		end[curr] = time;
	}
	
	public static void update(int s,int e,int c,int x,int val){
		if(s == e){
			segtree[c] += val;
			aux[s] += val;
			return;
		}
		int m = (s + e) / 2;
		if(x <= m)
			update(s,m,2*c+1,x,val);
		else
			update(m+1,e,2*c+2,x,val);
		segtree[c] += val;
	}
	
	public static int find(int s,int e,int c,int l,int r){
		if(s == l && e == r )
			return segtree[c];
		int m = (s + e) / 2;
		if(l <= m && r <= m)
			return find(s,m,2*c+1,l,r);
		if(l > m && r > m)
			return find(m+1,e,2*c+2,l,r);
		return find(s,m,2*c+1,l,m) + find(m+1,e,2*c+2,m+1,r);
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}