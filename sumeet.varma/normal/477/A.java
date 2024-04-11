import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class DreamoonAndSums {

	static long m = (long) (1e9 + 7);
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    long A = ip(st1.nextToken());
	    long B = ip(st1.nextToken());
	        
	    long ans = 0;
	    for(long r=1;r<B;r++){
	    	long a = (r*B + r)%m;
	    	long n = A;
	    	long d = (r*B)%m;
	    	long sum = ( ((n*a)%m) + ( ((n*(n-1)/2)%m)*d )%m  ) % m;
	    	ans = (ans + sum) % m;
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}