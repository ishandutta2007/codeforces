import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class DreamoonAndSets {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int k = ip(st1.nextToken());
	          
	    w.println((6*n-1)*k);
	         
	    int even = 2 ,odd = 1;
	    
	    for(int i=0;i<n;i++){
	    	w.printf("%d %d %d %d\n",k*even,k*odd,k*(odd+2),k*(odd+4));
	    	even += 2;
	    	if(i%2 != 0)
	    		even += 2;
	    	odd += 6;
	    }
	   
	    w.close(); 
	}
	
	public static int gcd(int a,int b){
		int temp=0;
		while(b!=0){
			temp = b;
			b = a%b;
			a = temp;
		}
		return a;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}