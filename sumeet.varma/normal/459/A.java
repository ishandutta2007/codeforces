import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R261D2TAPashmakAndGarden {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int x1 = ip(st1.nextToken());
		int y1 = ip(st1.nextToken());
	    int x2 = ip(st1.nextToken());
	    int y2 = ip(st1.nextToken());
	    
	    if(x1 == x2){
	    	w.println( (x1 + Math.abs(y1 - y2)) + " " + y1 + " " + (x2 + Math.abs(y1 - y2)) + " " + y2);
	    }
	    else if(y1 == y2){
	    	w.println( x1 + " " + (y1 + Math.abs(x1 - x2)) + " " + x2 + " " + (y2 + Math.abs(x1 - x2)));
	    }
	    else{
	    	if(Math.abs(x1 - x2) != Math.abs(y1 - y2))
	    		w.println("-1");
	    	else
	    		w.println(x2 + " " + y1 + " " + x1 + " " + y2);
	    }
	         
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}