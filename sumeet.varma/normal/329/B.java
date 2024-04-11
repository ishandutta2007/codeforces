import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class R192qBBiridianForest {
	
	public static void main(String args[] ) throws Exception {
		
		int dx[] = new int[]{-1,1,0,0};
		int dy[] = new int[]{0,0,-1,1};
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int r = ip(st1.nextToken());
		int c = ip(st1.nextToken());
	    
		char a[][] = new char[r][c];
	    for(int i=0;i<r;i++)
	    	a[i] = br.readLine().toCharArray();
	        
	    int sx = -1,sy = -1;
	    for(int i=0;i<r;i++)
	    	for(int j=0;j<c;j++)
	    		if(a[i][j] == 'S'){
	    			sx = i;
	    			sy = j;
	    		}
	    
	    boolean vis[][] = new boolean[r][c];
		vis[sx][sy] = true;
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(sx);
		q.add(sy);
		
		int ans[][] = new int[r][c];
		ans[sx][sy] = 0;
		
		int ex = -1,ey = -1;
		
		while(!q.isEmpty()){
			int x = q.remove();
			int y = q.remove();
			if(a[x][y] == 'E'){
				ex = x;
				ey = y;
				break;
			}
			for(int i=0;i<4;i++){
				if(g(x+dx[i],y+dy[i],r,c) && a[x+dx[i]][y+dy[i]] != 'T' && !vis[x+dx[i]][y+dy[i]]){
					ans[x+dx[i]][y+dy[i]] = ans[x][y] + 1;
					vis[x+dx[i]][y+dy[i]] = true;
					q.add(x+dx[i]);
					q.add(y+dy[i]);
				}
			}
		}
		
		int ans2[][] = new int[r][c];
		for(int i=0;i<r;i++)
			Arrays.fill(ans2[i], Integer.MAX_VALUE);
		
		q.clear();
		ans2[ex][ey] = 0;
		q.add(ex);
		q.add(ey);
		
		while(!q.isEmpty()){
			int x = q.remove();
			int y = q.remove();
			for(int i=0;i<4;i++){
				if(g(x+dx[i],y+dy[i],r,c) && a[x+dx[i]][y+dy[i]] != 'T' && ans2[x+dx[i]][y+dy[i]] == Integer.MAX_VALUE){
					ans2[x+dx[i]][y+dy[i]] = ans2[x][y] + 1;
					q.add(x+dx[i]);
					q.add(y+dy[i]);
				}
			}
		}
	    
		int time = 0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(a[i][j] >= '0' && a[i][j] <= '9'){
					if(ans2[i][j] <= ans[ex][ey])
						time += a[i][j] - '0';
				}
			}
		}
		
		w.println(time);
	    w.close(); 
	}
	
	public static boolean g(int x,int y,int r,int c){
		if(x < 0 || y < 0 || x >= r || y >= c)	return false;
		return true;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}