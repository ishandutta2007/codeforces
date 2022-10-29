import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.ArrayList;

public class R2775UnberableControversyOfBeing {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	          
		ArrayList<Integer> g[] = new ArrayList[n+1];
	    for(int i=1;i<=n;i++)
	    	g[i] = new ArrayList<Integer>();
	    
	    for(int i=0;i<m;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	int u = ip(st2.nextToken());
	    	int v = ip(st2.nextToken());
	    	g[u].add(v);
	    }
	    
	    int atDist2[][] = new int[n+1][n+1];
	    
	    for(int i=1;i<=n;i++){
	    	int s = g[i].size();
	    	for(int j=0;j<s;j++){
	    		int nxt = g[i].get(j);
	    		int ns = g[nxt].size();
	    		for(int k=0;k<ns;k++)
	    			atDist2[i][g[nxt].get(k)]++;
	    	}
	    }
	    
	    long ans = 0;
	    for(int i=1;i<=n;i++)
	    	for(int j=1;j<=n;j++)
	    		if(i != j)
	    			ans += atDist2[i][j] * (atDist2[i][j] - 1) / 2;
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}