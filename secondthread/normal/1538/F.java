import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) {
//		System.out.println(count(9));
//		System.out.println(count(10));
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int l=fs.nextInt(), r=fs.nextInt();
			System.out.println(count(r)-count(l));
		}
	}

	//total number of digit changes to get from 0 -> x
	static long count(int x) {
		long ans=0;
		long waysToGetHere=0;
		for (char c:(x+"").toCharArray()) {
			waysToGetHere*=10;
			ans+=(c-'0')+waysToGetHere;
			waysToGetHere+=(c-'0');
		}
		return ans;
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