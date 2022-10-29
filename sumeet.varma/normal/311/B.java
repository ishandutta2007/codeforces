import java.io.*;
import java.util.*;

public class R185qBCatsTransport {

	static int n,m,p;
	static long cat[];
	static long dp[][];
	static final long oo = Long.MAX_VALUE >> 1;
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
		m = in.nextInt();
		p = in.nextInt();
		
		int d[] = new int[n];
		for(int i=1;i<n;i++)
			d[i] = d[i-1] + in.nextInt();
	
		cat = new long[m + 1];//time at which i'th cat is available on 1st hill
		long total = 0;
		cat[0] = Integer.MIN_VALUE;
		
		for(int i=1;i<=m;i++){
			int h = in.nextInt() - 1;
			int t = in.nextInt();
			cat[i] = t - d[h];
			total += cat[i];
		}
		
		Arrays.sort(cat);
		
		dp = new long[2][m + 1];
		
		for(int i=0;i<=m;i++){
			dp[0][i] = i * cat[i];
			dp[1][i] = oo;
		}
		
		int b[] = new int[m + 1];
		for(int i=1;i<=m;i++)
			b[i] = -i;
		
		for(int i=2;i<=p;i++){
			
			solveConvexHull(dp[1],b,dp[0],cat,m);
			
			for(int j=1;j<=m;j++)
				dp[1][j] += j * cat[j];
			
			for(int j=1;j<=m;j++){
				dp[0][j] = dp[1][j];
				dp[1][j] = oo;
			}		
			
			dp[0][0] = 0;
		}
		
		w.println(dp[0][m] - total);
		w.close();
	}
	
	public static void solveConvexHull(long dp[],int m[],long c[],long a[],int n){
	
		MyStack s = new MyStack(n + 5);
		
		s.push(new Line(m[1],c[1]));
		int ptr = 0,len;
		dp[1] = 0;
		
		for(int i=2;i<=n;i++){
			
			len = s.size();
			ptr = Math.min(ptr, len - 1);
			
			// to find increasing order of a[i]
			while (ptr + 1 < len && s.p[ptr + 1].m * a[i] + s.p[ptr + 1].c <= s.p[ptr].m * a[i] + s.p[ptr].c) 
				++ptr;
			
			dp[i] =  s.p[ptr].eval(a[i]);
			dp[i] = Math.min(dp[i], 0);
			
			Line toAdd = new Line(m[i],c[i]);
			while(s.size() >= 2){
				Line top = s.peek();
				Line top2 = s.peek2();
				if(top2.intersects(toAdd) <= top2.intersects(top))
					s.pop();
				else
					break;
			}

			s.push(toAdd);
		}
		
	}
	
	static class Line implements Comparable<Line> {

		long m,c;
		
		Line(long m,long c){
			this.m = m;
			this.c = c;
		}
		
		public int compareTo(Line o){
			return Long.compare(o.m, m);
		}
		
		public double intersects(Line o){
			return (c - o.c) * 1.0 / (o.m - m);
		}
		
		public long eval(long x){
			return m*x + c;
		}
		
		public String toString(){
			return m + " " + c;
		}
	}

	static class MyStack{
		Line p[];
		int top;
		MyStack(int n){
			p = new Line[n];
			top = -1;
		}
		void push(Line x){
			p[++top] = x;
		}
		Line pop(){
			return p[top--];
		}
		Line peek(){
			return p[top];
		}
		Line peek2(){
			return p[top-1];
		}
		Line get(int i){
			return p[i];
		}
		boolean isEmpty(){
			return top == -1;
		}
		int size(){
			return top + 1;
		}
		void clear(){
			top = 0;
		}
		void print(){
			for(int i=0;i<=top;i++)
				System.out.print(p[i] + " ");
			System.out.println();
		}
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
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
}