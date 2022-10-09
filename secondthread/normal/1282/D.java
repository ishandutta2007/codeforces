

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class D {

	public static void solve(FastScanner fs) {	
		String a300="", b300="";
		for (int i=0; i<300; i++) a300+='a';
		for (int i=0; i<300; i++) b300+='b';
		System.out.println(a300);
		System.out.flush();
		int nAs=300-fs.nextInt();
		if (nAs==300) return;
		
		System.out.println(b300);
		System.out.flush();
		int nBs=300-fs.nextInt();
		if (nBs==300) return;
		
		if (nAs==0) {
			String ans="";
			for (int i=0; i<nBs; i++) ans+='b';
			System.out.println(ans);
			return;
		}
		if (nBs==0) {
			String ans="";
			for (int i=0; i<nAs; i++) ans+='a';
			System.out.println(ans);
			return;
		}
		
		int n=nAs+nBs;
		boolean[] isA=new boolean[n];
		//figure out first n-1 things
		int defaultErrors=nAs;
		for (int i=0; i<n-1; i++) {
			isA[i]=true;
			System.out.println(toString(isA));
			System.out.flush();
			int curErrors=fs.nextInt();
//			System.err.println("Cur errors: "+curErrors+" default errors: "+defaultErrors);
			if (curErrors==0) {
				return;
			}
			if (curErrors<defaultErrors) {
				isA[i]=true;
				defaultErrors=curErrors;
			}
			else {
				isA[i]=false;
				//keep defaultErrors the same
			}
		}
		
		//figure out last thing
		for (boolean b:isA) {
			if (b) nAs--;
			else nBs--;
		}
		if (nAs!=0) isA[n-1]=true;
		else isA[n-1]=false;
		
		System.out.println(toString(isA));
	}

	
	static String toString(boolean[] isA) {
		StringBuilder sb=new StringBuilder("");
		for (boolean b:isA) if (b) sb.append('a'); else sb.append('b');
		return sb.toString();
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