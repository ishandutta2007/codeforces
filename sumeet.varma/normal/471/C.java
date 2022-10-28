import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R269Div2TaskCHouseofCards {

	@SuppressWarnings("unused")
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    long n = Long.parseLong(st1.nextToken());
	    
	    long t = 2;
	    
	    int count = 0;
	    int j = 1;
	    
	    while(t <= n){
	    	j++;
	    	if((n-t) % 3 == 0)
	    		count++;
	    	t += 3L*j - 1;
	    }
	         
	    w.println(count);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}