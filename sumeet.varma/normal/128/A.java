import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class R94qAStatues {

	static int n=8,m=8;
	static char grid[][] = new char[n][m];
	static int dp[][][] = new int[n][m][m+1];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    grid = new char[n][m];
	    for(int i=0;i<n;i++)
	    	grid[i] = br.readLine().toCharArray();
	    
	    solve(n-1,0,0);
	    
	    w.println(dp[n-1][0][0] == -1 ? "LOSE" : "WIN");
	    w.close(); 
	}
	
	public static int solve(int x,int y,int moves){
		if(moves == m)	return 1;
		if(x- moves >= 0 && grid[x-moves][y] == 'S')	return -1;
		if(dp[x][y][moves] == 0){
			dp[x][y][moves] = -1;
			for(int dx=-1;dx<=1;dx++){
				for(int dy=-1;dy<=1;dy++){
					if(g(dx,dy,x,y,moves)){
						if(solve(x+dx,y+dy,moves+1) == 1)
							dp[x][y][moves] = 1;
					}
				}
			}
		}
		return dp[x][y][moves];
	}
	
	public static boolean g(int dx,int dy,int x,int y,int moves){
		if((x + dx) >= n || (x + dx) < 0 || (y + dy) >= m || (y + dy) < 0)	return false;
		if(x + dx - moves < 0)	return true;
		if(grid[x+dx-moves][y+dy] == 'S')	return false;
		return true;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}