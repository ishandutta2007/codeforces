import java.io.*;
import java.util.*;

public class R305taskA {

	static Pair p[];
	static int segmax[],segmin[];
	static int oo = (int)(1e9),n;
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
	    
	    p = new Pair[n];
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    for(int i=0;i<n;i++)
	    	p[i] = new Pair(i,ip(st2.nextToken()));
	        
	    Arrays.sort(p);
	    
	    TreeSet<Integer> set = new TreeSet<Integer>();
	    for(int i=-1;i<=n;i++)
	    	set.add(i);
	    
	    int ans[] = new int[n+1];
	    int prev = 0;
	    
	    for(int i=0;i<n;i++){
	    	set.remove(p[i].idx);
	    	int l = set.lower(p[i].idx);
	    	int r = set.higher(p[i].idx);
	    	int curr = r - l - 1;
	    	while(curr > prev){
	    		ans[curr] = p[i].val;
	    		if(curr == prev)
	    			break;
	    		curr--;
	    	}
	    	prev = Math.max(prev, r - l - 1);
	    }
	    
	    for(int i=1;i<=n;i++)
	    	w.print(ans[i] + " ");
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	static public class Pair implements Comparable<Pair>{
		int idx,val;
		Pair(int i,int v){
			idx = i;
			val = v;
		}
		public int compareTo(Pair b){
			return -1*Integer.compare(val, b.val);
		}
	}
	
}