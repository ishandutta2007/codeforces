import java.io.*;
import java.util.*;

public class R298D2TC {

public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		long A = Long.parseLong(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int d[] = new int[n];
	    for(int i=0;i<n;i++)
	    	d[i] = ip(st2.nextToken());
	        
	    long sum = 0;
	    for(int i : d)
	    	sum += i;
	    
	   long b[] = new long[n];
	    
	    for(int i=0;i<n;i++){
	    	long otherMax = sum - d[i];
	    	if(otherMax < A){
	    		b[i] = A - otherMax - 1;
	    	}
	    	int otherMin = n-1;
	    	b[i] += Math.max(0, d[i] + otherMin - A);
	    }
	    
	    for(int i=0;i<n;i++)
	    	w.print(b[i] + " ");
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}