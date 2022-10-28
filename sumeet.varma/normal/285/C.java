import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.*;

public class R275D2TaskCBuildingPermutation {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n+1];
	    for(int i=1;i<=n;i++)
	    	a[i] = ip(st2.nextToken());
	         
	    a[0] = Integer.MIN_VALUE;
	    Arrays.sort(a);
	    
	    //System.out.println(Arrays.toString(a));
	    
	    long ans = 0;
	    for(int i=1;i<=n;i++)
	    	ans += Math.abs(i - a[i]);
	    
	    w.println(ans);
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}