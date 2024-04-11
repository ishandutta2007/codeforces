//package Round285Div2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TaskAContest {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int t = 1;
	    
	    while(t-- > 0) {
	    	StringTokenizer st1 = new StringTokenizer(br.readLine());
	    	int a = ip(st1.nextToken());
	    	int b = ip(st1.nextToken());
	    	int c = ip(st1.nextToken());
	    	int d = ip(st1.nextToken());
	    	
	    	int pointsa = Math.max(3*a / 10, a - a*c/250);
	    	int pointsb = Math.max(3*b/10 , b - b*d/250);
	    	
	    	if(pointsa > pointsb)
	    		w.println("Misha");
	    	else if(pointsa < pointsb)
	    		w.println("Vasya");
	    	else
	    		w.println("Tie");
	   	    }
	   	        
	   	    w.close();
	   	        
	   	}
	   	
	   	public static int ip(String s){
	   		return Integer.parseInt(s);
	   	}
}