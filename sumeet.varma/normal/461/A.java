import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class AppleManAndToastMan {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    long a[] = new long[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	         
	    long sum = 0;
	    Arrays.sort(a);
	    sum = n * a[n-1];
	    long var = n;
	    for(int i= n-2;i>=0;i--){
	    	sum += var * a[i];
	    	var--;
	    }
	    
	    w.print(sum);
	    w.close();
	    
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}