//package Dp_Optimasition;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class ConvexHullTrick2 {

	static int n;
	static long a[],b[],dp[];
	
	public static void main(String args[]) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		
		n = Integer.parseInt(br.readLine().trim());
		
		a = new long[n];
		b = new long[n];
		
		StringTokenizer st1 = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++)
			a[i] = Integer.parseInt(st1.nextToken());
			
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++)
			b[i] = Integer.parseInt(st2.nextToken());
		
		
		/*
		long dp2[] = new long[n];
		for(int i=1;i<n;i++){
			dp2[i] = Long.MAX_VALUE;
			for(int j=0;j<i;j++)
				dp2[i] = Math.min(dp2[i], dp2[j] + b[j] * a[i]);
		}
		System.out.println(dp2[n-1]);
		*/
		
		out.println(solveConvexHull());
		
		//System.out.println(Arrays.toString(dp2));
		//System.out.println(Arrays.toString(dp));
		
		br.close();
		out.close();
	}
	
	public static long solveConvexHull(){
		dp = new long[n];
		MyStack s = new MyStack(n + 5);
		s.push(new Line(b[0], dp[0]));
		int ptr = 0, len;
		for (int i = 1; i < n; i++) {
			len = s.size();
			ptr = Math.min(ptr, len - 1);
			// to find increasing order of a[i]
			while (ptr + 1 < len && s.p[ptr + 1].m * a[i] + s.p[ptr + 1].c <= s.p[ptr].m * a[i] + s.p[ptr].c) 
				++ptr;
			dp[i] = s.p[ptr].eval(a[i]);
			Line toAdd = new Line(b[i], dp[i]);
			while (s.size() >= 2) {
				Line top = s.peek();
				Line top2 = s.peek2();
				if (top2.intersects(toAdd) <= top2.intersects(top)) s.pop();
				else break;
			}
			s.push(toAdd);
		}

		return dp[n - 1];
	}
	
	static class Line implements Comparable<Line> {
		long m,c;
		Line(long m,long c){ this.m = m; this.c = c;}
		public int compareTo(Line o){ return Long.compare(o.m, m);}
		public double intersects(Line o){ return (c - o.c) * 1.0 / (o.m - m);}
		public long eval(long x){ return m*x + c;}
	}

	static class MyStack{
		Line p[];
		int top;
		MyStack(int n){ p = new Line[n]; top = -1; }
		void push(Line x){ p[++top] = x;}
		Line pop(){ return p[top--];}
		Line peek(){ return p[top];}
		Line peek2(){ return p[top-1];}
		Line get(int i){ return p[i]; }
		boolean isEmpty(){ return top == -1;}
		int size(){ return top + 1;}
	}

}