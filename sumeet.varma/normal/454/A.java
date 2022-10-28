import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Round259QALittlePonyAndCrystal {

	@SuppressWarnings("unused")
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    int count = 1;
	    boolean up = true;
	    for(int i=1;i<=n;i++){
	    	int left = n - count;
	    	for(int j=0;j<left/2;j++)
	    		w.print('*');
	    	for(int j=1;j<=count;j++)
	    		w.print('D');
	    	for(int j=0;j<left/2;j++)
	    		w.print('*');
	    	if(up)
	    		count += 2;
	    	else
	    		count -= 2;
	    	if(count == n)
	    		up = false;
	    	w.println();
	    }
	        
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}