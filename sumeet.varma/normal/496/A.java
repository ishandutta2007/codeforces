import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class MinDiificulty {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	   
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	         
	    int cur , min = Integer.MAX_VALUE;
	    for(int i=1;i<n-1;i++){
	    	int max = 0;
	    	for(int j=1;j<i;j++){
	    		max = Math.max(max, a[j] - a[j-1]);
	    	}
	    	max = Math.max(max, a[i+1] - a[i-1]);
	    	for(int j=i+2;j<n;j++){
	    		max = Math.max(max, a[j] - a[j-1]);
	    	}
	    	min = Math.min(min, max);
	    }
	    w.println(min);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}