import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R259QCExpectedMaximum {

	@SuppressWarnings("unused")
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int m = ip(st1.nextToken());
		int n = ip(st1.nextToken());
	  
	    double prob[] = new double[m+1];
	    double sum = 0;
	    for(int i=1;i<=m;i++){
	    	prob[i] = power(1.0*i/m,n) - sum;
	    	sum += prob[i];
	    }
	    
	   // System.out.println(Arrays.toString(prob));
	    
	    double ans = 0;
	    for(int i=1;i<=m;i++)
	    	ans += prob[i] * i;
	    w.println(ans);
	    w.close(); 
	}
	
	public static double power(double a,int b){
		if(b == 0)
			return 1;
		if(b == 1)
			return a;
		double t = power(a,b/2);
		return t * t * ((b % 2 == 0 ) ? 1 : a);
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}