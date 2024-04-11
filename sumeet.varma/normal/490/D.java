import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Chocolate {
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    long a1 = lp(st1.nextToken());
	    long b1 = lp(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    long a2 = lp(st2.nextToken());
	    long b2 = lp(st2.nextToken());
	    
	    long x = a1 * b1;
	    long y = a2 * b2;
	 
	    int countx[] = new int[2];
	    int county[] = new int[2];
	    
	    countx[0] = solve(2,x);
	    countx[1] = solve(3,x);
	    
	    county[0] = solve(2,y);
	    county[1] = solve(3,y);
	    
	    long ans = 0;
	    
	    if(countx[1] >= county[1]){
	    	int t = countx[1] - county[1];
	    	ans += t;
	    	for(int i=0;i<t;i++){
	    		x = 2*x/3;
	    		if(a1 % 3 == 0){
	    			a1 /= 3;
	    			a1 *= 2;
	    		}
	    		else{
	    			b1 /= 3;
	    			b1 *= 2;
	    		}
	    	}
	    	countx[0] += t;
	    }
	    
	    else{
	    	int t = county[1] - countx[1];
	    	ans += t;
	    	for(int i=0;i<t;i++){
	    		y = 2*y/3;
	    		if(a2 % 3 == 0){
	    			a2 /= 3;
	    			a2 *= 2;
	    		}
	    		else{
	    			b2 /= 3;
	    			b2 *= 2;
	    		}
	    	}
	    	county[0] += t;
	    }
	    
	    if(countx[0] >= county[0]){
	    	int t = countx[0] - county[0];
	    	ans += t;
	    	for(int i=0;i<t;i++){
	    		x = x/2;
	    		if(a1 % 2 == 0)
	    			a1 /= 2;
	    		else
	    			b1 /= 2;
	    	}
	    }
	    
	    else{
	    	int t = county[0] - countx[0];
	    	ans += t;
	    	for(int i=0;i<t;i++){
	    		y = y/2;
	    		if(a2 % 2 == 0)
	    			a2 /= 2;
	    		else
	    			b2 /= 2;
	    	}
	    }
	    
	    if(x != y)
	    	w.println(-1);
	    else{
	    	w.println(ans);
	    	w.println(a1 + " " + b1);
	    	w.println(a2 + " " + b2);
	    }
	    w.close();
	}
	
	public static int solve(int div,long num){
		int c = 0;
		while(num % div == 0){
			num /= div;
			c++;
		}
		return c;
	}
	public static long lp(String s){
		return Long.parseLong(s);
	}
}