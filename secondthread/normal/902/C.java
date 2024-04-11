

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	public static void solve(FS fs) {
		int n=fs.nextInt()+1;
		int[] a=new int[n];
		for (int i=0; i<n; i++) {
			a[i]=fs.nextInt();
		}
		int breakIndex=-1;
		for (int i=0; i<n-1; i++) {
			if (a[i]>1&&a[i+1]>1) {
				breakIndex=i;
			}
		}
		if (breakIndex==-1) {
			System.out.println("perfect");
			return;
		}
		
		
		System.out.println("ambiguous");
		int[] cumSums=new int[n+1];
		for (int i=1; i<=n; i++) {
			cumSums[i]=cumSums[i-1]+a[i-1];
		}
		
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<a[i]; j++)
				System.out.print(cumSums[i]+" ");
		}
		System.out.println();
		
		for (int i=0; i<n; i++) {
			if (i==breakIndex+1) {
				System.out.print((cumSums[i]-1)+" ");
				for (int j=1; j<a[i]; j++)
					System.out.print(cumSums[i]+" ");
			}
			else {
				for (int j=0; j<a[i]; j++)
					System.out.print(cumSums[i]+" ");
			}
		}
		
	}

	
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FS scanner = new FS(System.in);
		solve(scanner);
	}
	

	private static class FS {
		BufferedReader br;
		StringTokenizer st;
		public FS(InputStream in) {
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
	}
}