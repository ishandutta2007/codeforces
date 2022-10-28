import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R300qC {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	          
	    int d[] = new int[m];
	    int h[] = new int[m];
	    for(int i=0;i<m;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	d[i] = ip(st2.nextToken());
	    	h[i] = ip(st2.nextToken());
	    }
	    
	    int ans = h[m-1];
	    ans = Math.max(h[0] + d[0] - 1, ans);
	    ans = Math.max(ans, n - d[m-1] + h[m-1]);
	    
	    for(int i=0;i<m-1;i++){
	    	ans = Math.max(ans, h[i]);
	    	int hdiff = Math.abs(h[i+1] - h[i]);
	    	int ddiff = Math.abs(d[i+1] - d[i]);
	    	if(hdiff > ddiff){
	    		ans = -1;
	    		break;
	    	}
	    	int left = ddiff - hdiff;
	    	ans = Math.max(ans, left/2 + Math.max(h[i],h[i+1]));
	    }
	    
	    w.println(ans == -1 ? "IMPOSSIBLE" : ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}