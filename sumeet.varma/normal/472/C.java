import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class R270QDInverseTheProblem {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
	    String name[] = new String[n];
	    String sur[] = new String[n];
	    
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	name[i] = st2.nextToken();
	    	sur[i] = st2.nextToken();
	    	if(name[i].compareTo(sur[i]) > 0){
	    		String t = sur[i];
	    		sur[i] = name[i];
	    		name[i] = t;
	    	}
	    }
	    
	    int p[] = new int[n];
	    StringTokenizer st3 = new StringTokenizer(br.readLine());
	    for(int i=0;i<n;i++)
	    	p[i] = ip(st3.nextToken()) - 1;	
	    
	    boolean yes = true;
	    
	    String prev = name[p[0]];
	    for(int i=1;i<n;i++){
	    	int c = p[i];
	    	if(name[c].compareTo(prev) > 0)
	    		prev = name[c];
	    	else if(sur[c].compareTo(prev) > 0)
	    		prev = sur[c];
	    	else{
	    		yes = false;
	    		break;
	    	}
	    }
	    
	    w.println(yes ? "YES" : "NO");
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}