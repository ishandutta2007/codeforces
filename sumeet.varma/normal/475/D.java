import java.io.*;
import java.util.*;


public class Bayan2015QDGCDqueries {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	    
	    Map<Integer,Integer> divisors = new TreeMap<Integer,Integer>();
	    Map<Integer,Integer> nextDivisors = new TreeMap<Integer,Integer>();
	    Map<Integer,Long> result = new TreeMap<Integer,Long>();
	    
	    for(int i=0;i<n;i++){
	    	Iterator<Integer> d1 = divisors.keySet().iterator();
	    	nextDivisors.clear();
	    	while(d1.hasNext()){
	    		int c = d1.next();
	    		int v = divisors.get(c);
	    		int nc = gcd(c,a[i]);
	    		if(nextDivisors.containsKey(nc))
	    			nextDivisors.put(nc, nextDivisors.get(nc)+v);
	    		else
	    			nextDivisors.put(nc, v);
	    		if(result.containsKey(nc))
	    			result.put(nc, result.get(nc)+v);
	    		else
	    			result.put(nc, (long)v);
	    	}
	    	if(nextDivisors.containsKey(a[i]))
	    		nextDivisors.put(a[i], 1 + nextDivisors.get(a[i]));
	    	else
	    		nextDivisors.put(a[i], 1);
	    	if(result.containsKey(a[i]))
	    		result.put(a[i], result.get(a[i])+ 1);
	    	else
	    		result.put(a[i], 1L);
	    	divisors.clear();
	    	divisors.putAll(nextDivisors);
	    	
	    }
	    
	    int Q = ip(br.readLine());
	    for(int q=0;q<Q;q++){
	    	int v = ip(br.readLine());
	    	if(result.containsKey(v))
	    		w.println(result.get(v));
	    	else
	    		w.println("0");
	    }
	    
	    
	    w.close(); 
	}
	
	public static int gcd(int a,int b){
		int temp=0;
		while(b!=0){
			temp = b;
			b = a%b;
			a = temp;
		}
		return a;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}