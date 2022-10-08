import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;
/*
3 2
1 1 1
 */
public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int r=fs.nextInt();
		int[] a=fs.readArray(n);
		TreeSet<Integer> s=new TreeSet<>();
		for (int i=0; i<n;i++) if (a[i]==1) s.add(i);
		if (s.isEmpty() || s.first()>=r || s.last()<n-r) {
			System.out.println(-1);
			return;
		}
		s.add(n-1+r);
		int count=0;
		for (int i:s) {
			if (i!=n-1+r) {
				if (s.higher(i)>i+r-1+r) {
					System.out.println(-1);
					return;
				}
			}
		}
		
		//possible
		int firstUnheated=0;
		for (int i:s) {
			if (i==n-1+r) break;
			if (i-r+1>firstUnheated) {
				count++;
				firstUnheated=s.lower(i)+r;
			}
		}
		if (firstUnheated<n) count++;
		System.out.println(count);
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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