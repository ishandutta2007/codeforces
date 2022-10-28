import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class AnyaAndGhosts {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int m = ip(st1.nextToken());
	    int t = ip(st1.nextToken());
	    int r = ip(st1.nextToken());
	    
	    if(t<r){
	    	w.println(-1);
	    }
	    else{
		    int count = 0;
		    boolean notpossible = false;
		    boolean ghost[] = new boolean[605];
		    boolean candle[] = new boolean[605];
		    int ccount = 0;
		    
		    StringTokenizer st2 = new StringTokenizer(br.readLine());
		    for(int i=0;i<m;i++){
		    	ghost[300 + ip(st2.nextToken())] = true;
		    }
		    
		    for(int i=301;i<=600;i++){
		    	if(candle[i-t-1] == true)
		    		ccount--;
		    	if(ghost[i] == true){
		    		if(ccount < r){
		    			int need = r - ccount;
		    			for(int j=1;j<=need;j++){
		    				candle[i-j] = true;
		    			}
		    			count += need;
		    			ccount = r;
		    		}
		    	}
		    }
		    
		    w.println(count);
	    }
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}