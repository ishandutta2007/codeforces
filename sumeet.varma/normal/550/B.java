import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R306qB {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int l = ip(st1.nextToken());
	    int r = ip(st1.nextToken());
	    int x = ip(st1.nextToken());
		
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    int ans = 0;
	    
	    for(int i=0;i<(1<<n);i++){
	    	int state[] = new int[n];
	    	int num = i;
	    	int count = 0;
	    	for(int j=0;j<n;j++){
	    		state[j] = num & 1;
	    		num = num >> 1;
	    		if(state[j] == 1)	count++;
	    	}
	    	
	    	if(count < 2)	continue;
	    	
	    	long sum = 0;
	    	long min = (long)1e15;
	    	long max = 0;
	    	
	    	for(int j=0;j<n;j++){
	    		if(state[j] == 1){
	    			min = Math.min(min, a[j]);
	    			max = Math.max(max, a[j]);
	    			sum += a[j];
	    		}
	    	}
	    	
	    	if(sum >= l && sum <= r && (max - min >= x))
	    		ans++;
	    	
	    }
	    
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}