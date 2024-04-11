import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class R297Div2TaskDArthurAndWalls {

	static char grid[][];
	static int n,m;
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		m = ip(st1.nextToken());
	         
		grid = new char[n][m];
	    for(int i=0;i<n;i++)
	    	grid[i] = br.readLine().toCharArray();
	    
		LinkedList<Integer> q = new LinkedList<Integer>();
		
	    for(int i=0;i<n-1;i++){
	    	for(int j=0;j<m-1;j++){
	    		int wallCount = 0;
	    		int wallx = -1,wally = -1;
	    		for(int c=i;c<i+2;c++){
	    			for(int d=j;d<j+2;d++){
	    				if(grid[c][d] == '*'){
	    					wallCount++;
	    					wallx = c;
	    					wally = d;
	    				}
	    			}
	    		}
	    		if(wallCount == 1){
	    			q.add(wallx);
	    			q.add(wally);
	    			grid[wallx][wally] = '.';
	    		}
	    	}
	    }
	    
	    while(!q.isEmpty()){
	    	int x = q.remove();
	    	int y = q.remove();
	    	
	    	int ul = g(x,y) + g(x-1,y-1) + g(x,y-1) + g(x-1,y);
	    	if(ul == 103){
	    		if(grid[x-1][y-1] == '*'){
	    			grid[x-1][y-1] = '.';
	    			q.add(x-1);
	    			q.add(y-1);
	    		}
	    		if(grid[x][y-1] == '*'){
	    			grid[x][y-1] = '.';
	    			q.add(x);
	    			q.add(y-1);
	    		}
	    		if(grid[x-1][y] == '*'){
	    			grid[x-1][y] = '.';
	    			q.add(x-1);
	    			q.add(y);
	    		}
	    	}
	    		
	    	int ur = g(x,y) + g(x-1,y) + g(x-1,y+1) + g(x,y+1);
	    	if(ur == 103){
	    		if(grid[x-1][y] == '*'){
	    			grid[x-1][y] = '.';
	    			q.add(x-1);
	    			q.add(y);
	    		}
	    		if(grid[x-1][y+1] == '*'){
	    			grid[x-1][y+1] = '.';
	    			q.add(x-1);
	    			q.add(y+1);
	    		}
	    		if(grid[x][y+1] == '*'){
	    			grid[x][y+1] = '.';
	    			q.add(x);
	    			q.add(y+1);
	    		}
	    	}
	    	
	    	int lf = g(x,y) + g(x,y-1) + g(x+1,y) + g(x+1,y-1);
	    	if(lf == 103){
	    		if(grid[x+1][y] == '*'){
	    			grid[x+1][y] = '.';
	    			q.add(x+1);
	    			q.add(y);
	    		}
	    		if(grid[x+1][y-1] == '*'){
	    			grid[x+1][y-1] = '.';
	    			q.add(x+1);
	    			q.add(y-1);
	    		}
	    		if(grid[x][y-1] == '*'){
	    			grid[x][y-1] = '.';
	    			q.add(x);
	    			q.add(y-1);
	    		}
	    	}
	    	
	    	int lr = g(x,y) + g(x+1,y) + g(x,y+1) + g(x+1,y+1);
	    	if(lr == 103){
	    		if(grid[x+1][y] == '*'){
	    			grid[x+1][y] = '.';
	    			q.add(x+1);
	    			q.add(y);
	    		}
	    		if(grid[x+1][y+1] == '*'){
	    			grid[x+1][y+1] = '.';
	    			q.add(x+1);
	    			q.add(y+1);
	    		}
	    		if(grid[x][y+1] == '*'){
	    			grid[x][y+1] = '.';
	    			q.add(x);
	    			q.add(y+1);
	    		}
	    	}
	    }
	    
	    for(int i=0;i<n;i++)
	    	w.println(new String(grid[i]));
	    w.close(); 
	}
	
	public static int g(int x,int y){
		if(x < 0 || y < 0 || x >= n || y >= m)
			return -10000;
		return grid[x][y] == '.' ? 1 : 100;
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}