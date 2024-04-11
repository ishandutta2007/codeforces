import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class ModularEquations {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int t = 1;
	    
	    while(t-- > 0) {
	    	StringTokenizer st1 = new StringTokenizer(br.readLine());
	    	int a = ip(st1.nextToken());
	    	int b = ip(st1.nextToken());
	          
	        if(a==b)
	        	w.println("infinity");
	        else{
	        	if(a>b){
	        		int temp = a-b;
	        		w.println(factors(temp,b));
	        	}
	        	else{
	        		w.println("0");
	        	}
	        }
	    }
	        
	    w.close();
	        
	}
	
	public static int factors(int n,int start){
		int count = 0;
		int i;
		for(i=1;i*i<n;i++)
			if(n%i == 0){
				if(i>start)	count++;
				if(n/i > start)	count++;
			}
		if(i*i == n && i>start)	count++;
		return count;
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}