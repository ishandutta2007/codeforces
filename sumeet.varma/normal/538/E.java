//package Round300Div12;

import java.io.*;
import java.util.*;

public class R300qE {

	static int n;
	static ArrayList<Integer> g[];
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    n = ip(br.readLine());
	    
	    g = new ArrayList[n+1];
	    for(int i=1;i<=n;i++)
	    	g[i] = new ArrayList<Integer>();
	    
	    for(int i=1;i<n;i++){
	    	StringTokenizer st = new StringTokenizer(br.readLine());
	    	int u = ip(st.nextToken());
	    	int v = ip(st.nextToken());
	    	g[u].add(v);
	    }
	    
	    int m = 0;
	    for(int i=1;i<=n;i++)
	    	if(g[i].isEmpty())
	    		m++;
	    
	    w.println((m - solveMax(1,true) + 1) + " " + solveMin(1,true));
	    w.close(); 
	}
	
	public static int solveMax(int curr,boolean level){
		int s = g[curr].size();
		if(s == 0)	return 1;
		if(level == true){
			int min = n;
			for(int j=0;j<s;j++)
				min = Math.min(min,solveMax(g[curr].get(j),false));
			return min;
		}
		else{
			int sum = 0;
			for(int j=0;j<s;j++)
				sum += solveMax(g[curr].get(j),true);
			return sum;
		}
	}
	
	public static int solveMin(int curr,boolean level){
		int s = g[curr].size();
		if(s == 0)	return 1;
		if(level == true){
			int sum = 0;
			for(int j=0;j<s;j++)
				sum += solveMin(g[curr].get(j),false);
			return sum;
		}
		else{
			int min = n;
			for(int j=0;j<s;j++)
				min = Math.min(min,solveMin(g[curr].get(j),true));
			return min;
		}
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}