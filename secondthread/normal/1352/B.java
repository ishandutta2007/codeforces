import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=fs.nextInt();
			if (n<k) {
				System.out.println("NO");
				continue;
			}
			if ((n-(k-1))%2==1) {
				System.out.println("YES");
				for (int i=0; i<k-1; i++) System.out.print(1+" ");
				System.out.println(n-(k-1));
				continue;
			}
			if ((n-(k-1)*2)%2==0 && n>(k-1)*2) {
				System.out.println("YES");
				for (int i=0; i<k-1; i++) System.out.print(2+" ");
				System.out.println(n-(k-1)*2);
				continue;
			}
			System.out.println("NO");
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