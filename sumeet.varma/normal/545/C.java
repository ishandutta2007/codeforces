import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R303qC {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    int x[] = new int[n];
	    int h[] = new int[n];
	    
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	x[i] = ip(st2.nextToken());
	    	h[i] = ip(st2.nextToken());
	    }
	    
	    int ans = 1;
	    int prev = x[0];
	    for(int i=1;i<n;i++){
	    	if(x[i] - h[i] > prev){
	    		prev = x[i];
	    		ans++;
	    	}
	    	else{
	    		if(i == n-1 || (x[i] + h[i]) < x[i+1]){
	    			ans++;
	    			prev = x[i] + h[i];
	    		}
	    		else
	    			prev = x[i];
	    	}
	    }
	    
	    int ans2 = 1;
	    int next = x[n-1];
	    for(int i=n-2;i>=0;i--){
	    	if(x[i] + h[i] < next){
	    		next = x[i];
	    		ans2++;
	    	}
	    	else{
	    		if(i == 0 || (x[i] - h[i]) > x[i-1]){
	    			ans2++;
	    			next = x[i] - h[i];
	    		}
	    		else
	    			next = x[i];
	    	}
	    }
	    
	    w.println(Math.max(ans, ans2));
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}