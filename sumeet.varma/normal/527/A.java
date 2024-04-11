import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class TaskA {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    long a = Long.parseLong(st1.nextToken());
	    long b = Long.parseLong(st1.nextToken());
	   
	    long ans = 0;
	    
	    while(a!=0 && b!=0){
	    	if(b > a){
	    		long t = a;
	    		a = b;
	    		b = t;
	    	}
	    	//now a > b
	    	ans += a/b;
	    	a -= b*(a/b);
	    }
	
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}