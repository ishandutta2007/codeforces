import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R178qC {

	static long c[][];
	static long pow2[];
	static long mod = (long)(1e9 + 7);
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    c = new long[1001][1001];
	    c[0][0] = 1;
	    for(int i=1;i<=1000;i++){
	    	c[i][0] = c[i][i] = 1;
	    	for(int j=1;j<i;j++)
	    		c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
	    }
	    
	    pow2 = new long[1001];
	    pow2[0] = 1;
	    for(int i=1;i<=1000;i++)
	    	pow2[i] = (2 * pow2[i-1]) % mod;
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int b[] = new int[m];
	    for(int i=0;i<m;i++)
	    	b[i] = ip(st2.nextToken());
	    Arrays.sort(b);
	   
	    long ans = 1;
	    
	    int length = b[0] - 1;
	    for(int i=0;i<m-1;i++){
	    	if(b[i+1] != b[i] + 1){
		    	ans *= c[length + b[i+1] - b[i] - 1][length];
		    	ans %= mod;
		    	length += b[i+1] - b[i] - 1;
		    	ans *= pow2[b[i+1] - b[i] - 2];
		    	ans %= mod;
	    	}
	    }
	    
	    ans *= c[length + n - b[m-1]][length];
	    ans %= mod;
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}