import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
1
5
1 2 1 2 1
 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			long ans=0, base=0;
			for (int i=0; i<n; i+=2) base+=a[i];
			long minPrev=0;
			long cur=0;
			//start at even
			for (int i=0; i+1<n; i+=2) {
				cur-=a[i];
				cur+=a[i+1];
				ans=Math.max(ans, cur-minPrev);
				minPrev=Math.min(minPrev, cur);
			}
			
			minPrev=0;
			cur=0;
			//start at odd
			for (int i=1; i+1<n; i+=2) {
				cur+=a[i];
				cur-=a[i+1];
				ans=Math.max(ans, cur-minPrev);
				minPrev=Math.min(minPrev, cur);
			}
			out.println(ans+base);
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