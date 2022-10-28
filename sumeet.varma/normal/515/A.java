import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class TaskBRound291Div2 {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    long a = Math.abs(ip(st1.nextToken()));
	    long b = Math.abs(ip(st1.nextToken()));
	    long s = ip(st1.nextToken());
	    
	    if(s<a+b)
	    	w.println("No");
	    if(s==a+b)
	    	w.println("Yes");
	    if(s>(a+b)){
	    	if((s-(a+b)) % 2 == 0)
	    		w.println("Yes");
	    	else{
	    		w.println("No");
	    	}
	    }
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}