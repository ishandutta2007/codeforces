import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class R129qBLittleElephantAndCards {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    int up[] = new int[n];
	    int down[] = new int[n];
	    
	    TreeMap<Integer,Integer> u = new TreeMap<Integer,Integer>();
	    TreeMap<Integer,Integer> d = new TreeMap<Integer,Integer>();
	    TreeMap<Integer,Integer> same = new TreeMap<Integer,Integer>();
	    
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	up[i] = ip(st2.nextToken());
	    	down[i] = ip(st2.nextToken());
	    	if(u.containsKey(up[i]))	u.put(up[i],u.get(up[i]) + 1);
	    	else	u.put(up[i],1);
	    	if(d.containsKey(down[i]))	d.put(down[i],d.get(down[i]) + 1);
	    	else	d.put(down[i],1);
	    	if(up[i] == down[i]){
	    		if(same.containsKey(up[i]))
	    			same.put(up[i], same.get(up[i]) + 1);
	    		else
	    			same.put(up[i], 1);
	    	}
	    }
	    
	    int ans = n+1;
	    int half = ans/2;
	    
	    for(int i=0;i<n;i++){
	    	int der = u.get(up[i]);
	    	int coverUp = d.containsKey(up[i]) ? d.get(up[i]) : 0;
	    	coverUp -= same.containsKey(up[i]) ? same.get(up[i]) : 0;
	    	if(der + coverUp>= half)
	    		ans = Math.min(ans,Math.max(0,half - der));
	    	der = u.containsKey(down[i]) ? u.get(down[i]) : 0;
	    	coverUp = d.get(down[i]);
	    	coverUp -= same.containsKey(down[i]) ? same.get(down[i]) : 0;
	    	if(der + coverUp >= half)
	    		ans = Math.min(ans,Math.max(0,half - der));
	    }
	    
	    w.println(ans > n ? -1 : ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}