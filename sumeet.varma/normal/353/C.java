import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R205qCFindMaximum {

	static int n;
	static int a[],dp[][];
	static char m[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = Integer.parseInt(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = Integer.parseInt(st2.nextToken());
	 
	    m = br.readLine().toCharArray();
	    
	    int pre[] = new int[n];
	    pre[0] = a[0];
	    for(int i=1;i<n;i++)
	    	pre[i] = a[i] + pre[i-1];
	   
	    int ans = 0,rightAns = 0;
	    for(int i=n-1;i>=0;i--){
	    	if(m[i] == '1'){
	    		ans = Math.max(ans,(i > 0 ? pre[i-1] : 0) + rightAns);
	    		rightAns += a[i];
	    	}
	    }
	    ans = Math.max(ans,rightAns);
	    w.println(ans);
	    w.close(); 
	}
	
}