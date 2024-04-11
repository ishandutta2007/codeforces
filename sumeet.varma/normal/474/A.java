import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Keyboard {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    String buf = "qwertyuiopasdfghjkl;zxcvbnm,./";
	    
	    char type = br.readLine().charAt(0);
	         
	    char inp[] = br.readLine().toCharArray();
	    
	    if(type == 'L'){
		    for(int i=0;i<inp.length;i++){
		    	char c = inp[i];
		    	if(c == 'p' || c == ';' || c == '/')
		    		w.print(c);
		    	else{
		    		for(int j=0;j<buf.length();j++){
		    			if(buf.charAt(j) == c){
		    				w.print(buf.charAt(j+1));
		    				break;
		    			}
		    		}
		    	}
		    }
	    }
	    
	    else{
	    	for(int i=0;i<inp.length;i++){
		    	char c = inp[i];
		    	if(c == 'q' || c == 'a' || c == 'z')
		    		w.print(c);
		    	else{
		    		for(int j=0;j<buf.length();j++){
		    			if(buf.charAt(j) == c){
		    				w.print(buf.charAt(j-1));
		    				break;
		    			}
		    		}
		    	}
		    }
	    }
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}