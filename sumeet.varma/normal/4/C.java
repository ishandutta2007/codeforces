import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class R4QC {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    Map<String,Integer> m = new TreeMap<String,Integer>();
	    
	    for(int i=0;i<n;i++){
	    	String inp = br.readLine().trim();
	    	if(m.containsKey(inp)){
	    		int v = m.get(inp);
	    		w.println(inp + (v+1));
	    		m.put(inp, v+1);
	    	}
	    	else{
	    		w.println("OK");
	    		m.put(inp, 0);
	    	}
	    }
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}