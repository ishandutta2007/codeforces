import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R305qD {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    int max = 5000000 + 1;
	    
	    int fact[] = new int[max];
	    
	    for(int i=2;i<max;i++){
	    	int t = i/2;
	    	if(t*2 == i){
	    		fact[i] = fact[t] + 1;
	    		continue;
	    	}
	    	for(int j=3;j*j<=i;j+=2){
	    		t = i/j;
	    		if(t*j == i){
	    			fact[i] = fact[t] + 1;
	    			break;
	    		}
	    	}
	    	if(fact[i] == 0)
	    		fact[i] = 1;
	    }
	
	    long pre[] = new long[max];
	    for(int i=2;i<max;i++)
	    	pre[i] = pre[i-1] + fact[i];
	    
	    int t = ip(br.readLine());
	    
	    while(t-- > 0){
	    	StringTokenizer st1 = new StringTokenizer(br.readLine());
	    	int a = ip(st1.nextToken());
	    	int b = ip(st1.nextToken());
	    	w.println(pre[a] - pre[b]);
	    }
	        
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}