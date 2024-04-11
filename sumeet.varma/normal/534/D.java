import java.io.*;
import java.util.*;

public class R298D2TD {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	    
	    TreeMap<Integer,Integer> g[] = new TreeMap[3];
	    for(int i=0;i<3;i++){
	    	g[i] = new TreeMap<Integer,Integer>();
	    	g[i].put(-1, -1);
	    }
	    for(int i=0;i<n;i++){
	    	if(g[a[i] % 3].containsKey(a[i]))
	    		g[a[i] % 3].put(a[i],g[a[i] % 3].get(a[i]) + 1);
	    	else
	    		g[a[i] % 3].put(a[i],1);
	    }
	    
	    int ans[] = new int[n];
	    int prev = -1;
	    for(int i=0;i<n;i++){
	    	if(g[i % 3].containsKey(prev + 1)){
	    		ans[i] = prev + 1;
	    		int count = g[i % 3].get(prev + 1);
	    		if(count == 1)
	    			g[i % 3].remove(prev + 1);
	    		else
	    			g[i % 3].put(prev + 1, count - 1);
	    		prev++;
	    	}
	    	else{
	    		int key = g[i % 3].floorKey(prev + 1);
	    		if(key == -1){
	    			System.out.println("Impossible");
	    			return;
	    		}
	    		int count = g[i % 3].get(key);
	    		ans[i] = key;
	    		if(count == 1)
	    			g[i % 3].remove(key);
	    		else
	    			g[i % 3].put(key, count - 1);
	    		prev = key;
	    	}
	    }
	    
	    ArrayList<Integer> rev[] = new ArrayList[200010];
	    for(int i=0;i<=200009;i++)
	    	rev[i] = new ArrayList<Integer>();
	    
	    for(int i=0;i<n;i++)
	    	rev[a[i]].add(i);
	    
	    int pt[] = new int[200010];
	    
	    w.println("Possible");
		for(int i=0;i<n;i++)
			w.print((rev[ans[i]].get(pt[ans[i]]++)+1) + " ");
		w.println();
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}

class Pair implements Comparable<Pair>{
	int i,v;
	Pair(int i,int v){
		this.i = i;
		this.v = v;
	}
	@Override
	public int compareTo(Pair arg0) {
		return v - arg0.v;
	}
	
}