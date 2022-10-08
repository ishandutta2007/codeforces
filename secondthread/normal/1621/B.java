import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int maxSize=0;
			int maxSizeCost=0;
			int leftmost=Integer.MAX_VALUE, lCost=0;
			int rightmost=Integer.MIN_VALUE, rCost=0;
			for (int i=0; i<n; i++) {
				int l=fs.nextInt(), r=fs.nextInt(), cost=fs.nextInt();
				if (r-l+1>maxSize || (r-l+1==maxSize && maxSizeCost>cost)) {
					maxSizeCost=cost;
					maxSize=r-l+1;
				}
				if (l<leftmost || (l==leftmost && cost<lCost)) {
					lCost=cost;
					leftmost=l;
				}
				if (r>rightmost|| (r==rightmost && cost<rCost)) {
					rCost=cost;
					rightmost=r;
				}
				int ans=rightmost-leftmost+1;
				if (ans==maxSize) {
					out.println(Math.min(maxSizeCost, rCost+lCost));
				}
				else {
					out.println(rCost+lCost);
				}
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