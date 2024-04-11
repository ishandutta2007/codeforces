//package Practise;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class R202qCMafia {
	
	static int n;
	static int a[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	 
	    w.println(bSFirst(0,(long)(1e14)));
	    w.close(); 
	}
	
	//Returns first occurrence of key when it is present else -1
			public static long bSFirst(long start,long end){
				long ret = -1;
				while(true){
					if(start==end) return ret;
					long mid = (start+end)/2;
					if(func(mid)) ret = mid;
					if(end-start==1) return ret;
					if(func(mid))	end = mid;
					else start = mid+1;
				}
			}
			
			public static boolean func(long mid){
				long avail = 0;
				for(int i=0;i<n;i++){
					if(mid < a[i])
						return false;
					avail += mid - a[i];
				}
				if(avail >= mid)
					return true;
				return false;
			}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}