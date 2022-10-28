import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R240QCMashmokhAndNumbers {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int k = ip(st1.nextToken());
	    
		if(n == 1){
			if(k == 0)
				System.out.println("1");
			else
				System.out.println("-1");
			return;
		}
		
		int a[] = new int[n];
	    
		int min = n/2;
	    if(k < min){
	    	System.out.println(-1);
	    	return;
	    }
	    
	    int limit = (int)(1e9);
	    
	    int left = k - (min - 1);
	    a[0] = left;
	    a[1] = 2*left;
	    
	    for(int i=2;i<n;i++)
	    	a[i] = limit--;
	    
	    for(int i=0;i<n;i++)
	    	w.print(a[i] + " ");
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}