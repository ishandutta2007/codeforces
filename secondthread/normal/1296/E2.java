import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		char[] line=fs.next().toCharArray();
		int[] ans=new int[n];
		SegTree st=new SegTree();
		int max=1;
		for (int i=n-1; i>=0; i--) {
			ans[i]=st.rangeMax(0, line[i]-'a'-1);
			st.pointUpdate(line[i]-'a', ans[i]+1);
			max=Math.max(max, ans[i]+1);
		}
		System.out.println(max);
		for (int i=0; i<n; i++) System.out.print(ans[i]+1+" ");
		System.out.println();
	}
	
	static class SegTree {
		int[] values=new int[26];
		int rangeMax(int l, int r) {
			if (l>r) return 0;
			int max=values[l];
			for (int i=l; i<=r; i++) max=Math.max(max, values[i]);
			return max;
		}
		
		void pointUpdate(int x, int to) {
			values[x]=to;
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
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

	}

}