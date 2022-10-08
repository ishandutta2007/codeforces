

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*
1
5 5
BBBRR
 */
public class E {

	public static void solve(FastScanner fs) {	
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=fs.nextInt();
			char[] word=fs.next().toCharArray();
			int[] rcs=new int[n+1], gcs=new int[n+1], bcs=new int[n+1];
			for (int i=0; i<n; i++) {
				if (i<3) rcs[i+1]=word[i]=='R'?0:1;
				else rcs[i+1]=rcs[i+1-3]+(word[i]=='R'?0:1);
				if (i<3) gcs[i+1]=word[i]=='G'?0:1;
				else gcs[i+1]=gcs[i+1-3]+(word[i]=='G'?0:1);
				if (i<3) bcs[i+1]=word[i]=='B'?0:1;
				else bcs[i+1]=bcs[i+1-3]+(word[i]=='B'?0:1);
			}
			
			int ans=n;
			for (int start=0; start+k<=n; start++) {
//				System.out.println("Try 1");
				ans=Math.min(ans, eval(start, start+k-1, rcs, gcs, bcs));
//				System.out.println("Try 2");
				ans=Math.min(ans, eval(start, start+k-1, bcs, rcs, gcs));
//				System.out.println("Try 3");
				ans=Math.min(ans, eval(start, start+k-1, gcs, bcs, rcs));
			}
			out.println(ans);
		}
		out.close();
	}

	static int eval(int start, int end, int[] cs1, int[] cs2, int[] cs3) {
		int a1=every3Eval(start, end, cs1);
		int a2=every3Eval(start+1, end, cs2);
		int a3=every3Eval(start+2, end, cs3);
		int ans=a1+a2+a3;
		if (ans<3) {
//			System.out.println("Evaluating from "+start+" to "+end+" gives "+ans+" "+a1+" "+a2+" "+a3);
		}
		return a1+a2+a3;
	}
	
	static int every3Eval(int start, int end, int[] cs) {
		if (start>end) return 0;
		int length=end-start;
		length-=length%3;
		end=start+length;
//		System.out.println("CS: "+Arrays.toString(cs)+" start: "+start+" calculated end: "+end);
		return get(cs, end+1)-get(cs, start+1-3);
	}
	
	static int get(int[] cs, int i) {
		if (i<0) return 0;
		return cs[i];
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