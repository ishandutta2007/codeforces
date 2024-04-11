import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R215qBSerejaAndSuffixes {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	    
	    int ans[] = new int[n+1];
	    boolean hash[] = new boolean[100001];
	    for(int i=n-1;i>=0;i--){
	    	ans[i] = ans[i+1];
	    	if(!hash[a[i]])	ans[i]++;
	    	hash[a[i]] = true;
	    }
	    
	    for(int i=0;i<m;i++)
	    	w.println(ans[ip(br.readLine()) - 1]);
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}