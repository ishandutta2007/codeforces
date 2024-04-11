import java.io.*;
import java.util.*;

public class R299TaskA {

	static long a,b;
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    a = ip(st1.nextToken());
		b = ip(st1.nextToken());
	    int n = ip(st1.nextToken());
	    
	    for(int i=0;i<n;i++){
		    StringTokenizer st2 = new StringTokenizer(br.readLine());
		    int l = ip(st2.nextToken()) - 1;
		    long t = ip(st2.nextToken());
		    long m = ip(st2.nextToken());	
		    if(t < (a + l*b)){
		    	w.println("-1");
		    	continue;
		    }
		    else
		    	w.println(bSLast(l,l+1104010,l,m,t) + 1);
	    }
	    
	    w.close(); 
	}
	
	public static int bSLast(int start,int end,int l,long m,long t){
		int ret = -1;
		while(true){
			if(start==end) return ret;
			int mid = (start+end)/2;
			if(func(mid,l,m,t)) ret = mid;
			if(end-start==1) return ret;
			if(!func(mid,l,m,t))	end = mid;
			else start = mid+1;
		}
	}
	
	public static boolean func(long r,long l,long m,long t){
		long sum = a * (r - l + 1) + b * (1L * r * (r + 1) - 1L * l * (l-1))/2;
		return sum <= m*t && (a + r*b <= t);
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	public static long lp(String s){
		return Long.parseLong(s);
	}
}