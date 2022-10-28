import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R256QCPaintingFence {

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
	        
	    w.println(solve(0,n-1));
	    w.close(); 
	}
		
	public static int solve(int start,int end){
		//System.out.println(start + " " + end);
		if(start > end)
			return 0;
		if(start == end && a[start] != 0)
			return 1;
		if(start == end && a[start] == 0)
			return 0;
		int min = Integer.MAX_VALUE;
		for(int i=start;i<=end;i++)
			min = Math.min(min,a[i]);
		int curi = start;
		int ans = min;
		boolean foundFirst = false;
		for(int i=start;i<=end;i++){
			a[i] -= min;
			if((a[i] == 0 && i!=start && a[i-1] != 0)){
				ans += solve(curi,i-1);
				curi = i + 1;
				foundFirst = true;
			}
			if(a[i] == 0 && foundFirst == false)
				curi = i + 1;
		}
		if(a[end] != 0)
			ans += solve(curi,end);
		return Math.min(ans,end-start+1);
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}