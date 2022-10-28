import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class R263qBApplemanAndTree {

	static int n;
	static ArrayList<Integer> g[];
	static long dp[][];
	static int x[];
	static final int mod = (int)(1e9 + 7);
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    n = ip(br.readLine());
		
	    g = new ArrayList[n];
	    for(int i=0;i<n;i++)
			g[i] = new ArrayList<Integer>();
		
	    StringTokenizer st1 = new StringTokenizer(br.readLine()); 
		for(int i=1;i<n;i++)
			g[ip(st1.nextToken())].add(i);
	    
		x = new int[n];
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++)
			x[i] = ip(st2.nextToken());
		
		dp = new long[n][2];
		for(int i=0;i<n;i++)	dp[i][0] = dp[i][1] = -1; //dp[i][j] = ans for subtree[i] with j needed
		
		w.println(solve(0,1));
		w.close(); 
	}
	
	public static long solve(int curr,int state){
		//System.out.println(curr + " " + state);
		if(dp[curr][state] == -1){
			
			long ans = 0;
			if(state == 1){ //if 1 needed
				if(x[curr] == 0){
					long temp = 1;
					for(int next : g[curr])
						temp = (temp * (solve(next,1) + solve(next,0))) % mod;
					for(int next : g[curr]){
						long temp2 = (temp * inv(solve(next,0) + solve(next,1))) % mod;
						temp2 = (temp2 * solve(next,1)) % mod;
						ans += temp2;
						if(ans >= mod)
							ans -= mod;
					}
				}
				else{
					ans = 1;
					for(int next : g[curr])
						ans = (ans * (solve(next,0) + solve(next,1))) % mod;
				}
			}
			
			else{
				if(x[curr] == 0){
					ans = 1;
					for(int next : g[curr])
						ans = (ans * (solve(next,1) + solve(next,0))) % mod;
				}
				else
					ans = 0;
			}
			
			dp[curr][state] = ans;
			//System.out.println(curr + " " + state + " " + dp[curr][state] + " " + g[curr]);
		}
		
		return dp[curr][state];
	}
	
	public static long inv(long x){
		return pow((int)(x%mod),mod-2);
	}
	
	public static long pow(int a,int b){
		if(b == 0)
			return 1;
		long t = pow(a,b>>1);
		t = (t * t) % mod;
		if( (b & 1) != 0)
			t = (t * a) % mod;
		return t;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}