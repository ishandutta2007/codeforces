import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R210qBLevkoAndArray {

	static int n,k;
	static int dp[];
	static long a[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		k = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new long[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	    
	    w.println(bSFirst(0,(long)(1e10)));
	    w.close(); 
	}
	
	public static int bSFirst(long start,long end){
		long ret = -1;
		while(start < end){
			long mid = (start + end) / 2;
			boolean res = func(mid);	
			if(res) ret = end = mid;
			else	start = mid + 1;
		}
		return (int)ret;
	}
	
	public static boolean func(long x){
		int dp[] = new int[n];
		
		for(int i=0;i<n;i++)
			dp[i] = i;
		
		for(int i=1;i<n;i++)
			for(int j=0;j<i;j++)
				if(Math.abs(a[i] - a[j]) <= x*(i-j))
					dp[i] = Math.min(dp[i], dp[j] + i - j - 1);
		
		int ans = dp[n-1];
		for(int i=0;i<n;i++)
			ans = Math.min(ans,dp[i] + n - 1 - i);
		
		return ans <= k;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}