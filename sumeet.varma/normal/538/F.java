//package Round300Div12;

import java.io.*;
import java.util.*;

public class R300qF {

	static int n,count;
	static Pair p[];
	static long ans[];
	static int segtree[],a[];
	
	public static void main(String args[]) throws Exception{
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
		
		p = new Pair[n];
		for(int i=0;i<n;i++)
			p[i] = new Pair(i,in.nextInt());
		
		Arrays.sort(p);
		//System.out.println(Arrays.deepToString(p));
		
		a = new int[n];
		segtree = new int[4*n];
		ans = new long[n];
		
		for(int i=0;i<n;i++){
			for(int k=1;k<n;k++){
				int l = k*p[i].i + 1;
				int r = k*p[i].i + k;
				if(l >= n)
					break;
				r = Math.min(n-1,r);
				int t = find(0,n-1,0,l,r);
				//System.out.println(p[i].i + " " + p[i].v + " " + k + " " + l + " " + r + " " + t);
				ans[k] += t;
			}
			update(0,n-1,0,p[i].i);
		}
		
		for(int i=1;i<n;i++)
			w.print(ans[i] + " ");
		w.close();
	}
	
	
	public static int find(int s,int e,int c,int l,int r){
		if(s == l && e == r)
			return segtree[c];
		else{
			int m = (s + e) / 2;
			if(l <= m && r <= m)
				return find(s,m,2*c+1,l,r);
			else if(l > m && r > m)
				return find(m+1,e,2*c+2,l,r);
			else
				return find(s,m,2*c+1,l,m) + find(m+1,e,2*c+2,m+1,r);
		}
	}
	
	public static void update(int s,int e,int c,int i){
		if(s == e)
			segtree[c]++;
		else{
			int m = (s + e) / 2;
			if(i <= m)	update(s,m,2*c+1,i);
			else	update(m+1,e,2*c+2,i);
			segtree[c]++;
		}
	}
}

class Pair implements Comparable<Pair>{
	int v,i;
	Pair(int i,int v){
		this.i = i;
		this.v = v;
	}
	public int compareTo(Pair b) {
		if(this.v != b.v)	return this.v - b.v;
		return this.i - b.i;
	}
	public String toString(){
		return i + " " + v;
	}
}

class InputReader {

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
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = snext();
		}

		int res = 0;

		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = snext();
		} while (!isSpaceChar(c));

		return res * sgn;
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