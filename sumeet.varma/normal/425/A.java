import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


public class R243QCSerejaAndSwaps {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int k = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    long ans = a[0];
	    
	    for(int i=0;i<n;i++){
	    	for(int j=i;j<n;j++){
	    	
	    		ArrayList<Integer> list = new ArrayList<Integer>();
	    		for(int x=0;x<i;x++)
	    			list.add(a[x]);
	    		for(int x=j+1;x<n;x++)
	    			list.add(a[x]);
	    		Collections.sort(list,Collections.reverseOrder());
	    		
	    		ArrayList<Integer> orig = new ArrayList<Integer>();
	    		for(int x=i;x<=j;x++)
	    			orig.add(a[x]);
	    		Collections.sort(orig,Collections.reverseOrder());
	    		
	    		ArrayList<Integer> ansList = new ArrayList<Integer>();
	    		int c = 0,d = 0;
	    		int cs = list.size(), ds = orig.size();
	    		
	    		while(c < cs && c < k && d < ds){
	    			if(orig.get(d) >= list.get(c))
	    				ansList.add(orig.get(d++));
	    			else
	    				ansList.add(list.get(c++));
	    		}
	    		
	    		while(d<ds && orig.get(d) >= 0)
	    			ansList.add(orig.get(d++));
	    		
	    		int as = ansList.size();
	    		while(as < (j - i + 1)){
	    			ansList.add(orig.get(d++));
	    			as++;
	    		}
	    		
	    		long sum = 0;
	    		for(int x=0;x<as;x++)
	    			sum += ansList.get(x);
	    		
	    		ans = Math.max(ans, sum);
	    	}
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}