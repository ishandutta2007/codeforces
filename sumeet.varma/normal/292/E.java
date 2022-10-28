//package Practise;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class CopyingData {

	static int n,m;
	static int a[],b[];
	static Node segtree[];

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		m = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    StringTokenizer st3 = new StringTokenizer(br.readLine());
	    b = new int[n];
	    for(int i=0;i<n;i++)
	    	b[i] = ip(st3.nextToken());
	    
	    segtree = new Node[4*n];
	    for(int i=0;i<4*n;i++)
	    	segtree[i] = new Node(0,0);
	    
	    int count = 0;
	    
	    for(int i=0;i<m;i++){
	    	StringTokenizer st4 = new StringTokenizer(br.readLine());
	    	int type = ip(st4.nextToken());
	    	if(type == 1){
	    		int x = ip(st4.nextToken()) - 1;
	    		int y = ip(st4.nextToken()) - 1;
	    		int k = ip(st4.nextToken());
	    		update(0,n-1,0,y,y+k-1,x,++count);
	    	}
	    	else{
	    		int x = ip(st4.nextToken()) - 1;
	    		Node ans = find(0,n-1,0,x);
	    		w.println(ans.time == 0 ? b[x] : a[ans.lazy]);
	    	}
	    }
	    w.close(); 
	}
	
	public static void update(int s,int e,int c,int l,int r,int x,int count){
		//System.out.println(s + " " + e + " " + l + " " + r + " " + x);
		if(s == l && e == r)
			segtree[c] = new Node(x,count);
		else{
			int m = (s + e) / 2;
			if(l <= m && r <= m) update(s,m,2*c+1,l,r,x,count);
			if(l > m && r > m)	update(m+1,e,2*c+2,l,r,x,count);
			if(l <= m && r > m){
				update(s,m,2*c+1,l,m,x,count);
				update(m+1,e,2*c+2,m+1,r,x+m+1-l,count);
			}
		}
	}
	
	public static Node find(int s,int e,int c,int x) throws Exception{
		if(s == e)
			return segtree[c];
		int m = (s + e) / 2;
		if(x <= m)	return merge(s,x,segtree[c],find(s,m,2*c+1,x));
		else	return merge(s,x,segtree[c],find(m+1,e,2*c+2,x));
	}
	
	public static Node merge(int s,int pos,Node curr,Node down) throws Exception{
		if(curr.time == 0)	return down.copy();
		if(down.time == 0){
			Node ret = curr.copy();
			ret.lazy += pos - s;
			return ret;
		}
		if(down.time > curr.time)	return down.copy();
		if(curr.time > down.time){
			Node ret = curr.copy();
			ret.lazy += pos - s;
			return ret;
		}
		throw new Exception();
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}

class Node{
	int lazy,time; //lazy = index
	Node(int lazy,int time){
		this.lazy = lazy;
		this.time = time;
	}
	Node copy(){
		return new Node(lazy,time);
	}
	public String toString(){
		return lazy + " " + time;
	}
}