import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class RCCWarmup2014qCFootball {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int k = ip(st1.nextToken());
	          
	    int state[][] = new int[n][n];
	    int m = 0;
	    
	    for(int i=0;i<n;i++){
	    	int count = k;
	    	for(int j=0;j<n && count>0;j++){
	    		if(i == j)	continue;
	    		if(state[i][j] == 0 && state[j][i] == 0){
	    			state[i][j] = 1;
	    			state[j][i] = -1;
	    			count--;
	    			m++;
	    		}
	    	}
	    	if(count != 0){
	    		System.out.println(-1);
	    		return;
	    	}
	    }
	    
	    w.println(m);
	    
	    for(int i=0;i<n;i++)
	    	for(int j=0;j<n;j++)
	    		if(state[i][j] == 1)
	    			w.println((i+1) + " " + (j+1));
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}