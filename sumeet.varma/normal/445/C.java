import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R254QCDZYLovesPhysics {

	static int g[][];
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	         
		int x[] = new int[n+1];
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    for(int i=1;i<=n;i++)
	    	x[i] = ip(st2.nextToken());
	    
	    double ans = 0;
	    
	    g = new int[n+1][n+1];
	    for(int i=0;i<m;i++){
	    	StringTokenizer st3 = new StringTokenizer(br.readLine());
	    	int a = ip(st3.nextToken());	
	    	int b = ip(st3.nextToken());
	    	int c = ip(st3.nextToken());
	    	g[a][b] = g[b][a] = c;
	    		ans = Math.max(ans, 1.0*(x[a] + x[b])/c);
	    }
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}