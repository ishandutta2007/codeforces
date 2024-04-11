//package Round267Div2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Fedor {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int t = 1;
	    
	    while(t-- > 0) {
	    	StringTokenizer st1 = new StringTokenizer(br.readLine());
	    	int n = ip(st1.nextToken());
	    	int m = ip(st1.nextToken());
	    	int k = ip(st1.nextToken());
	          
	        int nums[] = new int[m+1];
	        for(int i=0;i<=m;i++)
	        	nums[i] = ip(br.readLine());
	           
	        int ans = 0;
	        for(int i=0;i<m;i++){
	        	if(setBits(nums[i]^nums[m]) <= k)	ans++;
	        }
	        w.println(ans);
	    }
	        
	    w.close();
	        
	}
	
	public static int setBits(int x){
		int count = 0;
		for(int i=0;i<31;i++){
			int temp = x>>1;
			temp = temp << 1;
			if(temp!=x)	count++;
			x = x>>1;
		}
		return count;
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}