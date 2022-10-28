import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R280D2TaskAVanyaAndCubes {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    long total = 0;
	    long curr = 0;
	    
	    while(true){
	    	total += (curr+1)*(curr+2) / 2;
	    	if(total > n)
	    		break;
	    	else
	    		curr++;
	    }
	     
	    w.print(curr);
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}