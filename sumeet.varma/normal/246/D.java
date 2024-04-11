import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;


public class R151qDColorfulGraph {

	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	    
		final int MAX = 100001;
	    Set<Integer> set[] = new HashSet[MAX];
	    for(int i=1;i<MAX;i++)
	    	set[i] = new HashSet<Integer>();
	    
	    boolean der[] = new boolean[MAX];
	   
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int c[] = new int[n+1];
	    for(int i=1;i<=n;i++){
	    	c[i] = ip(st2.nextToken());
	    	der[c[i]] = true;
	    } 
	    
	    for(int i=0;i<m;i++){
	    	StringTokenizer st = new StringTokenizer(br.readLine());
	    	int u = ip(st.nextToken());
	    	int v = ip(st.nextToken());
	    	if(c[u] != c[v]){
	    		set[c[u]].add(c[v]);
	    		set[c[v]].add(c[u]);
	    	}
	    }
	    
	    int ans = -1,index = -1;
	    
	    for(int i=1;i<MAX;i++){
	    	if(der[i]){
	    		int s = set[i].size();
	    		if(s > ans){
	    			ans = s;
	    			index = i;
	    		}
	    	}
	    }
	    
	    w.println(index);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}