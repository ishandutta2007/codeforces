import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R240TDMashmokhAndAcm {

	static long dp[][];
	static long mod = (long)(1e9 + 7);
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    /*
	    int count = 0;
	    for(int i=1;i<=2000;i++){
	    	for(int j=1;j<=i;j++){
	    		if(i % j == 0)
	    			count++;
	    	}
	    }
	    System.out.println(count * 2000);
	    */
	    
	    ArrayList<Integer>[] divisors = new ArrayList[2001];
	    for(int i=1;i<=2000;i++)
	    	divisors[i] = new ArrayList<Integer>();
	    
	    for(int i=1;i<=2000;i++){
	    	for(int j=1;j*j<=i;j++){
	    		if(i % j == 0){
	    			divisors[i].add(j);
	    			if(i/j != j)
	    				divisors[i].add(i/j);
	    		}
	    	}
	    }
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int k = ip(st1.nextToken());
	    
		dp = new long[k][n+1];
		Arrays.fill(dp[k-1], 1);
		
		for(int i=k-2;i>=0;i--){
			for(int j=1;j<=n;j++){
				int s = divisors[j].size();
				for(int c=0;c<s;c++){
					int d = divisors[j].get(c);
					dp[i][d] += dp[i+1][j];
				}
			}
			for(int j=1;j<=n;j++)
				dp[i][j] %= mod;
		}
		
		long ans = 0;
		for(int i=1;i<=n;i++)
			ans += dp[0][i];
		ans %= mod;
		w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}