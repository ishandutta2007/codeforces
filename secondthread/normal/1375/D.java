import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			ArrayList<Integer> ans=new ArrayList<>();
			while (!solved(a)) {
				int mex=mex(a);
				if (mex==0) {
					int putAt=0;
					for (int i=0; i<n; i++) if (a[i]!=i+1) {
						putAt=i;
						break;
					}
					ans.add(putAt);
					a[putAt]=mex;
				}
				else {
					a[mex-1]=mex;
					ans.add(mex-1);
				}
			}
			out.println(ans.size());
			for (int i:ans) out.print(i+1+" ");
			out.println();
		}
		out.close();
	}
	
	static boolean solved(int[] a) {
		for (int i=0; i<a.length; i++) if (a[i]!=i+1) return false;
		return true;
	}
	
	static int mex(int[] a) {
		int n=a.length;
		boolean[] have=new boolean[n+1];
		for (int i:a) have[i]=true;
		for (int i=0; i<=n; i++) if (!have[i]) return i;
		throw null;
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
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