import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class R29qCMailStamps {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    Map<Integer,Integer> first = new HashMap<Integer,Integer>();
	    Map<Integer,Integer> second = new HashMap<Integer,Integer>();
	    
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	int u = ip(st2.nextToken());
	    	int v = ip(st2.nextToken());
	    	if(first.containsKey(u))
	    		second.put(u, v);
	    	else
	    		first.put(u, v);
	    	if(first.containsKey(v))
	    		second.put(v, u);
	    	else
	    		first.put(v, u);
	    }
	    
	    Iterator<Integer> it = first.keySet().iterator();
	    int start = -1;
	    while(it.hasNext()){
	    	int curr = it.next();
	    	if(!second.containsKey(curr)){
	    		start = curr;
	    		break;
	    	}
	    }
	    
	    if(start == -1)
	    	throw new Exception();
	    
	    Set<Integer> vis = new HashSet<Integer>();
	    vis.add(start);
	    
	    w.print(start + " ");
	    int next = first.get(start);
	    w.print(next + " ");
	    vis.add(next);
	    
	    boolean found = true;
	    while(found){
	    	found = false;
	    	int f = first.get(next);
	    	if(!vis.contains(f)){
	    		w.print(f + " ");
	    		found = true;
	    		next = f;
	    		vis.add(next);
	    	}
	    	else{
	    		int s = second.containsKey(next) ? second.get(next) : -1;
	    		if(s == -1)
	    			break;
	    		if(!vis.contains(s)){
	    			w.print(s + " ");
	    			found = true;
	    			next = s;
	    			vis.add(s);
	    		}
	    	}
	    }
	    
	    w.println();
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}