import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class MaximumInTable {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
	    int grid[][] = new int[n][n];
	    for(int i=0;i<n;i++){
	    	grid[0][i] = 1;
	    	grid[i][0] = 1;
	    }
	    
	    for(int i=1;i<n;i++){
	    	for(int j=1;j<n;j++)
	    		grid[i][j] = grid[i-1][j] + grid[i][j-1];
	    }
	         
	    w.println(grid[n-1][n-1]);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}

}