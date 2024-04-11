import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
import java.util.StringTokenizer;


public class R222qAMaze {

	static int n,m,k;
	static char grid[][];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    int dx[] = {-1,1,0,0};
	    int dy[] = {0,0,-1,1};
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
	    m = ip(st1.nextToken());
	    k = ip(st1.nextToken());
	    
	    grid = new char[n][m];
	    for(int i=0;i<n;i++)
	    	grid[i] = br.readLine().toCharArray();
	    
	    
	    Queue<Integer> q = new LinkedList<Integer>();
	 
	    int s = 0;
	    boolean state = true;
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<m;j++){
	    		if(grid[i][j] == '.'){
	    			if(state){
	    				q.add(i);
	    				q.add(j);
	    				state = false;
	    			}
	    			s++;
	    		}
	    	}
	    }
	    
	    int count = 0;
	    while(count < (s-k)){
	    	int x = q.remove();
	    	int y = q.remove();
	    	if(grid[x][y] == 'X')	continue;
	    	grid[x][y] = 'X';
	    	count++;
	    	for(int d=0;d<4;d++){
	    		if(g(x+dx[d],y+dy[d])){
	    			q.add(x+dx[d]);
	    			q.add(y+dy[d]);
	    		}
	    	}
	    }
	    
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<m;j++){
	    		if(grid[i][j] == 'X')
	    			grid[i][j] = '.';
	    		else if(grid[i][j] == '.')
	    			grid[i][j] = 'X';
	    	}
	    }
	    
	    for(int i=0;i<n;i++)
	    	w.println(new String(grid[i]));
	    w.close(); 
	}
	
	public static boolean g(int x,int y){
		if(x < 0 || y < 0 || x >= n || y >= m)	return false;
		if(grid[x][y] == '.')	return true;
		return false;
	}
	
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}