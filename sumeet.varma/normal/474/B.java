import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Worms {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    int sum = 0;
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++){
	    	a[i] = ip(st2.nextToken());
	    	sum += a[i];
	    }
	    
	    int pos[] = new int[sum+1];
	    
	    int count = 1;
	    
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<a[i];j++)
	    		pos[count++] = i+1;
	    }
	    
	    int m = ip(br.readLine());
	    
	    st1 = new StringTokenizer(br.readLine());
	    for(int i=0;i<m;i++)
	    	w.println(pos[ip(st1.nextToken())]);
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}