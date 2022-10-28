import java.io.*;
import java.util.*;


public class R300qA {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    String t = "CODEFORCES";
	    StringBuilder s = new StringBuilder(br.readLine().toString());
	    
	    boolean yes = false;
	    
	    for(int i=0;i<s.length();i++){
	    	for(int j=i;j<s.length();j++){
	    		StringBuilder n = new StringBuilder(s.substring(0,i)).append(s.substring(j,s.length()));
	    		if(n.toString().equals(t))
	    			yes = true;
	    		if(s.substring(0,i).equals(t))
	    			yes = true;
	    		if(s.substring(j,s.length()).equals(t))
	    			yes = true;
	    	}
	    }
	    
	    w.println(yes? "YES" : "NO");
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}