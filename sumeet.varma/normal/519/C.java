import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class AAndBTeamMaking {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int m = ip(st1.nextToken());
	          
	    int teams = 0;
	    
	    while(n!=0 || m!=0){
	    	if(n <= m){
	    		if(n>=1 && m>=2){
	    			teams++;
	    			n--;
	    			m -= 2;
	    		}
	    		else{
	    			n = m = 0;
	    		}
	    	}
	    	else{
	    		if(m>=1 && n>=2){
	    			teams++;
	    			m--;
	    			n -= 2;
	    		}
	    		else
	    			n = m = 0;
	    	}
	    }
	    
	    w.println(teams);
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}