import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class R221qBMaximumSubmatrix2 {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	          
	    int a[][] = new int[n+1][m+1];
	    char temp[];
	    for(int i=1;i<=n;i++){
	    	temp = br.readLine().toCharArray();
	    	for(int j=1;j<=m;j++)
	    		a[i][j] = temp[j-1] == '0' ? 0 : 1;
	    }
	    
	    int left[][] = new int[m+1][n+1];
	    for(int i=1;i<=n;i++)
	    	for(int j=1;j<=m;j++)
	    		left[j][i] = a[i][j] == 0 ? 0 : left[j-1][i] + 1;
	    int ans = 0;
	    
	    for(int j=1;j<=m;j++){
	    	Arrays.sort(left[j]);
	    	for(int i=n;i>0;i--)
	    		ans = Math.max(ans, left[j][i] * (n - i + 1));
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}