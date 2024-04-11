import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class TaskA {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	   	int k = ip(st1.nextToken());
	     
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[][] = new int[k+1][n];
	    for(int i=0;i<n;i++){
	    	a[1][i] = ip(st2.nextToken());
	    	for(int j=2;j<=k;j++)
	    		a[j][i] = j * a[1][i];
	    }
	    
	    int Q = ip(br.readLine());
	   
	    for(int q = 0;q<Q;q++){
	    	int	x = ip(br.readLine()); 	
	    	int ans = Integer.MAX_VALUE;
	    	
	    	for(int i=0;i<n;i++)
	    		if(x % a[1][i]== 0)
	    			ans = Math.min(x/a[1][i],ans);
	    	
	    	for(int i=0;i<n;i++){
	    		for(int dis=1;dis<=k;dis++){
	    			for(int other=1;other<=k-dis;other++){
	    				int here = dis*a[1][i];
	    				int needed = x - here;
	    				int search = Arrays.binarySearch(a[other], needed);
	    				if( search >=0 && search < n)
	    					ans = Math.min(ans, dis+other);
	    			}
	    		}
	    	}
	    	
	    	w.println(ans > k ? -1 : ans);
	    }
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}