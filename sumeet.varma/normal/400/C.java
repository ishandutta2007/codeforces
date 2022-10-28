//package Practise;

import java.io.*;
import java.util.*;

public class R234TBNewMatrixOfCandies {

	@SuppressWarnings("unused")
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	    int x = ip(st1.nextToken());
	    int y = ip(st1.nextToken());
	    int z = ip(st1.nextToken());
	    int p = ip(st1.nextToken());
	    
	    y = y % 2;
	    x = x % 4;
	    z = z % 4;
	    
	    int nn = n;
	    int mm = m;
	    
	    for(int i=0;i<p;i++){
		    StringTokenizer st2 = new StringTokenizer(br.readLine());
		    int xk = ip(st2.nextToken());
		    int yk = ip(st2.nextToken());
		    int ansx = xk,ansy = yk;
		   
		    for(int j=0;j<x;j++){
		    	int t = ansx;
		    	ansx = ansy;
		    	ansy = n - t + 1;
		    	int tt = n;
		    	n = m;
		    	m = tt;
		    }
		    
		    if(y == 1)
		    	ansy = m - ansy + 1;
		    
		  
		    for(int j=0;j<z;j++){
		    	int t = ansy;
		    	ansy = ansx;
		    	ansx = m - t + 1;
		    	int tt= n;
		    	n = m;
		    	m = tt;
		    }
		    
		    n = nn;
		    m = mm;
		    w.println(ansx + " " + ansy);
		   // w.flush();
	    }
	    
	    w.close(); 
	}
	
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}