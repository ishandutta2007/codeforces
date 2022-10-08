import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			int prev=0;
			int l=0, r=n-1;
			boolean alice=true;
			int aliceSum=0, bobSum=0;
			int nTurns=0;
			while (l<=r) {
				nTurns++;
				int eaten=0;
				if (alice) {
					while (eaten<=prev && l<=r) {
						eaten+=a[l++];
					}
					aliceSum+=eaten;
				}
				else {
					while (eaten<=prev && l<=r) {
						eaten+=a[r--];
					}
					bobSum+=eaten;
				}
				prev=eaten;
				alice^=true;
			}
			System.out.println(nTurns+" "+aliceSum+" "+bobSum);
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
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
		long nextLong() {
			return Long.parseLong(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}
	
	public void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

}