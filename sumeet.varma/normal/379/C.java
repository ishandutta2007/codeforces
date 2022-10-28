//package GoodBye2013;

import java.io.*;
import java.util.*;

public class GoodBye13qCNewYearRatingsChange {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    Pair p[] = new Pair[n];
	    for(int i=0;i<n;i++)
	    	p[i] = new Pair(i,ip(st2.nextToken()));
	        
	    Arrays.sort(p);
	    int ans[] = new int[n];
	    int lastVal = -1;
	    
	    for(int i=0;i<n;i++){
	    	if(p[i].val > lastVal){
	    		lastVal = p[i].val;
	    		ans[p[i].idx] = p[i].val;
	    	}
	    	else{
	    		lastVal++;
	    		ans[p[i].idx] = lastVal;
	    	}
	    }
	    
	    for(int i=0;i<n;i++)
	    	w.print(ans[i] + " ");
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}

class Pair implements Comparable<Pair>{
	int idx,val;
	Pair(int idx,int val){
		this.idx = idx;
		this.val = val;
	}
	public int compareTo(Pair b){
		return val - b.val;
	}
}