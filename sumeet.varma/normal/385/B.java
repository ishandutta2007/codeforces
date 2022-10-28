import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R226qBBearAndStrings {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    char s[] = br.readLine().toCharArray();
	    int n = s.length;
	    
	    boolean yes[] = new boolean[n];
	    
	    char pat[] = "bear".toCharArray();
	    
	    for(int i=0;i<n-3;i++){
	    	yes[i] = true;
	    	for(int j=i;j<i+4;j++){
	    		if(s[j] != pat[j - i])
	    			yes[i] = false;
	    	}
	    }
	   
	    boolean dp[][] = new boolean[n][n];
	    
	    for(int len=3;len<n;len++){
	    	for(int i=0;i<n-len;i++){
	    		if(yes[i] || dp[i+1][i+len])
	    			dp[i][i+len] = true;
	    	}
	    }
	    
	    int ans = 0;
	    for(int i=0;i<n;i++)
	    	for(int j=0;j<n;j++)
	    		if(dp[i][j])
	    			ans++;
	    
	    w.println(ans);
	    w.close();
	        
	}
	
}