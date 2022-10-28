import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class BayanStringlyConnectedCity {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	         
		ArrayList<Integer> g[][] = new ArrayList[n][m];
	    for(int i=0;i<n;i++)
	    	for(int j=0;j<m;j++)
	    		g[i][j] = new ArrayList<Integer>();
	    
		char horiz[] = br.readLine().toCharArray();
	        
		for(int i=0;i<n;i++){
			if(horiz[i] == '>'){
				for(int j=0;j<(m-1);j++){
					g[i][j].add(i);
					g[i][j].add(j+1);
				}
			}
			else{
				for(int j=1;j<m;j++){
					g[i][j].add(i);
					g[i][j].add(j-1);
				}
			}
		}
		
		char verti[] = br.readLine().toCharArray();
		
		for(int j=0;j<m;j++){
			if(verti[j] == 'v'){
				for(int i=0;i<(n-1);i++){
					g[i][j].add(i+1);
					g[i][j].add(j);
				}
			}
			else{
				for(int i=1;i<n;i++){
					g[i][j].add(i-1);
					g[i][j].add(j);
				}
			}
		}
		
		boolean ans = true;
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				
				boolean vis[][] = new boolean[n][m];
				
				vis[x][y] = true;
				Queue<Integer> q = new LinkedList<Integer>();
				q.add(x);
				q.add(y);
				
				while(!q.isEmpty()){
					int cx = q.remove();
					int cy = q.remove();
					int s = g[cx][cy].size();
					
					for(int i=0;i<s;){
						int nxtx = g[cx][cy].get(i++);
						int nxty = g[cx][cy].get(i++);
						if(!vis[nxtx][nxty]){
							vis[nxtx][nxty] = true;
							q.add(nxtx);
							q.add(nxty);
						}
					}
				}
				
				for(int i=0;i<n;i++)
					for(int j=0;j<m;j++)
						ans = ans & vis[i][j];
			}
		}
	
	    
		w.println(ans ? "YES" : "NO");
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}