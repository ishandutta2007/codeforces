import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*

 */
public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		for (int i=1; i<10000000; i++) {
//			if (works(i+"")) System.out.println(i);
		}
//		System.out.println(works("98"));
//		System.out.println(works("998"));
//		System.out.println(works("9998"));
//		System.out.println(works("99998"));
//		System.out.println(works("999998"));
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			if (n==1) {
				out.println(-1);
			}
			else {
				for (int i=1; i<n; i++) out.print(9);
				out.println(8);
			}
		}
		out.close();
	}
	
	static boolean works(String s) {
		int val=Integer.parseInt(s);
		for (char c:s.toCharArray()) {
			if (c=='0' || val%(c-'0')==0) return false;
		}
		return true;
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		boolean hasNext() {
			String next=null;
			try {
				next = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (next==null) {
				return false;
			}
			st=new StringTokenizer(next);
			return true;
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}

}