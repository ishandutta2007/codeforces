import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R178qA {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    int m = ip(br.readLine());
	    
	    for(int i=0;i<m;i++){
	    	StringTokenizer st3 = new StringTokenizer(br.readLine());
	    	int x = ip(st3.nextToken()) - 1;
	    	int y = ip(st3.nextToken());
	    	int left = y - 1;
	    	int right = a[x] - y;
	    	if(x - 1 >= 0)
	    		a[x-1] += left;
	    	if(x + 1 < n)
	    		a[x+1] += right;
	    	a[x] = 0;
	    }
	    
	    
	    for(int i=0;i<n;i++)
	    	w.println(a[i]);
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}