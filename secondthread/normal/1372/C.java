import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
1
4
1 3 2 4
 */
public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			for (int i=0; i<n; i++) a[i]--;
			//zero
			boolean works=true, works2=true;
			for (int i=0; i<n; i++) 
				if (a[i]!=i) works=false;
			
			int firstWrong=n, lastWrong=0;
			for (int i=0; i<n; i++) {
				if (a[i]!=i) {
					firstWrong=Math.min(firstWrong, i);
					lastWrong=Math.max(lastWrong, i);
				}
			}
			for (int i=firstWrong; i<=lastWrong; i++) {
				if (a[i]==i) works2=false;
			}
			
			if (works) {
				System.out.println(0);
			}
			else if (works2) {
				System.out.println(1);
			}
			else {
				System.out.println(2);
			}
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