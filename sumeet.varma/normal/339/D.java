//package Practise;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class R197qDXeniaAndBitOperations {

	static int n,m,N;
	static int a[],segtree[];
	static boolean prop[];
	static boolean or = true,xor = false;
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		m = ip(st1.nextToken());
	    N = 1<<n;
		
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[N];
	    for(int i=0;i<N;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    segtree = new int[4*N];
	    prop = new boolean[4*N];
	    build(0,N-1,0);
	    
	    for(int i=0;i<m;i++){
	    	StringTokenizer st3 = new StringTokenizer(br.readLine());
	    	int p = ip(st3.nextToken()) - 1;
	    	int b = ip(st3.nextToken());
	    	update(0,N-1,0,p,b);
	    	w.println(segtree[0]);
	    }
	    
	    w.close(); 
	}
	
	public static void build(int s,int e,int c){
		if(s == e){
			segtree[c] = a[s];
			prop[c] = xor;
			return;
		}
		int m = (s + e) >> 1;
    	build(s,m,2*c+1);
    	build(m+1,e,2*c+2);
	   	prop[c] = !prop[2*c+1];
	   	if(prop[c] == or)	segtree[c] = segtree[2*c+1] | segtree[2*c+2];
	    else 				segtree[c] = segtree[2*c+1] ^ segtree[2*c+2];
	}
	
	public static void update(int s,int e,int c,int i,int val){
		if(s == e)
			segtree[c] = val;
		else{
			int m = (s + e) >> 1;
	    	if(i <= m)	update(s,m,2*c+1,i,val);
	    	else	update(m+1,e,2*c+2,i,val);
	    	if(prop[c] == or)	segtree[c] = segtree[2*c+1] | segtree[2*c+2];
	    	else 	segtree[c] = segtree[2*c+1] ^ segtree[2*c+2];
		}
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}