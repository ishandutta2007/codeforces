import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class GuessYouWayOut {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    long h = Long.parseLong(st1.nextToken());
	    long n = Long.parseLong(st1.nextToken());
	          
	    long ans = solve(h,n,true);
	    w.println(ans-1);
	    w.close(); 
	}
	
	public static long solve(long h,long n,boolean direction){
		//System.out.println(h + " " + n);
		
		if(h==0)
			return 1;
		
		long total = (long)Math.pow(2,h+1) - 1;
		long lastlevel = (long)Math.pow(2, h);
		
		if(direction){
			if(n<=lastlevel/2)
				return 1 + solve(h-1,n,!direction);
			else
				return 1 + total/2 + solve(h-1,n - (long)Math.pow(2,h-1),direction);
		}
		else{
			if(n<=lastlevel/2)
				return 1 + total/2 + solve(h-1,n,direction);
			else
				return 1 + solve(h-1,n - (long)Math.pow(2,h-1),!direction);
		}
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}