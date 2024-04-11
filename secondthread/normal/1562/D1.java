import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
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

 */
public class D {

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
			
			for (int qq=0; qq<q; qq++) {
				int l=fs.nextInt()-1, r=fs.nextInt()-1;
				int ans=Math.abs(cs[r+1]-cs[l]);
//				System.out.println(Math.abs(cs[r+1]-cs[l]));
				if (ans==0)
					out.println(ans);
				else if (ans%2==0)
					out.println(2);
				else 
					out.println(1);
			}
		}
		out.close();
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