//package Practise;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class CountWays {

	static int MOD = (int)(1e9 + 7);
	static long fact[];
	static long invFact[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    fact = new long[200201];
	    fact[0] = 1;
	    for(int i=1;i<=200200;i++)
	    	fact[i] = (i * fact[i-1]) % MOD;
	    
	    invFact = new long[200201];
	    for(int i=0;i<=200200;i++)
	    	invFact[i] = inverseEuler(fact[i]);
	    	
	    int t = 1;
	    
	    while(t-- > 0) {
	    	StringTokenizer st1 = new StringTokenizer(br.readLine());
	    	int n = ip(st1.nextToken());
	    	int m = ip(st1.nextToken());
	    	int k = ip(st1.nextToken());
	          
	    	Pair p[] = new Pair[k+1];
	    	
	    	for(int i=0;i<k;i++){
	        	StringTokenizer st2 = new StringTokenizer(br.readLine());
	        	int x = ip(st2.nextToken());
	        	int y = ip(st2.nextToken());
	        	p[i] = new Pair(x,y,find(1,1,x,y));
	    	}
	    	
	    	p[k] = new Pair(n,m,find(1,1,n,m));
	    	Arrays.sort(p);
	    	
	    	//System.out.println(Arrays.deepToString(p));
	    	
	    	for(int i=0;i<p.length;i++)
	    		for(int j=i+1;j<p.length;j++){
	    				p[j].ans -= (p[i].ans * find(p[i].x,p[i].y,p[j].x,p[j].y));
	    				p[j].ans %= MOD;
	    				if(p[j].ans < 0)
	    					p[j].ans += MOD;
	    			}
	    	w.println(p[k].ans % MOD);
	    	
	    }
	    
	    w.close(); 
	}
	
	public static long C(int n,int r){
		if(r > n)	return -1;
		if(r == 0)	return 1;
		return (fact[n] * ((invFact[r] * invFact[n-r]) % MOD)) % MOD;
	}
	
	public static long inverseEuler(long a){
		return pow(a,MOD - 2);
	}
	
	public static long pow(long a,long b){
		if(b == 0)	return 1;
		if(b == 1)	return a % MOD;
		long t = pow(a,b >> 1);
		t = (t * t) % MOD;
		if((b & 1) == 1)
			t = (t * a) % MOD;
		return t;
	}
	
	public static long find(int x1,int y1,int x2,int y2){
		if(x1 <= x2 && y1 <= y2)
			return C(x2 - x1 + y2 - y1 , x2 - x1);
		return 0;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	public static long lp(String s){
		return Long.parseLong(s);
	}

	static class Pair implements Comparable<Pair>{
		int x,y;
		long ans;
		Pair(int a,int b,long ans){
			x = a;
			y = b;
			this.ans = ans;
		}
		public int compareTo(Pair arg0) {
			if(x != arg0.x)	return Integer.compare(x, arg0.x);
			return Integer.compare(y, arg0.y);
		}
		public String toString(){
			return x + " " + y + " " + ans;
		}
	}
}