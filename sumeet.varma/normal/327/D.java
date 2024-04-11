import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class R191qDBlockTower {

	static int n,m;
	static char grid[][];
	static int blue = -1,red = -2,down = -3;
	static ArrayList<Integer> ans;
	
	static int dx[],dy[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		m = ip(st1.nextToken());
		
		dx = new int[]{-1,1,0,0};
		dy = new int[]{0,0,-1,1};
		
		grid = new char[n][m];
		for(int i=0;i<n;i++)
			grid[i] = br.readLine().toCharArray();
	    
		ans = new ArrayList<Integer>();
		
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<m;j++){
	    		if(grid[i][j] == '.'){
	    			grid[i][j] = 'b';
	    			ans.add(blue);
	    			ans.add(i+1);
	    			ans.add(j+1);
	    		}
	    	}
	    }
	    
	    for(int i=0;i<n;i++)
	    	for(int j=0;j<m;j++)
	    		if(grid[i][j] == 'b')
	    			dfs(i,j,false);
	    
	    int k = ans.size() / 3;
	    w.println(k);
	    
	    for(int i=0;i<3*k;){
	    	int type = ans.get(i++);
	    	if(type == blue)
	    		w.print("B ");
	    	else if(type == red)
	    		w.print("R ");
	    	else
	    		w.print("D ");
	    	w.print(ans.get(i++) + " ");
	    	w.println(ans.get(i++));
	    }
	    
	    w.close(); 
	}
	
	public static void dfs(int x,int y,boolean var){
		grid[x][y] = 'R';	
		
		for(int i=0;i<4;i++){
			if(g(x+dx[i],y+dy[i]))
				dfs(x+dx[i],y+dy[i],true);
		}
		
		if(var){
			ans.add(down);
			ans.add(x+1);
			ans.add(y+1);
			ans.add(red);
			ans.add(x+1);
			ans.add(y+1);
		}
	}
	
	public static boolean g(int i,int j){
		if(i < 0 || j < 0 || i >= n || j >= m)	return false;
		if(grid[i][j] == 'b')	return true;
		return false;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}