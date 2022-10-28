import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.*;

public class R254QBDZYLovesChemistry {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	       
		boolean hash[][] = new boolean[n+1][n+1];
		for(int i=0;i<m;i++){
		    StringTokenizer st2 = new StringTokenizer(br.readLine());
		    int x = ip(st2.nextToken());
		    int y = ip(st2.nextToken());
		    hash[x][y] = true;
		    hash[y][x] = true;
		}
		
		int count = 0;
		boolean vis[] = new boolean[n+1];
		
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i] = true;
				count--;
				Queue<Integer> q = new LinkedList<Integer>();
				q.add(i);
				while(!q.isEmpty()){
					int c = q.remove();
					count++;
					for(int j=1;j<=n;j++){
						if(hash[c][j] && !vis[j]){
							vis[j] = true;
							q.add(j);
						}
					}
				}
			}
		}
	    
		w.println((long)Math.pow(2,count));
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}