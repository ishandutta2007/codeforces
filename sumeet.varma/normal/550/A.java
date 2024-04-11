import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R306TaskA {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s[] = br.readLine().toCharArray();
	        
	    boolean yes1 = false;
	    boolean yes2 = false;
	    
	    for(int i=0;i<s.length -1;i++){
	    	if(!yes1 && s[i] == 'A' && s[i+1] == 'B'){
	    		yes1 = true;
	    		i++;
	    		continue;
	    	}
	    	if(!yes2 && s[i] == 'B' && s[i+1] == 'A'){
	    		yes2 = true;
	    		i++;
	    		continue;
	    	}
	    }
	    
	    if(yes1 && yes2){
	    	w.println("YES");
	    	w.close();
	    	return;
	    }
	    
	    yes1 = yes2 = false;
	    
	    for(int i=0;i<s.length -1;i++){
	    	if(!yes2 && s[i] == 'B' && s[i+1] == 'A'){
	    		yes2 = true;
	    		i++;
	    		continue;
	    	}
	    	if(!yes1 && s[i] == 'A' && s[i+1] == 'B'){
	    		if(yes2 || (i + 2) >= s.length || s[i+2] !='A'){
	    			yes1 = true;
	    			i++;
	    			continue;
	    		}
	    	}
	    }
	    
	    if(yes1 && yes2){
	    	w.println("YES");
	    	w.close();
	    	return;
	    }
	    
	    yes1 = yes2 = false;
	    
	    for(int i=0;i<s.length -1;i++){
	    	if(!yes2 && s[i] == 'B' && s[i+1] == 'A'){
	    		if(yes1 || (i + 2) >= s.length || s[i+2] !='B'){
		    		yes2 = true;
		    		i++;
		    		continue;
	    		}
	    	}
	    	if(!yes1 && s[i] == 'A' && s[i+1] == 'B'){
	    		yes1 = true;
	    		i++;
	    		continue;
	    	}
	    }
	    
	    if(yes1 && yes2){
	    	w.println("YES");
	    	w.close();
	    	return;
	    }
	    
	    
	    System.out.println("NO");
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}