import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R304qA {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	   // PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int k = ip(st1.nextToken());
		int n = ip(st1.nextToken());
	    int w = ip(st1.nextToken());     
		
	    long need = w * 1L * (w + 1) * k / 2;
	      
	    System.out.println(Math.max(0,need - n));
	    
	    //w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}