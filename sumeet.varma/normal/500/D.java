//package Practise.GoodBye2014;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class NewYearSantaNetwork {

	static int subtree[],a[],b[],l[];
	static int n;
	static ArrayList<Integer> g[];
	static long ans;
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter p = new PrintWriter(System.out);
	        
	    n = ip(br.readLine());
	          
	    a = new int[n + 1];
	    b = new int[n + 1];
	    l = new int[n + 1];
	    
	    g = new ArrayList[n + 1];
	    for(int i=1;i<=n;i++)
	    	g[i] = new ArrayList<Integer>();
	    
	    
	    for(int i=1;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	a[i] = ip(st2.nextToken());
	    	b[i] = ip(st2.nextToken());
	    	l[i] = ip(st2.nextToken());
	    	g[a[i]].add(b[i]);
	    	g[b[i]].add(a[i]);
	    }
	    
	    //create a tree rooted at 1
	    subtree = new int[n+1];
	    findSubtree(1,0);
	    
	    ans = 0;
	    for(int i=1;i<=n;i++){
	    	int nn = Math.min(subtree[a[i]], subtree[b[i]]);
	    	ans += nn * 1L * (n - nn) * l[i];
	    }
	   
	    
	    int Q = ip(br.readLine());
	    
	    for(int q=0;q<Q;q++){
	    	StringTokenizer st3 = new StringTokenizer(br.readLine());
	    	int r = ip(st3.nextToken());
	    	int w = ip(st3.nextToken());
	    	int nn = Math.min(subtree[a[r]], subtree[b[r]]);
	    	ans -= nn * 1L * (n - nn) * (l[r] - w);
	    	l[r] = w;
	    	p.println(ans * 6.0 / (n * 1L *(n-1)));
	    }
	    
	    p.close(); 
	}
	
	public static int findSubtree(int curr,int parent){
		subtree[curr] = 1;
		int s = g[curr].size();
		for(int i=0;i<s;i++)
			if(g[curr].get(i) != parent)
				subtree[curr] += findSubtree(g[curr].get(i),curr);
		return subtree[curr];
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}