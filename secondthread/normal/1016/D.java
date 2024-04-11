import java.util.*;
import java.io.*;

public class A {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int height=fs.nextInt();
		int width=fs.nextInt();
		int[] rowXors=fs.readArray(height);
		int[] colXors=fs.readArray(width);
		int[][] matrix=new int[width][height];
		for (int i=0; i<height; i++) matrix[0][i]=rowXors[i];
		for (int x=0; x<width; x++) {
			int total=0;
			for (int y=0; y<height; y++)
				total^=matrix[x][y];
			int stillNeed=(total^colXors[x]);
			matrix[x][0]^=stillNeed;
			if (x==width-1&&stillNeed!=0) {
				System.out.println("NO");
				return;
			}
			else {
				if (stillNeed!=0)
					matrix[x+1][0]^=stillNeed;
			}
		}
		System.out.println("YES");
		for (int y=0; y<height; y++) {
			for (int x=0; x<width; x++)
				System.out.print(matrix[x][y]+" ");
			System.out.println();
		}
	}

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
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