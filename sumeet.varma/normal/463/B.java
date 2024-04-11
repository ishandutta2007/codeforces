import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class CaisaAndPylons {

public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n+1];
	    for(int i=1;i<=n;i++)
	    	a[i] = ip(st2.nextToken());
	    
	    int curr = 0;
	    int ans = 0;
	    
	    for(int i=1;i<=n;i++){
	    	curr -= a[i] - a[i-1];
	    	if(curr < 0 ){
	    		ans += -1*curr;
	    		curr = 0;
	    	}
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}