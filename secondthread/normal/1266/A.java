

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
/*
8
603
006
205
228
1053
0000000000000000000000000000000000000000000000
0
1
 */
public class A {

	public static void solve(FastScanner fs) {	
		int T=fs.nextInt();
		for (int i=0; i<1000; i++) {
//			System.out.println(sort(i*60+""));
		}
		for (int tt=0; tt<T; tt++) {
			int[] count=new int[10];
			char[] line=fs.next().toCharArray();
			if (line.length==1 && line[0]=='0') {
				System.out.println("red");
				continue;
			}
			int digitSum=0;
			for (int i=0; i<line.length; i++) {
				count[line[i]-'0']++;
				digitSum+=line[i]-'0';
			}
			
			if (count[0]==0 || digitSum%3!=0) {
				System.out.println("cyan");
				continue;
			}
			
			count[0]--;
			boolean works=false;
			for (int i=0; i<10; i++) {
				if (count[i]!=0 && i*10%4==0)
					works=true;
			}
			System.out.println(works?"red":"cyan");
		}
		
		
	}
	
	public static String sort(String s) {
		char[] chars=s.toCharArray();
		Arrays.sort(chars);
		s="";
		for (char c:chars) {
			s+=c;
		}
		return s;
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