import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.*;

public class Bits {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	
	    int n = ip(br.readLine());
	    
	    while(n-- > 0) {
	    	StringTokenizer st1 = new StringTokenizer(br.readLine());
	    	long l = lp(st1.nextToken());
	    	long r = lp(st1.nextToken());
	    	
	    	w.println(algo(l,r));
	    }
	       
	    w.close();
	        
	}
	
	public static long algo(long l,long r){
		long ans = 0;
    	char ll[] = Long.toBinaryString(l).toCharArray();
    	char rr[] = Long.toBinaryString(r).toCharArray();
    	
    	if(ll.length < rr.length){
    		ans = (1L<<(rr.length-1))-1;
    	}
    	else{
    		if(l==r)
    			ans = l;
    		else{
    			int pos = -1;
    			
    			for(int i=0;i<rr.length;i++){
    				if(ll[i] == rr[i]){
    					if(ll[i] == '1')
    						ans += (1L<<(rr.length-i-1));
    				}
    				else{
    					pos = i;
    					break;
    				}
    			}
    			
    			ans += (1L<<(rr.length-pos-1))-1;
    		}
    	}
    	
    	if(setBits(r) > setBits(ans))
			ans = r;
		if(setBits(l) == setBits(ans))
			ans = l;
		return ans;
	}
	
	public static long bf(long l,long r){
		long maxBits = setBits(l);
		long ans = l;
		for(long i=l;i<=r;i++){
			if(setBits(i)>maxBits){
				maxBits = setBits(i);
				ans = i;
			}
		}
		return ans;
	}
	
	public static long setBits(long x){
		int count = 0;
		for(int i=0;i<364;i++){
			long temp = x>>1;
			temp = temp << 1;
			if(temp!=x)	count++;
			x = x>>1;
		}
		return count;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}

	public static long lp(String s){
		return Long.parseLong(s);
	}
	
	
}