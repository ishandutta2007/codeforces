import java.io.*;
import java.util.*;

public class R63qESubsegments {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int k = ip(st1.nextToken());
	          
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = -1*ip(br.readLine());
	        
	    TreeSet<Integer> set = new TreeSet<Integer>();
	    Map<Integer,Integer> map = new HashMap<Integer,Integer>();
	    
	    for(int i=0;i<k;i++){
	    	if(map.containsKey(a[i])){
	    		int curr = map.get(a[i]);
	    		map.put(a[i], curr + 1);
	    		if(curr == 1)
	    			set.remove(a[i]);
	    	}
	    	else{
	    		set.add(a[i]);
	    		map.put(a[i], 1);
	    	}
	    }
	    
	    if(set.isEmpty())
	    	w.println("Nothing");
	    else
	    	w.println(-1*set.first());
	    
	    for(int i=k;i<n;i++){
	    	int prev = a[i-k];
	    	int prevCount = map.get(prev);
	    	int nowCount = prevCount - 1;
	    	if(nowCount == 0){
	    		map.remove(prev);
	    		set.remove(prev);
	    	}
	    	else if(nowCount == 1){
	    		map.put(prev, nowCount);
	    		set.add(prev);
	    	}
	    	else
	    		map.put(prev, nowCount);
	    	
	    	int dis = a[i];
	    	
	    	if(map.containsKey(dis)){
	    		int curr = map.get(dis);
	    		map.put(dis, curr + 1);
	    		if(curr == 1)
	    			set.remove(dis);
	    	}
	    	else{
	    		set.add(dis);
	    		map.put(dis, 1);
	    	}
	    	if(set.isEmpty())
	    		w.println("Nothing");
	    	else
	    		w.println(-1*set.first());
	    }
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}