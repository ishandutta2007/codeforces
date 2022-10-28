import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class R146qBLetsPlayOsu {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    int n = Integer.parseInt(br.readLine());
	    
	    StringTokenizer st = new StringTokenizer(br.readLine());
	    double p[] = new double[n];
	    for(int i=0;i<n;i++)
	    	p[i] = Double.parseDouble(st.nextToken());
	    
	    double dp[] = new double[n];
	    for(int i=1;i<n;i++)
	    	dp[i] = (dp[i-1] + p[i-1]) * p[i];
	    
	    double ans = 0;
	    for(double prob : dp )
	    	ans += prob;
	    ans *= 2;
	    
	    for(int i=0;i<n;i++)
	    	ans += p[i];
	    
	    w.println(ans);
	    w.close(); 
	}
	
}