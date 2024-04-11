import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

/* 
 * Subscribe to galen_colin!
 * https://tinyurl.com/galencolin
*/

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		testcase: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int nCuts=0;
			int[] a=fs.readArray(n);
			for (int i=0; i<n; i++) a[i]--;
			int[] freq=new int[n];
			for (int i:a) freq[i]++;
			for (int i:freq) {
				if (i>(n+1)/2) {
					System.out.println(-1);
					continue testcase;
				}
			}
			
			//otherwise possible
			ArrayList<Integer> endPoints=new ArrayList<>();
			endPoints.add(a[0]);
			endPoints.add(a[n-1]);
			for (int i=0; i+1<n; i++) {
				if (a[i]==a[i+1]) {
					endPoints.add(a[i]);
					endPoints.add(a[i+1]);
					nCuts++;
				}
			}
			Arrays.fill(freq, 0);
			for (int i:endPoints) freq[i]++;
			int max=freq[0];
			for (int i:freq) max=Math.max(max, i);
			int nOthers=endPoints.size()-max;
			//max and nOthers are always same parity
			nCuts+=Math.max(0, (max-nOthers-2)/2);
			System.out.println(nCuts);
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