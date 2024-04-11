//package Practise;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class R207qCKnightTournament {

	static int n,m;
	static Node2 segtree[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		m = ip(st1.nextToken());
		
		segtree = new Node2[4*n];
		for(int i=0;i<4*n;i++)
			segtree[i] = new Node2(0,0);
		
		int last = -1,count = 0;
		
		for(int i=0;i<m;i++){
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			int l = ip(st2.nextToken()) - 1;
			int r = ip(st2.nextToken()) - 1;
			int x = ip(st2.nextToken()) - 1;
			++count;
			if(l != x)
				update(0,n-1,0,l,x-1,x,count);
			if(r != x)
				update(0,n-1,0,x+1,r,x,count);
			last = x;
		}
		
		for(int i=0;i<n;i++){
			if(i == last)
				w.print(0 + " ");
			else
				w.print((find(0,n-1,0,i).lazy + 1)+ " ");
		}
		
	    w.close(); 
	}
	
	public static void update(int s,int e,int c,int l,int r,int x,int count){
		if(segtree[c].time != 0)
			return;
		if(s == l && e == r){
			segtree[c].lazy = x;
			segtree[c].time = count;
		}
		else{
			int m = (s + e) / 2;
			if(l <= m && r <= m)	update(s,m,2*c+1,l,r,x,count);
			if(l > m && r > m)	update(m+1,e,2*c+2,l,r,x,count);
			if(l <=m && r > m){
				update(s,m,2*c+1,l,m,x,count);
				update(m+1,e,2*c+2,m+1,r,x,count);
			}
		}
	}
	
	public static Node2 find(int s,int e,int c,int x) throws Exception{
		if(s == e)	return segtree[c];
		int m = (s + e)/2;
		if(x <= m)	return merge(segtree[c],find(s,m,2*c+1,x));
		else	return merge(segtree[c],find(m+1,e,2*c+2,x));
	}
	
	public static Node2 merge(Node2 curr,Node2 down) throws Exception{
		if(curr.time == 0)	return down.copy();
		if(down.time == 0)	return curr.copy();
		if(curr.time < down.time)	return curr.copy();
		if(down.time < curr.time)	return down.copy();
		throw new Exception();
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}

class Node2{
	int lazy,time;
	Node2(int l,int t){
		lazy = l;
		time = t;
	}
	Node2 copy(){
		return new Node2(lazy,time);
	}
}