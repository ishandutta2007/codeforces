//package Round266Div2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class WonderRoom {

public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    long n = ip(st1.nextToken());
		long c = ip(st1.nextToken());
	    long d = ip(st1.nextToken());      
	   
	    long a = Math.min(c, d);
	    long b = Math.max(c, d);
	    
	    long e = a;
	    long f = b;
	    
	    long s = a*b;
	    
	    if(s < 6*n){
	    	boolean first = true;
	    	long area = 6*n;
	    	
	    	for(long i=a;i*i<=area;i++){
	    		long other = (long)Math.ceil(area*1.0/i);
	    		if(i >= e && other >= f){
	    		if(i*other < s || first){
	    			s = i*other;
	   				a = i;
	   				b = other;
	   				first = false;
	    		}
	    		}
	    	}
	    
	    }
	    
	    w.println(s);
	    if(a < c){
	    	long t = a;
	    	a = b;
	    	b = t;
	    }
	    
	    w.println(a + " " + b);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}