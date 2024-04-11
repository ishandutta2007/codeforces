import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.TreeMap;
import java.util.StringTokenizer;


public class R303qD {

	static TreeMap<Integer,Integer> map;
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
	    map = new TreeMap<Integer,Integer>();
	    
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    for(int i=0;i<n;i++)
	    	add(ip(st2.nextToken()));
	        
	    int ans = 0,time = 0;
	    
	    for(int i=0;i<n;i++){
	    	if(map.higherKey(time - 1) == null)
	    		break;
	    	int v = map.higherKey(time - 1);
	    	remove(v);
	    	ans++;
	    	time += v;
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static void add(int x){
		if(map.containsKey(x))
			map.put(x, map.get(x) + 1);
		else
			map.put(x, 1);
	}
	
	public static void remove(int x){
		int curr = map.get(x);
		if(curr == 1)
			map.remove(x);
		else
			map.put(x, curr - 1);
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}