import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;


public class R184qAStrangeAddition {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    boolean der[] = new boolean[101];
	    
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    for(int i=0;i<n;i++)
	    	der[ip(st2.nextToken())] = true;
	        
	    Set<Integer> ans = new TreeSet<Integer>();
	  
	    for(int i=0;i<=10;i++){
	    	if(der[10*i]){
	    		boolean yes = true;
	    		Iterator<Integer> it = ans.iterator();
	    		while(it.hasNext() && yes){
	    			if(!verify(it.next(),10*i))
	    				yes = false;
	    		}
	    		if(yes)
	    			ans.add(10*i);
	    	}
	    }
	    
	    for(int i=1;i<100;i++){
	    	if(i % 10 != 0 && der[i]){
	    		boolean yes = true;
	    		Iterator<Integer> it = ans.iterator();
	    		while(it.hasNext() && yes){
	    			if(!verify(it.next(),i))
	    				yes = false;
	    		}
	    		if(yes)
	    			ans.add(i);
	    	}
	    }
	    
	    w.println(ans.size());
	    Iterator<Integer> it = ans.iterator();
	    while(it.hasNext())
	    	w.print(it.next() + " ");
	    w.println();
	    w.close(); 
	}
	
	public static boolean verify(int a,int b){
		char x[] = Integer.toString(a).toCharArray();
		char y[] = Integer.toString(b).toCharArray();
		for(int i=x.length-1,j=y.length-1;i>=0 && j>=0;i--,j--){
			if(x[i] != '0' && y[j] != '0')
				return false;
		}
		return true;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}