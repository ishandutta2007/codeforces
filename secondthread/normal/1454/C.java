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
			int[] a=fs.readArray(n);
			for (int i=0; i<n; i++) a[i]--;
			ArrayList<Integer>[] occs=new ArrayList[n];
			for (int i=0; i<n; i++) occs[i]=new ArrayList<>();
			for (int i=0; i<n; i++) occs[a[i]].add(i);
			int best=Integer.MAX_VALUE;
			for (ArrayList<Integer> aa:occs) best=Math.min(best, tryCount(aa, n));
			System.out.println(best);
		}
	}
	
	static int tryCount(ArrayList<Integer> a, int n) {
		if (a.isEmpty()) return Integer.MAX_VALUE;
		int count=0;
		for (int i=0; i+1<a.size(); i++) if (a.get(i)+1!=(int)a.get(i+1)) count++;
		if (a.get(0)!=0) count++;
		if (a.get(a.size()-1)!=n-1) count++;
		return count;
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