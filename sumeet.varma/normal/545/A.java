import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R303qA {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    boolean bad[] = new boolean[n];
	          
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	for(int j=0;j<n;j++){
	    		int curr = ip(st2.nextToken());
	    		if(curr <= 0)	continue;
	    		else if(curr == 1)	bad[i] = true;
	    		else if(curr == 2)  bad[j] = true;
	    		else if(curr == 3){
	    			bad[i] = true;
	    			bad[j] = true;
	    		}
	    	}
	    }
	    
	    int ans = n;
	    for(boolean why : bad)
	    	if(why)	ans--;
	    
	    w.println(ans);
	    
	    for(int i=0;i<n;i++){
	    	if(!bad[i])
	    		w.print((i+1) + " ");
	    }
	    w.println();
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}