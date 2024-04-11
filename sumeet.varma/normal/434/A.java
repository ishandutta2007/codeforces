import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class R248QCRyokoMemoryNote {

	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int m = ip(st1.nextToken());
		int n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    long sum = 0;
	    for(int i=1;i<n;i++)
	    	sum += Math.abs(a[i] - a[i-1]);
	    
	   ArrayList<Integer> s[] = new ArrayList[m+1];
	   for(int i=1;i<=m;i++)
		   s[i] = new ArrayList<Integer>();
	   
	    for(int i=0;i<n;i++){
	    	if(i - 1 >= 0 && a[i-1] != a[i])	s[a[i]].add(a[i-1]);
	    	if(i + 1 < n && a[i+1] != a[i])		s[a[i]].add(a[i+1]);
	    }
	    
	    long ans = sum;
	    for(int i=1;i<=m;i++){
	    	int siz = s[i].size();
	    	if(siz == 0)
	    		continue;
	    	Collections.sort(s[i]);
	        int median;
	    	if (siz % 2 != 0 ) 
	           median = s[i].get(siz/2);
	        else 
	           median = (s[i].get(siz/2) + s[i].get(siz/2 - 1)) / 2 ;
	        long delta = 0;
	        for(int j=0;j<siz;j++)
	        	delta += Math.abs(s[i].get(j) - median) - Math.abs(s[i].get(j) - i);
	        //System.out.println(sum + " " + delta + " " + median + " "  + i);
	        ans = Math.min(ans,sum+delta);
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}