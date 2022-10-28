import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class InitialBet {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int n = 5;
	    
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    int total = 0;
	    for(int i=0;i<5;i++)
	    	total += a[i];
	    
	    if(total % 5 != 0 || total == 0)
	    	w.print(-1);
	    else{
	    	int bet = total/5;
	    	int diff = 0;
	    	for(int i=0;i<5;i++)
	    		diff += a[i] - bet;
	    	if(diff != 0)
	    		bet = -1;
	    	w.print(bet);
	    	
	    }
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}