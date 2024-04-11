//package GoodBye2013;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class GoodBye13qBNewYearPresent {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	    
	    for(int i=0;i<a[0];i++)
	    	w.print("PRL");
	    w.print("R");
	    
	    for(int i=1;i<n;i++){
	    	for(int j=0;j<a[i];j++)
	    		w.print("PLR");
	    	if(i != n-1)
	    		w.print("R");
	    }
	    w.println();
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}