import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R297TaskA {

public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    char a[] = br.readLine().toCharArray();
	    int n = a.length;
	    int count[] = new int[n];
	    
	    int m = ip(br.readLine());
	    StringTokenizer st = new StringTokenizer(br.readLine());
	    
	    for(int t=0;t<m;t++){
	    	count[ip(st.nextToken())-1]++;
	    }
	        
	    int tc = 0;
	    for(int i=0;i<n/2;i++){
	    	tc += count[i];
	    	if(tc % 2 != 0){
	    		char t = a[i];
	    		a[i] = a[n-1-i];
	    		a[n-1-i] = t;
	    	}
	    }
	    
	    w.println(new String(a));

	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}