import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R258D2TaskCPredictOutcomeOfTheGame {
	
	static long n,k;
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int t = ip(br.readLine());
	    
	    for(int q=0;q<t;q++){
		    StringTokenizer st1 = new StringTokenizer(br.readLine());
		    n = lp(st1.nextToken());
			k = lp(st1.nextToken());
		    long d1 = lp(st1.nextToken());
		    long d2 = lp(st1.nextToken());
		    
		    boolean ans = false;
		    	
		    ans = ans | solve(0,d1,d1+d2);
		    ans = ans | solve(0,d1,d1-d2);
		    ans = ans | solve(d1,0,d2);
		    ans = ans | solve(d2+d1,d2,0);
		    ans = ans | solve(d2-d1,d2,0);
		    
		    w.println(ans ? "yes" : "no");
	    }
	    
	    w.close(); 
	}

	public static boolean solve(long t1,long t2,long t3){
		if(t1 < 0 || t2 < 0 || t3 < 0)	return false;
		if((t1 + t2 +t3) > k)	return false;
		if((k - (t1 + t2 + t3)) % 3 != 0)	return false;
		long max = Math.max(t1, Math.max(t2,t3));
		long needed = 3*max - t1 - t2 - t3;
		long der = n - k;
		if(needed > der)	return false;
		long waste = der - needed;
		if(waste % 3 != 0)	return false;
		return true;
	}
	
	public static long lp(String s){
		return Long.parseLong(s);
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}