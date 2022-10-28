import java.io.*;
import java.util.*;

public class LsryQD {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    String ans[] = new String[]{"Stannis","Daenerys"};
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int k = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    int odd = 0;
	    for(int i=0;i<n;i++)
	    	if((a[i] & 1) == 1)
	    		odd++;
	    
	    int turns = n - k;
	    
	    if(k == n){
	    	if(odd % 2 == 1)
	    		System.out.println(ans[0]);
	    	else
	    		System.out.println(ans[1]);
	    	return;
	    }
	    
	    if(turns/2 >= odd){
	    	System.out.println(ans[1]);
	    	return;
	    }
	    
	    //Now we know number of odds > turns/2 //No one can finish odds
	    
	    int even = n - odd;
	    
	    if(turns % 2 == 1){
	    	if(turns/2 >= even){
	    		if(k % 2 == 1 )
	    			System.out.println(ans[0]);
	    		else
	    			System.out.println(ans[1]);
	    	}
	    	else
	    		System.out.println(ans[0]);
	    	return;
	    }
	    
	    //now we know both have equal turns
	    if(turns % 2 == 0){
	    	if(turns/2 >= even){
	    		if(k % 2 == 1)
	    			System.out.println(ans[0]);
	    		else
	    			System.out.println(ans[1]);
	    	}
	    	else
	    		System.out.println(ans[1]);
	    	return;
	    }
	    
	
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
		
}