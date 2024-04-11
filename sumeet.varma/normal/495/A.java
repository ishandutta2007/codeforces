import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class DigitalCounter {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int t = 1;
	    int repl[] = new int[10];
	    repl[0] = 2;
	    repl[1] = 7;
	    repl[2] = 2;
	    repl[3] = 3;
	    repl[4] = 3;
	    repl[5] = 4;
	    repl[6] = 2;
	    repl[7] = 5;
	    repl[8] = 1;
	    repl[9] = 2;
	    
	    while(t-- > 0) {
	    	String n = br.readLine();
	    	w.println(repl[n.charAt(0)-'0'] * repl[n.charAt(1) - '0']) ;
	    
	    }
	        
	    w.close();
	        
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}