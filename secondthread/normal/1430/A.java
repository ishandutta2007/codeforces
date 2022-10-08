import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		boolean[] possible=new boolean[1010];
		possible[0]=true;
		for (int i=0; i<1000; i++) {
			if (!possible[i]) continue;
			possible[i+3]=possible[i+5]=possible[i+7]=true;
		}
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			if (!possible[n]) System.out.println(-1);
			else {
				int[] counts=new int[3];
				while (n!=0) {
					if (possible[n-3]) {
						counts[0]++;
						n-=3;
					}
					else if (possible[n-5]) {
						counts[1]++;
						n-=5;
					}
					else {
						counts[2]++;
						n-=7;
					}
				}
				System.out.println(counts[0]+" "+counts[1]+" "+counts[2]);
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