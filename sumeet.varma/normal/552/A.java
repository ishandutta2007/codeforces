import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R308qA {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    int hash[][] = new int[101][101];
	    
	    int n = ip(br.readLine());
	   
	    while(n-- > 0){
	    	StringTokenizer st1 = new StringTokenizer(br.readLine());
	    	int x1 = ip(st1.nextToken());
	    	int y1 = ip(st1.nextToken());
	    	int x2 = ip(st1.nextToken());
	    	int y2 = ip(st1.nextToken());
	    	for(int i=x1;i<=x2;i++)
	    		for(int j=y1;j<=y2;j++)
	    			hash[i][j]++;
	    }
	    
	    int ans = 0;
	    for(int i=1;i<=100;i++)
	    	for(int j=1;j<=100;j++)
	    		ans += hash[i][j];
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	public static long lp(String s){
		return Long.parseLong(s);
	}
}