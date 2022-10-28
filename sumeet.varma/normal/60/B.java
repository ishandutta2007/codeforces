import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R56qBSerialTime {

	static char rect[][][];
	static boolean vis[][][];
	static int k,n,m;
	static int dk[],dx[],dy[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    dk = new int[]{-1,1,0,0,0,0};
	    dx = new int[]{0,0,-1,1,0,0};
	    dy = new int[]{0,0,0,0,-1,1};
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    k = ip(st1.nextToken());
		n = ip(st1.nextToken());
	    m = ip(st1.nextToken());
	    
	    br.readLine();
	    
	    rect = new char[k][n][m];
	    
	    for(int i=0;i<k;i++){
	    	for(int x=0;x<n;x++)
	    		rect[i][x] = br.readLine().toCharArray();
	    	br.readLine();
	    }
	    
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int x = ip(st2.nextToken()) - 1;
	    int y = ip(st2.nextToken()) - 1;
	    	    
	    vis = new boolean[k][n][m];
	    vis[0][x][y] = true;
	    
	    dfs(0,x,y);
	    
	    int ans = 0;
	    for(boolean der[][] : vis)
	    	for(boolean der2[] : der)
	    		for(boolean der3 : der2)
	    			if(der3)	ans++;
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static void dfs(int lev,int x,int y){
		for(int i=0;i<6;i++)
			if(g(lev+dk[i],x+dx[i],y+dy[i]) && !vis[lev+dk[i]][x+dx[i]][y+dy[i]]){
				vis[lev+dk[i]][x+dx[i]][y+dy[i]] = true;
				dfs(lev+dk[i],x+dx[i],y+dy[i]);
			}
	}
	
	public static boolean g(int x,int y,int z){
		return (x>=0) && (y>=0) && (z>=0) && (x<k) && (y<n) && (z<m) && rect[x][y][z] == '.';
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}