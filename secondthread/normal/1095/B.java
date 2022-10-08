import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class B {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		ArrayList<Integer> a=new ArrayList<>();
		for (int i=0; i<n; i++) a.add(fs.nextInt());
		Collections.sort(a);
		System.out.println(Math.min(a.get(n-1)-a.get(1), a.get(n-2)-a.get(0)));
	}
	static int eval(int[] a, int indexToIgnore) {
		int min=a[0], max=a[0];
		if (indexToIgnore==0)
			min=max=a[1];
		for (int i=0; i<a.length; i++) {
			if (i!=indexToIgnore) {
				min=Math.min(min, a[i]);
				max=Math.max(max, a[i]);
			}
		}
		return (max-min);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
			
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}