import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class AndreyAndProblem {

public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	   
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    double a[] = new double[n];
	    for(int i=0;i<n;i++)
	    	a[i] = Double.parseDouble(st2.nextToken());
	         
	    Arrays.sort(a);
	    double ans = a[n-1];
	    double noone = 1 - a[n-1];
	    for(int i=n-2;i>=0;i--){
	    	double ans2 = ans * (1 - a[i]) + a[i] * noone ;
	    	noone *= 1 - a[i];
	    	if(ans2 >= ans)
	    		ans = ans2;
	    	else
	    		break;
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}