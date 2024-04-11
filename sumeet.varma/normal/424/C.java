import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R242TCMagicFormulaes {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    int xors[] = new int[n+1];
	    xors[0] = 0;
	    for(int i=1;i<=n;i++)
	    	xors[i] = i ^ xors[i-1];
	    
	    int ans = 0;
	    for(int i=1;i<=n;i++){
	    	int cycles = n/i;
	    	if(cycles % 2 != 0)
	    		ans = ans ^ xors[i-1];
	    	int rem = n % i;
	    	ans = ans ^ xors[rem];
	    }
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    for(int i=0;i<n;i++)
	    	ans = ans ^ ip(st2.nextToken());
	        
	    w.print(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	public static long lp(String s){
		return Long.parseLong(s);
	}
}