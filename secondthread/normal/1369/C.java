import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int k=fs.nextInt();
			int[] a=fs.readArray(n);
			int[] sizes=fs.readArray(k);
			sort(a); sort(sizes);
			long ans=0;
			for (int i=0; i<k; i++) sizes[i]--;
			for (int i=0; i<k; i++) {
				ans+=a[n-1-i];
				if (sizes[i]==0)ans+=a[n-1-i]; 
			}
			int next=0;
			for (int g=k-1; g>=0; g--) {
				int toAdd=next<n?a[next]:0;
				next+=sizes[g];
				if (sizes[g]!=0) {
					ans+=toAdd;
				}
			}
			System.out.println(ans);
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