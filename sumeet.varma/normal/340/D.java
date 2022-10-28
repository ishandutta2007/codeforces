//package Practise;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class R198qDBubbleSortGraph {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    w.println(longestIncreasingSubsequenceNlogn(a,n));
	    w.close(); 
	}
	
	public static int longestIncreasingSubsequenceNlogn(int a[],int n){
		
		int tailTable[] = new int[n];
		int prev[] = new int[n];
		int len = 1;
		tailTable[0] = a[0];
		prev[0] = -1;
		for(int i=0;i<n;i++){
			if(a[i] <= tailTable[0]){
				tailTable[0] = a[i];
				prev[i] = -1;
			}
			else if(a[i] > tailTable[len-1]){
				tailTable[len] = a[i];
				prev[i] = tailTable[len-1];
				len++;
			}
			else{
				int index = ceilIndex(tailTable,0,len-1,a[i]);
				tailTable[index] = a[i];
				prev[i] = tailTable[index-1];
			}
		}
		
		return len;
	}
	
	public static int ceilIndex(int tailTable[], int l, int r, int key) {
	    while( r - l > 1 ) {
	        int m = l + (r - l)/2;
	        if(tailTable[m] >= key)
	        	r = m;
	        else
	        	l = m;
	    }
	    return r;
	}

	public static int ip(String s){
		return Integer.parseInt(s);
	}
}