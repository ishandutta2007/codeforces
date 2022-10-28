import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Arrays;


public class R280D2TasbVanyaAndLanterns {

public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int l = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	         
	    Arrays.sort(a);
	    
	    double currD = a[0];
	    for(int i=1;i<n;i++){
	    	if(a[i] - currD <= a[i-1] + currD)
	    		continue;
	    	else{
	    		currD = (a[i] - a[i-1]) / 2.0;
	    	}
	    }
	    
	    currD = Math.max(currD , l - a[n-1]);
	    w.println(currD);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}