import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		int[] a=fs.readArray(n);
		int min=1, max=1_100_000_000;
		while (min!=max) {
			int mid=(min+max)/2;
//			System.out.println("Trying mid: "+mid);
			if (go(a, mid, k) || go2(a, mid, k)) {
				max=mid;
			}
			else {
				min=mid+1;
			}
		}
		System.out.println(min);
	}
	
	//possible to do a min <= legalBound
	static boolean go(int[] a, int legalBound, int k) {
		int count=0;
		int n=a.length;
		for (int i=0; i<n; i++) {
			if (count%2==0) {
				count++;
			}
			else {
				if (a[i]<=legalBound) count++;
			}
		}
//		System.out.println("In go: count: "+count);
		return count>=k;
	}
	
	static boolean go2(int[] a, int legalBound, int k) {
		int count=0;
		int n=a.length;
		for (int i=0; i<n; i++) {
			if (count%2==1) {
				count++;
			}
			else {
				if (a[i]<=legalBound) count++;
			}
		}
//		System.out.println("In go2: count: "+count);
		return count>=k;
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