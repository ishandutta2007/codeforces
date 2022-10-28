import java.io.*;
import java.util.*;

public class R234QDDimaAndBacteria {

	static int oo = Integer.MAX_VALUE;
			
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int m = ip(st1.nextToken());
		int k = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int c[] = new int[k];
	    for(int i=0;i<k;i++)
	    	c[i] = ip(st2.nextToken());
	
	    int a[] = new int[n];
	    int l=0;
	    for(int i=0;i<k;i++)
	    	for(int j=0;j<c[i];j++)
	    		a[l++] = i;
	    
	    int dist[][] = new int[k][k];
	    for(int i=0;i<k;i++)
	    	for(int j=0;j<k;j++)
	    		dist[i][j] = (i == j) ? 0 : oo;
	    
	    ArrayList<Integer> g[] = new ArrayList[n];
	    for(int i=0;i<n;i++)
	    	g[i] = new ArrayList<Integer>();
	    
	    for(int i=0;i<m;i++){
	    	StringTokenizer st3 = new StringTokenizer(br.readLine());
	    	int u = ip(st3.nextToken())-1;
	    	int v = ip(st3.nextToken())-1;
	    	int x = ip(st3.nextToken());
	    	if(x == 0){
		    	g[u].add(v);
		    	g[v].add(u);
	    	}
	    	dist[a[u]][a[v]] = Math.min(dist[a[u]][a[v]],x);
	    	dist[a[v]][a[u]] = Math.min(dist[a[v]][a[u]],x);
	    }
	    	
	   
	    boolean yes = true;
	    
	    boolean vis[] = new boolean[n];
	    int setIndex[] = new int[n];
	    int totalSet = 0;
	    
	    for(int i=0;i<n;i++){
	    	if(!vis[i]){
	    		vis[i] = true;
	    		Queue<Integer> q = new LinkedList<Integer>();
	    		q.add(i);
	    		setIndex[i] = ++totalSet;
	    		while(!q.isEmpty()){
	    			int curr = q.remove();
	    			int s = g[curr].size();
	    			for(int b=0;b<s;b++){
	    				int nxt = g[curr].get(b);
	    				if(!vis[nxt]){
	    					vis[nxt] = true;
	    					setIndex[nxt] = totalSet;
	    					q.add(nxt);
	    				}
	    			}
	    		}
	    	}
	    }
	    
	    l = 0;
	    for(int i=0;i<k;i++){
	    	int id = setIndex[l];
	    	for(int j=0;j<c[i];j++){
	    		if(setIndex[l++] != id)
	    			yes = false;
	    	}
	    }
	    
	    if(yes){
	    	w.println("Yes");
	    	
	    	//Floyd-Warshall
	    	for(int x=0;x<k;x++){
	    		for(int y=0;y<k;y++){
	    			for(int z=0;z<k;z++){
	    				if(dist[y][x] != oo && dist[x][z] != oo)
	    					dist[y][z] = Math.min(dist[y][z],dist[y][x] + dist[x][z]);
	    			}
	    		}
	    	}
	    	for(int i=0;i<k;i++){
	    		for(int j=0;j<k;j++)
	    			w.print(dist[i][j] == oo ? "-1 " : (dist[i][j] + " "));
	    		w.println();
	    	}
	    }
	    else
	    	w.println("No");
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}