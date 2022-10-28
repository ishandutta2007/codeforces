import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R97TaskC {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int count[] = new int[1000001];
	    for(int i=0;i<n;i++)
	    	count[ip(st2.nextToken())]++;
	    
	    long ans = 0;
	    long pair = -1;
	  
	    for(int i=1000000;i>0;i--){
	    	if(pair == -1){
	    		 ans += 1L*(count[i]/4)*i*i;
	    	    	count[i] -= 4*(count[i]/4);
	    		
	    		 if(count[i] % 2 == 1){
	    			  if(count[i-1] > 0)
	    				  count[i-1]++;
	    		       count[i]--;
	    		  }
	    		  if(count[i] == 2)
	    		   	pair = i;
	    	}
	    	else{
	    		if(count[i] >= 2){
	    			ans += 1L*pair*i;
	    			count[i] -= 2;
	    			pair = -1;
	    			i++;
	    		}
	    		else if(count[i] == 1){
	    			if(count[i-1] > 0){
	    				count[i-1]++;
	    				count[i] = 0;
	    			}
	    		}
	    	}
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}