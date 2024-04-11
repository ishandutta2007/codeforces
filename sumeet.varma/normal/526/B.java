import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.*;

public class TaskB {

	static int n;
	static int a[];
	static int ans;
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		
	    ans = 0;
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[(1<<(n+1))];
	    for(int i=2;i<a.length;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    solve(1);
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int solve(int i){
		if(i >= (1<<n))
			return 0;
		int left = solve(2*i);
		int right = solve(2*i + 1);
		left += a[2*i];
		right += a[2*i+1];
		ans += Math.abs(left - right);
		return Math.max(left, right);
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	public static long lp(String s){
		return Long.parseLong(s);
	}
}