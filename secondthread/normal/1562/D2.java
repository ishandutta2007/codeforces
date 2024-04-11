import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

/*
+--++---++-++-
+--+**--++-++-
+--+--++-++-
++---++---++

+--++---++-++-

--++---+++---


1
14 1
+--++---+++---
1 14

3
14 1
+--++---++-++-
1 14
14 3
+--++---+++---
1 14
6 12
3 10
4 10
+-+-
1 1
1 2
1 3
1 4
2 2
2 3
2 4
3 3
3 4
4 4

1
14 1
+-++---+++--
+++--+--+--+
1
14 1
+--++---++-++-
1 14

14 1
+--++---++-++-
++--++-++---+
+ --++-++---+
1
1 14

1
14 1
+--++---++-++-
1 14

 */
public class D2 {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), q=fs.nextInt();
			char[] line=fs.next().toCharArray();
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=line[i]=='+'?1:-1;
			for (int i=1; i<n; i+=2) a[i]*=-1;
			
			int[] cs=new int[n+1];
			for (int i=1; i<=n; i++) cs[i]=cs[i-1]+a[i-1];
			
			Query[] queriesO=new Query[q];
			ArrayList<Query>[] queriesAt=new ArrayList[n];
			for (int i=0; i<queriesAt.length; i++) queriesAt[i]=new ArrayList<>();
			for (int qq=0; qq<q; qq++) {
				int l=fs.nextInt()-1, r=fs.nextInt()-1;
				queriesO[qq]=new Query(l, r);
				queriesAt[l].add(queriesO[qq]);
			}
			
			int offset=(n*3+100)/2;
			int[] nextTimeSumIs=new int[n*3+100];
			nextTimeSumIs[cs[n]+offset]=n;
			for (int l=n-1; l>=0; l--) {
				nextTimeSumIs[cs[l]+offset]=l;
				for (Query qq:queriesAt[l]) {
					int r=qq.r;
					if (cs[r+1]-cs[l]==0) {
						qq.ans=0;
						continue;
					}
					if ((cs[r+1]-cs[l])%2==0) {
						qq.ans=2;
						qq.ansPositions= new int[] {-1, qq.r};
						r--;
					}
					else {
						qq.ans=1;
						qq.ansPositions= new int[] {-1};
					}
					//TODO: find position we remove
					int finalSum=cs[r+1]-cs[l];
//					System.out.println("Final sum is "+finalSum+" "+l+" "+r);
					if (finalSum%2==0) throw null;
					//if final sum == 5
					//find when it is 3
					int targetFinalSum=(finalSum/2 + finalSum%2);
					targetFinalSum+=cs[l];
					qq.ansPositions[0]=nextTimeSumIs[targetFinalSum+offset]-1;
				}
			}
			
			for (Query qq:queriesO) {
				out.println(qq.ans);
				if (qq.ans!=0) {
					for (int i:qq.ansPositions) {
						out.print(i+1+" ");
					}
					out.println();
				}
			}
		}
		out.close();
	}

	static class Query {
		int l, r, ans;
		int[] ansPositions;
		
		public Query(int l, int r) {
			this.l=l;
			this.r=r;
		}
		
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}