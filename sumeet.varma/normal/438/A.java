import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R250QCTheChildAndTheToy {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int v[] = new int[n+1];
	    for(int i=1;i<=n;i++)
	    	v[i] = ip(st2.nextToken());
	        
	    long ans = 0;
	    for(int i=0;i<m;i++){
	    	StringTokenizer st3 = new StringTokenizer(br.readLine());
	    	int x = ip(st3.nextToken());
	    	int y = ip(st3.nextToken());
	    	ans += Math.min(v[x],v[y]);
	    }
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}