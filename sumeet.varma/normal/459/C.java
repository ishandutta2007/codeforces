import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R261D2TCPashmakAndBuses {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int k = ip(st1.nextToken());
	    int d = ip(st1.nextToken());
	         
	    if(d == 1){
	    	if(n > k)
	    		w.println("-1");
	    	else{
	    		for(int i=1;i<=n;i++)
	    			w.print(i + " ");
	    	}
	    }
	    else{
	    	int ans[][] = new int[n][d];
	    	if(k >= n){
	    		for(int i=0;i<n;i++)
	    			Arrays.fill(ans[i], i+1);
	    	}
	    	else{
	    		if(k == 1){
	    			if(n > 1){
	    				w.println("-1");
	    				w.close();
	    				return;
	    			}
	    			else
	    				Arrays.fill(ans[0], 1);
	    		}
	    		else{
	    			Arrays.fill(ans[0],1);
	    			for(int i=1;i<n;i++){
	    				if(next_perm(ans[i-1],ans[i],k) == false){
	    					w.println("-1");
	    					w.close();
	    					return;
	    				}
	    			}
	    			
	    		}
	    	}
	    	
	    	for(int i=0;i<d;i++){
	    		for(int j=0;j<n;j++)
	    			w.print(ans[j][i] + " ");
	    		w.println();
	    	}
	    }
	    
	    w.close(); 
	}
	
	public static boolean next_perm(int end[],int start[],int k){
		int n = end.length;
		boolean found = false;
		
		for(int i=n-1;i>=0;i--){
			if(found){
				start[i] = end[i];
			}
			else{
				if(end[i] != k){
					start[i] = end[i] + 1;
					found = true;
				}
				else
					start[i] = 1;
			}
		}
		return found;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}