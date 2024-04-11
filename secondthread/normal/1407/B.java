import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			ArrayList<Integer> list=new ArrayList<>();
			for (int i=0; i<n; i++) list.add(fs.nextInt());
			int gcd=list.get(0);
			for (int i:list) gcd=Math.max(gcd, i);
			while (!list.isEmpty()) {
				int maxGCDWith=list.get(0);
				for (int i:list) {
					if (gcd(maxGCDWith, gcd)<gcd(i, gcd)) maxGCDWith=i;
				}
				if (maxGCDWith==-1) break;
				list.remove((Integer)maxGCDWith);
				System.out.print(maxGCDWith+" ");
				gcd=gcd(gcd, maxGCDWith);
			}
			for (int i:list)
				System.out.print(i+" ");
			System.out.println();
		}
	}
	
	static int gcd(int a, int b) {
		if (b==0) return a;
		return gcd(b, a%b);
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