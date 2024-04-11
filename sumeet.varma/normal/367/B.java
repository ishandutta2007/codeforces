import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class R215qDSerejaAndAnagrams {
	static Set<Integer> ans;
	static int incorrect = 0,other = 0;
	static Map<Integer,Integer> b,curr;
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int m = ip(st1.nextToken());
		int p = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    b = new TreeMap<Integer,Integer>();
	    StringTokenizer st3 = new StringTokenizer(br.readLine());
	    for(int i=0;i<m;i++){
	    	int nxt = ip(st3.nextToken());
	    	if(b.containsKey(nxt))
	    		b.put(nxt, b.get(nxt) + 1);
	    	else
	    		b.put(nxt, 1);
	    }
	    
	    curr = new TreeMap<Integer,Integer>();
	    ans = new TreeSet<Integer>();
	    for(int i=0;i<p;i++){
	    	curr.clear();
	    	incorrect = b.size();
	 	    other = 0;
	    	
	 	    int j = i,k;
	    	for(j=i,k=1;j<n && k<m;j+=p,k++)
	    		add(a[j]);
	    	int last = i;
	    	
	    	while(j < n){
	    		add(a[j]);
	    		//System.out.println(curr + " " + incorrect + " " + other);
	    		if(incorrect == 0 && other == 0)
	    			ans.add(last);
	    		remove(a[last]);
	    		j += p;
	    		last += p;
	    	}
	    }
	    
	    w.println(ans.size());
	    Iterator<Integer> it = ans.iterator();
	    while(it.hasNext())
	    	w.print((it.next() + 1) + " ");
	    w.close(); 
	}
	
	public static void add(int x){
		int prev = 0;
		if(curr.containsKey(x))	prev = curr.get(x);
		curr.put(x, prev + 1);
		int now = prev + 1;
		if(b.containsKey(x)){
			int need = b.get(x);
			if(need == prev)	incorrect++;
			if(need == now)	incorrect--;
		}
		else
			if(prev == 0)	other++;
	}

	public static void remove(int x){
		int prev = curr.get(x);
		int now = prev - 1;
		if(now == 0)
			curr.remove(x);
		else
			curr.put(x, now);
		if(b.containsKey(x)){
			int need = b.get(x);
			if(need == prev)	incorrect++;
			if(need == now)	incorrect--;
		}
		else{
			if(now == 0)
				other--;
		}
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}