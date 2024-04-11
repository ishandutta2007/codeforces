import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R270QAMath {

	public static void main(String args[] ) throws Exception {
		
					
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		boolean prime[] = sieve(n+50);
		
	    for(int i=3;i<n;i++){
	    	if(!prime[i] && !prime[n-i]){
	    		w.println(i + " " + (n-i));
	    		break;
	    	}
	    }
	        
	    
	    w.close(); 
	}
	
	public static boolean[] sieve(int n){//O(n)
		boolean prime[] = new boolean[n+1];
		Arrays.fill(prime,true);//assume all are prime except 0 and 0
		prime[0] = prime[1] = false;
		
		int m = (int) Math.sqrt(n);
		
		//going only till square root because for n if it had to have a factor it should have been before sqrt(n)//it cant have independent factors later
		
		for(int i=2;i<=m;i++)
			if(prime[i]) //if i is prime then make its multiples unprime
				for(int k=i*i;k<=n;k+=i) //multiples of i till i*i would already be unprime...so starting from i*i because such numbers would be i*j where j=2 to i-1 and they would already have been marked by those numbers
					prime[k] = false;
		
		return prime;
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}