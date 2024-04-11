import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=fs.nextInt();
			char[] line=fs.next().toCharArray();
			int[] fromRight=new int[n];
			int rightCount=k+1;
			for (int i=n-1; i>=0; i--) {
				if (line[i]=='1')
					rightCount=0;
				else
					rightCount++;
				fromRight[i]=rightCount;
			}
			
			int leftCount=k+1;
			int ans=0;
			for (int i=0; i<n; i++) {
				if (line[i]=='1') {
					leftCount=0;
					continue;
				}
				else {
					leftCount++;
				}
				if (leftCount>k && fromRight[i]>k) {
					ans++;
					leftCount=0;
				}
			}
			out.println(ans);
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