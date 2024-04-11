import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class TaskARound292Div2 {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int m = ip(st1.nextToken());
	         
	    boolean nn[] = new boolean[101];
	    boolean mm[] = new boolean[101];
	    
	  
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int totaln = ip(st2.nextToken());
	    for(int i=0;i<totaln;i++)
	    	nn[ip(st2.nextToken())] = true;
	         
	  
	    StringTokenizer st3 = new StringTokenizer(br.readLine());
	    int totalm = ip(st3.nextToken());
	    for(int i=0;i<totalm;i++)
	    	mm[ip(st3.nextToken())] = true;
	    
	    boolean der = true;
	    
	    for(int i=0;i<Math.max(n, m)*Math.max(n, m);i++){
	    	if(nn[i%n] == true || mm[i%m] == true){
	    		nn[i%n] = mm[i%m] = true;
	    	}
	    }
	    
	    for(int i=0;i<n;i++){
	    	if(nn[i] == false){
	    		der = false;
	    		break;
	    	}
	    }
	    
	    for(int i=0;i<m;i++){
	    	if(mm[i] == false){
	    		der = false;
	    		break;
	    	}
	    }
	    
	    w.println(der ? "Yes" :  "No");
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}