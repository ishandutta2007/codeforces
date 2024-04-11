import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		if (n%2==0) {
			int sum=0;
			for (int i:a) sum^=i;
			if (sum!=0) {
				System.out.println("NO");
				return;
			}
		}
		PrintWriter out=new PrintWriter(System.out);
		out.println("YES");
		int nGroups=(n-1)/2;
		out.println(nGroups*2);
		for (int i=0; i<nGroups; i++)
			out.println((2*i+1)+" "+(2*i+2)+" "+n);
		for (int i=0; i<nGroups; i++)
			out.println((2*i+1)+" "+(2*i+2)+" "+n);
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