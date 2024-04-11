import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class ZeptoLab2014qCDungeonsAndCandies {

	static ArrayList<Integer> g[];
	static PrintWriter p;
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    p = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	    int k = ip(st1.nextToken());
	    int w = ip(st1.nextToken());
	    
	    char level[][][] = new char[k+1][n][m];
	    for(int i=1;i<=k;i++)
	    	for(int j=0;j<n;j++)
	    		level[i][j] = br.readLine().toCharArray();
	    
	    Edge e[] = new Edge[k*(k+1)/2];
	    
	    int c = 0;
	    for(int i=1;i<=k;i++)
	        e[c++] = new Edge(0,i,n*m);
	    
	    for(int i=1;i<=k;i++){
	    	for(int j=i+1;j<=k;j++){
	    		int d = 0;
	    		for(int x=0;x<n;x++)
	    			for(int y=0;y<m;y++)
	    				if(level[i][x][y] != level[j][x][y])
	    					d++;
	    		e[c++] = new Edge(i,j,w*d);
	    	}
	    }
	    
	    Arrays.sort(e);
	    //System.out.println(Arrays.deepToString(e) + " " + c);
	    
		g = new ArrayList[k+1];
	    for(int i=0;i<=k;i++)
	    	g[i] = new ArrayList<Integer>();
	    
	    DisjointSet ds = new DisjointSet(k+1);
	    
	    int added = 0,ans = 0;
	    for(int i=0;i<c && added <k;i++){
	    	if(ds.find(e[i].u) != ds.find(e[i].v)){
	    		ds.merge(e[i].u,e[i].v);
	    		g[e[i].u].add(e[i].v);
	    		g[e[i].v].add(e[i].u);
	    		ans += e[i].weg;
	    		added++;
	    	}
	    }
	    
	    p.println(ans);
	    dfs(0,-1);
	    
	    p.close(); 
	}
	
	public static void dfs(int curr,int prev){
		int s = g[curr].size();
		for(int i=0;i<s;i++){
			int nxt = g[curr].get(i);
			if(nxt == prev)	continue;
			p.println(nxt + " " + curr);
			dfs(nxt,curr);
		}
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	static public class Edge implements Comparable<Edge> {
		int u,v,weg;
		Edge(int u,int v,int weg){
			this.u = u;
			this.v = v;
			this.weg = weg;
		}
		public int compareTo(Edge o){
			return Integer.compare(weg, o.weg);
		}
		public String toString(){
			return u + " " + v + " " + weg;
		}
	}
	

	static public class DisjointSet {

		public int rank[],parent[];
		public int n;
		
		public DisjointSet(int n){
		    this.n = n;
			makeSet();
		}
		
		public void makeSet(){
			rank = new int[n];
			parent = new int[n];
			for(int i=0;i<n;i++)
				parent[i] = i;
		}
		
		public int find(int x){
			if(parent[x] != x)
				parent[x] = find(parent[x]);
			return parent[x];
		}
		
		public void merge(int x,int y){
			int xRoot = find(x);
			int yRoot = find(y);
			
			if(xRoot == yRoot)
				return;
			
			if(rank[xRoot] < rank[yRoot])
				parent[xRoot] = yRoot;
			else{
				parent[yRoot] = xRoot;
				if(rank[xRoot] == rank[yRoot]){
					parent[yRoot] = xRoot;
					rank[xRoot]++;
				}
			}
		}
	
	}
	
}