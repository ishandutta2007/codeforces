import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class R205qQueue {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s[] = br.readLine().toCharArray();
	        
	    int ans[] = new int[s.length];
	    int pos = 0,prevF = 0;
	    boolean found = false;
	    
	    for(int i=0;i<s.length;i++){
	    	if(s[i] == 'F'){
	    		int need = i - pos;
	    		if(need != 0)	found = true;
	    		if(need != 0)	need += prevF;
	    		ans[i] = need;
	    		pos++;
	    		if(found)
	    			prevF++;
	    	}
	    	else{
	    		prevF--;
	    		if(prevF < 0)	prevF = 0;
	    	}
	    }
	    
	    int max = 0;
	    for(int moves : ans)
	    	max = Math.max(moves, max);
	    
	    w.println(max);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}