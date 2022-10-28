//package Round267Div2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class G {
	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int n = ip(br.readLine());
	    int count= 0;
	    while(n-- > 0) {
	    	StringTokenizer st1 = new StringTokenizer(br.readLine());
	    	int p = ip(st1.nextToken());
	    	int q = ip(st1.nextToken());
	          
	        if(q - p >= 2)	count++;
	        
	    }
	    w.println(count);
	    w.close();
	        
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}