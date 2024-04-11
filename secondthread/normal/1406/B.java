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
			boolean hasZ=false;
			int[] a=fs.readArray(n);
			for (int i:a) if (i==0) hasZ=true;
			ruffleSort(a);
			for (int i=0; i<n; i++) if(i<5 || n-i-1<5) list.add(a[i]);
			n=list.size();
			long ans=Long.MIN_VALUE;
			if (hasZ) ans=0;
			for (int m=0; m<1<<n; m++) {
				if (Integer.bitCount(m)!=5) continue;
				long prod=1;
				for (int i=0; i<n; i++) {
					if ((m&(1<<i))!=0) prod*=list.get(i);
				}
				ans=Math.max(ans, prod);
			}
			System.out.println(ans);
			
		}
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