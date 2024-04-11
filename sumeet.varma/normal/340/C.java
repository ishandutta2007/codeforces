//package Practise;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class R198qCTouriseProblem {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    Arrays.sort(a);
	    
	    long sum = 0;
	    for(int i=0;i<n;i++)
	    	sum += a[i];
	    
	    long ans = sum;
	    
	    for(int i=0;i<n;i++){
	    	if(i != 0)
	    		sum -= (n - i)*1L*(a[i] - a[i-1]);
	    	else
	    		sum -= (n - i)*1L*a[i];
	    	ans += 2*sum;
	    }
	    
	    long g = gcd(ans,n);
	    w.println(ans/g + " " + n/g);
	    w.close(); 
	}
	
	public static long gcd(long a,long b){
		long t;
		while(b != 0){
			t = b;
			b = a % b;
			a = t;
		}
		return a;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}