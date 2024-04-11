import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class IlyaAndEscalator {

    static double dp[][];
    
    public static void main(String args[] ) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter w = new PrintWriter(System.out);
            
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        int N = ip(st1.nextToken());
        double p = Double.parseDouble(st1.nextToken());
        int T = ip(st1.nextToken());
              
        dp = new double[N+1][T+1];
        
        dp[0][0] = 1;
        
        for(int t=1;t<=T;t++){
            for(int n=0;n<=N;n++)
                dp[n][t] = (n!=0 ? p*dp[n-1][t-1] : 0) + ((n != N) ? (1-p)*dp[n][t-1] : dp[n][t-1]);
        }
        
        double ans = 0;
        for(int i=1;i<=N;i++){
            //System.out.println(dp[i][T]);
            ans += i*dp[i][T];
        }
        
        w.println(ans);
        w.close(); 
    }
    
    public static int ip(String s){
        return Integer.parseInt(s);
    }
}