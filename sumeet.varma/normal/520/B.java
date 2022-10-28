import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class TwoNumbers {
	
	static int[] a;
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int m = ip(st1.nextToken());
	  
	    w.println(solve(n,m));
	    w.close(); 
	}

	public static int solve(int n,int m){
		if(m <= n)
			return n-m;
		int ans[] = new int[2*m+1];
		Arrays.fill(ans, -1);
		LinkedList<Integer> q = new LinkedList();
		q.add(n);
		ans[n] = 0;
		while(true){
			int curr = q.remove();
			if(2*curr <= 2*m && ans[2*curr]==-1){
				ans[2*curr] = ans[curr]+1;
				q.add(2*curr);
			}
			if(curr>1 && ans[curr-1]==-1){
				ans[curr-1] = ans[curr]+1;
				q.add(curr-1);
			}
			if(ans[m]!=-1)
				return ans[m];
		}
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}