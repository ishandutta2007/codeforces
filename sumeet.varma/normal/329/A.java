import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class R192qAPurification {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    int n = ip(br.readLine());
	          
	    char a[][] = new char[n][n];
	    for(int i=0;i<n;i++)
	    	a[i] = br.readLine().toCharArray();
	        
	    boolean row[] = new boolean[n];
	    boolean col[] = new boolean[n];
	    for(int i=0;i<n;i++)
	    	for(int j=0;j<n;j++)
	    		if(a[i][j] == '.')
	    			row[i] = col[j] = true;
	    
	    boolean allRow = true,allCol = true;
	    for(int i=0;i<n;i++){
	    	allRow &= row[i];
	    	allCol &= col[i];
	    }
	    
	    if(allRow){
	    	for(int i=0;i<n;i++){
	    		for(int j=0;j<n;j++){
	    			if(a[i][j] == '.'){
	    				w.println((i+1) + " " + (j+1));
	    				break;
	    			}
	    		}
	    	}
	    }
	    else if(allCol){
	    	for(int j=0;j<n;j++){
	    		for(int i=0;i<n;i++){
	    			if(a[i][j] == '.'){
	    				w.println((i+1) + " " + (j+1));
	    				break;
	    			}
	    		}
	    	}
	    }
	    else
	    	w.println(-1);
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}