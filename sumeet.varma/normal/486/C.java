import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class PalindromeTransformation {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int p = ip(st1.nextToken())-1;
	          
	    char a[] = br.readLine().toCharArray();
	    int ans = 0;
	    
	    if(p<n/2){
	    	int rightadd = 0;
	    	
	    	for(int i=p;i<n/2;i++){
	    		if(a[i] > a[n-1-i]){
	    			ans += Math.min(a[i]-a[n-1-i],26+a[n-1-i]-a[i]);
	    			rightadd = i-p;
	    		}
	    		else if (a[i] < a[n-1-i]){
	    			ans += Math.min(a[n-1-i]-a[i],26+a[i]-a[n-1-i]);
	    			rightadd = i-p;
	    		}
	    	}
	    	
	    	int leftadd = 0;
	    	
	    	for(int i=p-1;i>=0;i--){
	    		if(a[i] > a[n-1-i]){
	    			ans += Math.min(a[i]-a[n-1-i],26+a[n-1-i]-a[i]);
	    			leftadd = p-i;
	    		}
	    		else if (a[i] < a[n-1-i]){
	    			ans += Math.min(a[n-1-i]-a[i],26+a[i]-a[n-1-i]);
	    			leftadd = p-i;
	    		}
	    	}
	    	
	    	ans += Math.min(leftadd, rightadd)  + leftadd + rightadd;
	    }
	    else{
	    	
	    	int rightadd = 0;
	    	
	    	for(int i=p;i<n;i++){
	    		if(a[i] > a[n-1-i]){
	    			ans += Math.min(a[i]-a[n-1-i],26+a[n-1-i]-a[i]);
	    			rightadd = i-p;
	    		}
	    		else if (a[i] < a[n-1-i]){
	    			ans += Math.min(a[n-1-i]-a[i],26+a[i]-a[n-1-i]);
	    			rightadd = i-p;
	    		}
	    	}
	    	
	    	int leftadd = 0;
	    	
	    	for(int i=p-1;i>=n/2;i--){
	    		if(a[i] > a[n-1-i]){
	    			ans += Math.min(a[i]-a[n-1-i],26+a[n-1-i]-a[i]);
	    			leftadd = p-i;
	    		}
	    		else if (a[i] < a[n-1-i]){
	    			ans += Math.min(a[n-1-i]-a[i],26+a[i]-a[n-1-i]);
	    			leftadd = p-i;
	    		}
	    	}
	    	
	    	ans += Math.min(leftadd, rightadd)  + leftadd + rightadd;
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}