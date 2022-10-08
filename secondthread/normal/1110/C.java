import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
//		System.out.println(gcd(12, 8));
//		int[] powAns=new int[26];
//		for (int base=1; base<26; base++) {
//			int num=(1<<base)-1;
//			for (int x=1; x<num; x++) {
//				int cand=gcd(num^x, num&x);
//				if (num<20)
//					System.out.println(num+" "+cand);
//				powAns[base]=Math.max(powAns[base], cand);
//			}
//		}
		int[] powAns= {0, 0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};
//		System.out.println(Arrays.toString(powAns));
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int orig=fs.nextInt();
			String binary=Integer.toBinaryString(orig);
			if (binary.contains("0")) {
				System.out.println((Integer.highestOneBit(orig)<<1)-1);
			}
			else {
				System.out.println(powAns[binary.length()]);
			}
		}
	}
	
	static int gcd(int a, int b) {
		if (b==0) return a;
		return gcd(b, a%b);
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