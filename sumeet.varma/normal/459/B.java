import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R261D2TBPashmakAndFlowers {

public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	         
	    int min = a[0];
	    int max = a[0];
	    
	    for(int i=0;i<n;i++){
	    	max = Math.max(a[i], max);
	    	min = Math.min(a[i], min);
	    }
	    
	    int mc = 0,MC = 0;
	    for(int i=0;i<n;i++){
	    	if(a[i] == min)
	    		mc++;
	    	if(a[i] == max)
	    		MC++;
	    }
	    
	    w.print((max - min) + " ");
	    if(min == max)
	    	w.println(1L * mc * (mc - 1)/ 2);
	    else
	    	w.println(1L * mc * MC);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}