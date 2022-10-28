import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class TaskA {

	static boolean maze[][];
	static int n,m;
	
	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
	    m = ip(st1.nextToken());
	    int k = ip(st1.nextToken());
	          
	    maze = new boolean[n][m];
	    int ans = 0;
	    boolean found = false;
	    
	    for(int a=1;a<=k;a++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
		    int i = ip(st2.nextToken())-1;
		    int j = ip(st2.nextToken())-1;
		    if(!found){
			    maze[i][j] = true;
			    if(check(i,j)){
			    	ans = a;
			    	found = true;
			    }
		    }
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static boolean check(int i,int j){
		if(i+1<n && j+1<m){
			if(maze[i+1][j] && maze[i][j+1] && maze[i+1][j+1])
				return true;
		}
		
		if(i-1>=0 && j-1>=0){
			if(maze[i-1][j-1] && maze[i][j-1] && maze[i-1][j])
				return true;
		}
			
		if(i+1<n && j-1>=0){
			if(maze[i+1][j] && maze[i+1][j-1] && maze[i][j-1])
				return true;
		}
		
		if(i-1>=0 && j+1<m){
			if(maze[i-1][j] && maze[i][j+1] && maze[i-1][j+1])
				return true;
		}
		return false;
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}