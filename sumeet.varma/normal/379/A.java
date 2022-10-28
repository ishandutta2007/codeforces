//package GoodBye2013;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class GoodBye13qANewYearCandles {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int a = ip(st1.nextToken());
		int b = ip(st1.nextToken());
	        
		long ans = a;
		int left = a;
		while(left >= b){
			int t = left/b;
			ans += t;
			left -= b*t;
			left += t;
		}
	    
		w.println(ans);
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}