//package Round285Div2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class TaskbChangingHandles {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int q = ip(br.readLine());
	    ArrayList<String> allOld = new ArrayList();
	    ArrayList<String> allNew = new ArrayList();
	    ArrayList<String> all = new ArrayList();
	    
	    while(q-- > 0) {
	    	StringTokenizer st1 = new StringTokenizer(br.readLine());
	    	String oldh = st1.nextToken();
	    	String newh = st1.nextToken();
	        
	    	if(!all.contains(newh)){
	    		if(allNew.contains(oldh)){
	    			int s = allNew.size();
	    			for(int i=0;i<s;i++){
	    				if(allNew.get(i).equals(oldh)){
	    					allNew.set(i, newh);
	    				}
	    			}
	    		}
	    		else{
	    			allOld.add(oldh);
	    			allNew.add(newh);
	    		}
	    		all.add(newh);
	    		all.add(oldh);
	    	}
	          
	    }
	        
	    int s = allNew.size();
	    w.println(s);
	    for(int i=0;i<s;i++)
	    	w.println(allOld.get(i) + " " + allNew.get(i));
	    w.close();
	        
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}