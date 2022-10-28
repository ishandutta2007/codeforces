//package Practise;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class R223qESerejaAndBrackets {

	static Node3 segtree[];
	static char a[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    a = br.readLine().toCharArray();
	    int n = a.length;      
	    
	    segtree = new Node3[4*n];
	    build(0,n-1,0);
	    
	    int m = ip(br.readLine());
	    for(int i=0;i<m;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	int l = ip(st2.nextToken()) - 1;
	    	int r = ip(st2.nextToken()) - 1;
	    	w.println(find(0,n-1,0,l,r).ans);
	    }
	    
	    w.close(); 
	}
	
	public static void build(int s,int e,int c){
		if(s == e)
			segtree[c] = new Node3(0,a[s] == '(' ? 1 : 0,a[s] == ')' ? 1 : 0);
		else{
			int m = (s + e) / 2;
			build(s,m,2*c+1);
			build(m+1,e,2*c+2);
			segtree[c] = merge(segtree[2*c+1],segtree[2*c+2]);
		}
	}
	
	public static Node3 find(int s,int e,int c,int l,int r){
		if(s == l && e == r)
			return segtree[c];
		int m = (s + e) / 2;
		if(l <= m && r <= m)	return find(s,m,2*c+1,l,r);
		else if(l > m && r > m)	return find(m+1,e,2*c+2,l,r);
		else	return merge(find(s,m,2*c+1,l,m) , find(m+1,e,2*c+2,m+1,r));
	}
	
	public static Node3 merge(Node3 x,Node3 y){
		Node3 ret = new Node3(0,0,0);
		int r = Math.min(x.open,y.close);
		ret.ans = x.ans + y.ans + 2*r;
		ret.open = x.open + y.open - r;
		ret.close = x.close + y.close - r;
		return ret;
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}

class Node3{
	int ans,open,close;
	Node3(int a,int b,int c){
		ans = a;
		open = b;
		close = c;
	}
}