import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class R2775LengthAndSumOfDigits {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int m = ip(st1.nextToken());
		int s = ip(st1.nextToken());
	    int t = s;
	    
	    if(m == 1){
	    	if(s >=0 && s<=9)
	    		System.out.println(s + " " + s);
	    	else
	    		System.out.println("-1 -1");
	    	return;
	    }
	    
		if(s < 1 || s > 9*m){
			System.out.println("-1 -1");
			return;
		}
	    
		int big[] = new int[m];
		for(int i=0;i<m;i++){
			int rem = 0;
			big[i] = Math.min(s - rem,9);
			s -= big[i];
		}
		
		s = t;
		int small[] = new int[m];
		
		int rem0 = 9*(m-1);
		small[0] = Math.max(1,s-rem0);
		s -= small[0];
		
		for(int i=1;i<m;i++){
			int rem = 9 * (m - 1 - i);
			small[i] = Math.max(0, s - rem);
			s -= small[i];
		}
		
		for(int i=0;i<m;i++)
			w.print(small[i]);
		w.print(" ");
		for(int i=0;i<m;i++)
			w.print(big[i]);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}