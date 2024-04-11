import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class R188qAPair {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    long x = lp(st1.nextToken());
	    long y = lp(st1.nextToken());
	    long m = lp(st1.nextToken());
	    
	    if(x >= m || y >= m){
	    	System.out.println(0);
	    	return;
	    }
	        
	    if(x <= 0 && y <= 0){
	    	System.out.println(-1);
	    	return;
	    }
	    
	    if(x >= 0 && y >= 0){
	    	System.out.println(orange(x,y,m));
	    	return;
	    }
	    
	    if(x >= 0 && y < 0){
	    	long t = (long)Math.ceil(-1.0*y / x);
	    	y += t*x;
	    	System.out.println(t + orange(x,y,m));
	    	return;
	    }
	    
	    if(x < 0 && y >= 0){
	    	long t = (long)Math.ceil(-1.0*x / y);
	    	x += t*y;
	    	System.out.println(t + orange(x,y,m));
	    	return;
	    }
	    
	    throw new Exception();
	}
	
	public static long orange(long x,long y,long m){
		if(x >= m || y >= m)	return 0;
		if(x < y)
			return 1 + orange(x+y,y,m);
		else
			return 1 + orange(x,x+y,m);
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	public static long lp(String s){
		return Long.parseLong(s);
	}
	
}