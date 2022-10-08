import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Contrived2dProblem {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++) a[i]=fs.nextInt();
		int[] sorted=a.clone();
		sort(sorted);
		int nQ=fs.nextInt();
		long[] cs1=new long[n+1];
		long[] cs2=new long[n+2];
		for (int i=1; i<=n; i++) cs1[i]=cs1[i-1]+a[i-1];
		for (int i=1; i<=n; i++) cs2[i]=cs2[i-1]+sorted[i-1];
		for (int qq=0; qq<nQ; qq++) {
			int type=fs.nextInt(), l=fs.nextInt()-1, r=fs.nextInt()-1;
			if (type==1) {
				out.println(cs1[r+1]-cs1[l]);
			}
			else {
				out.println(cs2[r+1]-cs2[l]);
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
			while (!st.hasMoreElements())
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
	}

}