

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=1;
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), q=fs.nextInt();
			int[] a=fs.readArray(n);
			int onesCount=0;
			for (int i:a) if (i==1) onesCount++;
			for (int qq=0; qq<q; qq++) {
				int type=fs.nextInt();
				int id=fs.nextInt()-1;
				if (type==1) {
					if (a[id]==1) onesCount--;
					else onesCount++;
					a[id]=1-a[id];
				}
				else {
					if (id<onesCount) {
						out.println(1);
					}
					else {
						out.println(0);
					}
				}
			}
		}
		out.close();
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int[] readArray(int n) {
			int[] a=new int[n]; 
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		int nextInt () {
			return Integer.parseInt(next());
		}
	}

}