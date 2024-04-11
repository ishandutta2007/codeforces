import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class NewYearTransportation {


	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int t = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=1;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	         
	    int pos = 1;
	    while(pos < t){
	    	pos = pos + a[pos];
	    }
	    
	    w.println(pos==t ?"YES":"NO");
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}