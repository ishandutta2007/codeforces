//package Practise;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class PetyaAndDivisors {
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    int closest[] = new int[100001];
	    
	    for(int i=1;i<=n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	int x = ip(st2.nextToken());
	    	int y = ip(st2.nextToken());
	    	int ans = 0;
	    	for(int j=1;j*j<=x;j++){
	    		int t = x/j;
	    		if(t*j == x){
	    			if(closest[j] < i - y)
	    				ans++;
	    			if(t != j && closest[t] < i - y)
	    				ans++;
	    			closest[t] = closest[j] = i;
	    		}
	    	}
	    	w.println(ans);
	    }
	    
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}