import java.io.*;
import java.util.*;

public class R250qDChildAndTheSequence {

	static int n,m;
	static int a[];
	static Node segtree[];
	
	public static void main(String args[] ) throws Exception {
		   
		InputReader in = new InputReader(System.in);
	    PrintWriter w = new PrintWriter(System.out);
	    
	    n = in.nextInt();
	    m = in.nextInt();
	    
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = in.nextInt();
	    
	    segtree = new Node[4*n];
	    build(0,n-1,0);
	    
	    for(int i=0;i<m;i++){
	    	int type = in.nextInt();
	    	if(type == 1)
	    		w.println(find(0,n-1,0,in.nextInt()-1,in.nextInt()-1).sum);
	    	else if(type == 2){
	    		int l = in.nextInt() - 1;
	    		int r = in.nextInt() - 1;
	    		int x = in.nextInt();
	    		while(true){
	    			Node ans = find(0,n-1,0,l,r);
	    			if(a[ans.maxIndex] < x)
	    				break;
	    			else{
	    				a[ans.maxIndex] = a[ans.maxIndex] % x;
	    				update(0,n-1,0,ans.maxIndex);
	    			}
	    		}
	    	}
	    	else{
	    		int k = in.nextInt() - 1;
	    		int x = in.nextInt();
	    		a[k] = x;
	    		update(0,n-1,0,k);
	    	}
	    	
	    }
	    
	    w.close(); 
	}
	
	public static void build(int s,int e,int c){
		if(s == e)
			segtree[c] = new Node(s);
		else{
			int m = (s + e) >> 1;
	    	build(s,m,2*c+1);
	    	build(m+1,e,2*c+2);
	    	segtree[c] = merge(segtree[2*c+1], segtree[2*c+2]);
		}
	}
	
	
	public static void update(int s,int e,int c,int x){
		if(s == e){	
			segtree[c].sum = a[x];
			return;
		}
		int m = (s + e) >> 1;
		if(x <= m)  update(s,m,2*c+1,x);
		else		update(m+1,e,2*c+2,x);
		segtree[c] = merge(segtree[2*c+1],segtree[2*c+2]);
	}
	
	public static Node find(int s,int e,int c,int l,int r){
		if(s == l && e == r) return segtree[c].copy();
		int m = (s + e) >> 1;
		if(r <= m) return find(s,m,2*c+1,l,r);
		if(l >  m) return find(m+1,e,2*c+2,l,r);
		return merge(find(s,m,2*c+1,l,m) , find(m+1,e,2*c+2,m+1,r));
	}
	
	public static class Node{
		int maxIndex;
		long sum;
		Node(int s){
			maxIndex = s;
			sum = a[maxIndex];
		}
		Node(){}
		public Node copy(){
			Node ans = new Node();
			ans.maxIndex = this.maxIndex;
			ans.sum = this.sum;
			return ans;
		}
		public String toString(){
			return maxIndex + " " + sum;
		}
	}
	
	public static Node merge(Node x,Node y){
		Node ans = new Node();
		ans.sum = x.sum + y.sum;
		ans.maxIndex = a[x.maxIndex] >= a[y.maxIndex] ? x.maxIndex : y.maxIndex;
		return ans;
	}
	
	public static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;
		public InputReader(InputStream stream) {
			this.stream = stream;
		}
		
		public int snext() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			
			int res = 0;

			do {
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res;
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}

	
}