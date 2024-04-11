import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Arrays;

public class TableDecorations {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    long c[] = new long[3];
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    for(int i=0;i<3;i++)
	    	c[i] = ip(st1.nextToken());
	    
	    Arrays.sort(c);
	   
	    w.print(solve(c));
	    w.close(); 
	}
	
	public static long solve(long[] c){
		long ans = c[0];
		
		//make c[1] & c[2] as close as possible
		long needed = 2 * ans;
		long diff = c[2] - c[1];
		if(diff <= needed)
			ans += (c[1] + c[2] - needed) / 3 ;
		else{
			c[2] -= needed;
			ans += Math.min(c[1], (c[1] + c[2]) / 3);
		}
		return ans;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}