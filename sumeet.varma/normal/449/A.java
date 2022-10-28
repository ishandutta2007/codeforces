import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class JzzhuAndChocolatesR257 {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int m = ip(st1.nextToken());
	    int k = ip(st1.nextToken());
	          
	    long ans = 0;
	     
	    if(n < m){
	    	int t = m;
	    	m = n;
	    	n = t;
	    }
	    
	    //now m <= n
	    
	   if( k < m)
		   ans = n * 1L * (m * 1L / (k+1));
	   else if( k <= (m+n-2))
		   ans = (n * 1L / (k+2-m));
	   else
		   ans = -1;
	   
	   int t = m;
	   m = n;
	   n = t;
	   
	   long ans2 = 0;
	   if( k < m)
		   ans2 = n * 1L * (m * 1L / (k+1));
	   else if( k <= (m+n-2))
		   ans2 = (n * 1L / (k+2-m));
	   else
		   ans2 = -1;
	   
	   ans = Math.max(ans, ans2);
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}