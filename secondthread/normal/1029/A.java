import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int t=fs.nextInt();
		String line=fs.next();
		int maxPreLen=-1;
		for (int preLen=1; preLen<n; preLen++) {
			if (line.endsWith(line.substring(0, preLen))) {
				maxPreLen=preLen;
			}
		}
		if (maxPreLen==-1) {
			for (int i=0; i<t; i++) {
				System.out.print(line);
			}
			System.out.println();
		}
		else {
			String additional=line.substring(maxPreLen);
			System.out.print(line);
			for (int i=1; i<t; i++) {
				System.out.print(additional);
			}
			System.out.println();
		}
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