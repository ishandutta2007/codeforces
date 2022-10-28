//package Practise;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class _24Game {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
	    if(n < 4){
	    	System.out.println("NO");
	    	return;
	    }
	    
	    System.out.println("YES");
	    
	    if(n == 4){
	    	call4();
	    	return;
	    }
	    
	    if(n == 5){
	    	call5();
	    	return;
	    }
	    
	    if(n%2 == 0){
	    	for(int i=n;i>4;i--){
	    		System.out.println(i + " - " + --i + " = "  + 1);
	    		System.out.println("1 * 1 = 1");
	    	}
	    	call4();
	    }
	    
	    else{
	    	for(int i=n;i>5;i--){
	    		System.out.println(i + " - " + --i + " = "  + 1);
	    		System.out.println("1 * 1 = 1");
	    	}
	    	call5();
	    }
	    
	    
	    w.close(); 
	}
	
	public static void call4(){
		System.out.println("4 * 3 = 12");
		System.out.println("12 * 2 = 24");
		System.out.println("24 * 1 = 24");
	}
	
	public static void call5(){
		System.out.println("5 * 4 = 20");
		System.out.println("3 - 1 = 2");
		System.out.println("2 + 2 = 4");
		System.out.println("20 + 4 = 24");
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}