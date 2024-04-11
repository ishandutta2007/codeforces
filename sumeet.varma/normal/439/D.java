import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R251QDDevuAndHisBrother {
	
	static int n,m;
	static int a[],b[];
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		m = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    StringTokenizer st3 = new StringTokenizer(br.readLine());
	    b = new int[m];
	    for(int i=0;i<m;i++)
	    	b[i] = ip(st3.nextToken());
	    
	    long ans = Long.MAX_VALUE;
	    
	    long start = 1,end = (long)(1e12);
	    
	    for(int it=0;it<100;it++){
	    	long mid1 = start + (end-start)/3;
	    	long mid2 = end - (end - start)/3;
	    	ans = Math.min(ans, func(mid1));
	    	ans = Math.min(ans, func(mid2));
	    	if(func(mid1) >= func(mid2))
	    		start = mid1;
	    	else
	    		end = mid2;
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	
	public static long func(long k){
		long ret = 0;
		for(int i=0;i<n;i++)
			ret += Math.max(0, k - a[i]);
		for(int i=0;i<m;i++)
			ret += Math.max(0, b[i] - k);
		return ret;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}