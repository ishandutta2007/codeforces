import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) throws InterruptedException {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			char[] a=fs.next().toCharArray();
			int[] counts=new int[10];
			for (char c:a) counts[c-'0']++;
			Arrays.sort(counts);
			int maxLength=counts[counts.length-1];
			
			for (int first=0; first<10; first++) {
				for (int second=0; second<10; second++) {
					int len=0;
					for (char c:a) {
						if (len%2==0) {
							if (c-'0'==first) len++;
						}
						else {
							if (c-'0'==second) len++;
						}
					}
					len-=len%2;
					maxLength=Math.max(maxLength, len);
				}
			}
			System.out.println(a.length-maxLength);
			
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