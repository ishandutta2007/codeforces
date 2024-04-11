import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R254QADZYLovesChessBoards {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	    
		char grid[][] = new char[n][m];
		for(int i=0;i<n;i++)
			grid[i] = br.readLine().toCharArray();
	    
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<m;j++){
	    		if(grid[i][j] == '.'){
	    			grid[i][j] = 'W';
	    			if(i % 2 == j % 2 )
	    				grid[i][j] = 'B';
	    		}
	    	}
	    }
		
	    for(int i=0;i<n;i++)
	    	w.println(new String(grid[i]));
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}