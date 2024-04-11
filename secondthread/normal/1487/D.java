import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

//Good morning!
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
//		for (int i=1; i<1000; i++) {
//			for (int j=i; j<1000; j++) {
//				for (int k=j; k<1000; k++) {
//					if (i*i+j*j==k*k && i*i==j+k) {
//						System.out.println(i+" "+j+" "+k);
//					}
//				}
//			}
//		}
		TreeMap<Long, Long> map=new TreeMap<>();
		int count=0;
		for (int i=3; i<100_000; i+=2) {
			count++;
			long c=(i*(long)i+1)/2;
//			c*=c;
			map.put(c, (long)count);
//			System.out.println(i+" "+(c-1)+" "+c);
		}
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int query=fs.nextInt();
			if (query<5) {
				System.out.println(0);
				continue;
			}
			System.out.println(map.floorEntry((long)query).getValue());
		}
			
	}

	// Use this instead of Arrays.sort() on an array of ints. Arrays.sort() is n^2
	// worst case since it uses a version of quicksort. Although this would never
	// actually show up in the real world, in codeforces, people can hack, so
	// this is needed.
	static void ruffleSort(int[] a) {
		//ruffle
		int n=a.length;
		Random r=new Random();
		for (int i=0; i<a.length; i++) {
			int oi=r.nextInt(n), temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
		}
		
		//then sort
		Arrays.sort(a);
	}
	
	// Use this to input code since it is faster than a Scanner
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