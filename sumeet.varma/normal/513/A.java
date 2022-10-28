import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Game {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n1 = ip(st1.nextToken());
	    int n2 = ip(st1.nextToken());
	    int k1 = ip(st1.nextToken());
	    int k2 = ip(st1.nextToken());
	    
	    if(n1>n2)
	    	w.println("First");
	    else
	    	w.println("Second");
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}