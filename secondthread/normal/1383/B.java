import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
1
8
1 1 1 1 1 1 1 0
 */
public class RealB {
	
	public static void main(String[] args) throws InterruptedException {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			int[] counts=new int[31];
			for (int i:a) {
				for (int j=0; j<31; j++) {
					if ((i&(1<<j))!=0) {
						counts[j]++;
					}
				}
			}
			int firstOdd=-1;
			for (int i:counts) if (i%2!=0) firstOdd=i;
			if (firstOdd==-1) {
				System.out.println("DRAW");
				continue;
			}
			if (firstOdd%4==1) {
				//care here?
				System.out.println("WIN");
			}
			else {
				//care about parity of zeros
				int nZeros=n-firstOdd;
				if (nZeros%2==1) {
					System.out.println("WIN");
				}
				else {
					System.out.println("LOSE");
				}
			}
			
		}
	}
	
	void sort(int[] a) {
		ArrayList<Integer> list=new ArrayList<>();
		for (int i:a) list.add(i);
		Collections.sort(list);
		for (int i=0; i<a.length; i++) a[i]=list.get(i);
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
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}

}