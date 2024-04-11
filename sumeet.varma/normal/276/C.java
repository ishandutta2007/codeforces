//package Practise;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class R169qCLittleGirlAndMaxSum {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int q = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    Arrays.sort(a);
	    
	    int idxCount[] = new int[n+1];
	    
	    for(int i=0;i<q;i++){
	    	StringTokenizer st = new StringTokenizer(br.readLine());
	    	int l = ip(st.nextToken()) - 1;
	    	int r = ip(st.nextToken()) - 1;
	    	idxCount[l]++;
	    	idxCount[r+1]--;
	    }
	    
	    for(int i=1;i<n;i++)
	    	idxCount[i] += idxCount[i-1];
	    idxCount[n] = 100000000;
	    Arrays.sort(idxCount);
	    
	    long ans = 0;
	    for(int i=0;i<n;i++)
	    	ans += idxCount[i] * 1L * a[i];
	    w.println(ans);
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}