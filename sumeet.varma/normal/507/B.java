import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class TaskB {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    long r = ip(st1.nextToken());
	    long x1 = ip(st1.nextToken());
	    long y1= ip(st1.nextToken());
	    long x2 = ip(st1.nextToken());
	    long y2 = ip(st1.nextToken());
	    
	    double dis = Math.sqrt((x2 - x1)*(x2 -x1) + (y1-y2)*(y1-y2));
	    long ans = (long) Math.ceil(dis/(2*r));
	    
	    
	    w.println((long) ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}