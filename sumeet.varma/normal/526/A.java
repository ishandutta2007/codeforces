import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class TaskA {

	static int n;
	static char a[];
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		
	    a = br.readLine().toCharArray();
	    
	    boolean found = false;
	    for(int i=0;i<n;i++){
	    	if(a[i] == '*'){
	    		for(int len = 1;len < n-i;len++){
	    			if(g(i+len) && g(i+2*len) && g(i+3*len) && g(i+4*len))
	    				found = true;
	    		}
	    	}
	    }
	    
	    w.println(found ? "yes" : "no");
	    w.close(); 
	}
	
	public static boolean g(int i){
		if(i >= n)
			return false;
		if(i< 0 )
			return false;
		if(a[i] == '*')
			return true;
		if(a[i] == '.')
			return false;
		return false;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	public static long lp(String s){
		return Long.parseLong(s);
	}
}