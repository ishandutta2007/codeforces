import java.io.*;
import java.util.*;

public class LsryQC {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	          
	    char grid[][] = new char[n][m];
	    for(int i=0;i<n;i++)
	    	grid[i] = br.readLine().toCharArray();
	    
	    int val[][] = new int[n + 1][m + 1];
	    int ans = 0;
	    
	    for(int i=n-1;i>=0;i--){
	    	for(int j=m-1;j>=0;j--){
	    		int need;
	    		if(grid[i][j] == 'W')
	    			need = 1;
	    		else
	    			need = -1;
	    		val[i][j] += val[i][j+1];
	    		int change = need - val[i][j];
	    		if(change != 0){
	    			ans++;
	    			for(int k=i;k>=0;k--)
	    				val[k][j] += change;
	    		}
	    	}
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}