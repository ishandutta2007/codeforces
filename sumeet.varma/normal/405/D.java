import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class R238qDToySum {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
	    int s = 1000000;
	    boolean hash[] = new boolean[s+1];
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    for(int i=0;i<n;i++)
	    	hash[ip(st2.nextToken())] = true;
	        
	    ArrayList<Integer> ans = new ArrayList<Integer>();
	    
	    for(int i=1;i<=s;i++)
	    	if(hash[i] && !hash[s+1-i])
	    		ans.add(s+1-i);
	    
	    int c = 0;
	    for(int i=1;i<=s;i++){
	    	if(hash[i] && hash[s+1-i])
	    		c++;
	    }
	    
	    for(int i=1;i<=s && c>0;i++)
	    	if(!hash[i] && !hash[s+1-i]){
	    		c-=2;
	    		ans.add(i);
	    		ans.add(s+1-i);
	    	}
	    
	    w.println(ans.size());
	    for(int now : ans)
	    	w.print(now + " ");

	    
	 /*   long rhs = 0;
	    for(int i=1;i<=s;i++)
	    	if(hash[i])	rhs += s - i;
	    
	    long lhs = 0;
	    for(int now : ans)
	    	lhs += now - 1;
	    
	    System.out.println(lhs + " " + rhs);*/
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}