

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {

	public static void solve(FastScanner fs) {	
		int n=fs.nextInt();
		Num[] nums=new Num[n];
		for (int i=0; i<n; i++)
			nums[i]=new Num(fs.nextLong());
		Arrays.sort(nums);
		for (int i=0; i<n; i++)
			System.out.print(nums[i].val+" ");
		System.out.println();
		
	}
	
	static class Num implements Comparable<Num> {
		long val;
		int num2s=0, num3s=0;
		
		public Num(long val) {
			this.val=val;
			while (val%2==0) {
				num2s++;
				val/=2;
			}
			while (val%3==0) {
				num3s++;
				val/=3;
			}
		}

		public int compareTo(Num o) {
			return (num2s-num3s)-(o.num2s-o.num3s);
		}
	}

	
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}