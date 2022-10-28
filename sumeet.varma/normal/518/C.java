import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class AnyaAndSmartphone {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int m = ip(st1.nextToken());
	    int k = ip(st1.nextToken());
	          
	    int pos[] = new int[n+1];
	    int left[] = new int[n+1];
	    int right[] = new int[n+1];
	    
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int prev = 0;
	    for(int i=1;i<=n;i++){
	    	int now = ip(st2.nextToken());
	    	right[prev] = now;
	    	pos[now] = i;
	    	left[now] = prev;
	    	prev = now;
	    }
	    right[prev] = -1;
	    
	    long ans = 0;
	    StringTokenizer st3 = new StringTokenizer(br.readLine());
	    for(int i=0;i<m;i++){
	    	int curr = ip(st3.nextToken());
	    	
	    	ans += pos[curr]/k;
	    	if(pos[curr] % k != 0)
	    		ans++;
	    	if(left[curr] != 0){
	    		int lc = left[curr];
	    		int rc = right[curr];
	    		int llc = left[left[curr]];
	    		int p = pos[curr];
	    		
	    		pos[curr] = pos[lc];
	    		pos[lc] = p;
	    	
	    		right[lc] = rc;
	    		if(rc != -1)
	    			left[rc] = lc;
	    		left[lc] = curr;
	    		right[curr] = lc;
	    		right[llc] = curr;
	    		left[curr] = llc;
	    		
	    	}
	    	
	    	//System.out.println(pos[curr]);
	    	//System.out.println(ans);
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}