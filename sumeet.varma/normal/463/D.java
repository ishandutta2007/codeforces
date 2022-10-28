import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class GargariAndPermutations {
	
	static ArrayList<Integer> g[];
	static boolean vis[];
	static int ans[];
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int k = ip(st1.nextToken());
	     
		//O(kn)
		int a[][] = new int[k][n];
		for(int i=0;i<k;i++){
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++)
				a[i][j] = ip(st2.nextToken());
		}
		
		//O(kn^2)
		int count[][] = new int[n+1][n+1];
		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){
				for(int c=j+1;c<n;c++)
					count[a[i][j]][a[i][c]]++;
			}
		}
		
		g = new ArrayList[n+1];
	
		//O(n*n)
		for(int i=1;i<=n;i++){
			g[i] = new ArrayList<Integer>();
			for(int j=1;j<=n;j++)
				if(count[i][j] == k)
					g[i].add(j);
		}
		
		//find the longest path in this graph
		//O(n^2)
		vis = new boolean[n+1];
		ans = new int[n+1];
		int ans = 0;
		
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i] = true;
				//int tempAns = dfs(i);
				//System.out.println(i + " " + tempAns);
				ans = Math.max(ans, dfs(i));
			}
		}
		
		w.println(ans);
	    w.close(); 
	}
	
	public static int dfs(int start){
		
		int s = g[start].size();
		int ans2 = 1;
		for(int i=0;i<s;i++){
			if(!vis[g[start].get(i)]){
				vis[g[start].get(i)] = true;
				ans2 = Math.max(ans2, dfs(g[start].get(i)) + 1);
			}
			else
				ans2 = Math.max(ans2, 1 + ans[g[start].get(i)]);
		}
		ans[start] = ans2;
		return ans2;
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}