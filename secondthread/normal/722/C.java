import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs = new FastScanner();
		int n=fs.nextInt();
		long[] a=new long[n];
		for (int i=0; i<n; i++) a[i]=fs.nextLong();
		DisjointSet dj=new DisjointSet(n, a);
		int[] perm=fs.readArray(n);
		for (int i=0; i<n; i++) perm[i]--;
		boolean[] alive=new boolean[n];
		long[] ans=new long[n];
		long best=0;
		for (int i=n-1; i>=0; i--) {
			alive[perm[i]]=true;
			if (perm[i]>0 && alive[perm[i]-1]) dj.union(perm[i], perm[i]-1);
			if (perm[i]+1<n && alive[perm[i]+1]) dj.union(perm[i], perm[i]+1);
			ans[i]=Math.max(best, dj.sum[dj.find(perm[i])]);
			best=Math.max(best, ans[i]);
		}
		for (int i=0; i+1<n; i++) {
			System.out.println(ans[i+1]);
		}
		System.out.println(0);
	}

	static class DisjointSet {
		int[] s;
		long[] sum;

		public DisjointSet(int n, long[] sum) {
			Arrays.fill(s = new int[n], -1);
			this.sum = sum;
		}

		public int find(int i) {
			return s[i] < 0 ? i : (s[i] = find(s[i]));
		}

		public boolean union(int a, int b) {
			if ((a = find(a)) == (b = find(b)))
				return false;
			if (s[a] == s[b])
				s[a]--;
			if (s[a] <= s[b]) {
				s[b] = a;
				sum[a]+=sum[b];
			} else {
				s[a] = b;
				sum[b]+=sum[a];
			}
			return true;
		}
	}

	static final Random random = new Random();

	static void ruffleSort(int[] a) {
		int n = a.length;// shuffle, then sort
		for (int i = 0; i < n; i++) {
			int oi = random.nextInt(n), temp = a[oi];
			a[oi] = a[i];
			a[i] = temp;
		}
		Arrays.sort(a);
	}

	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			while (!st.hasMoreTokens())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] readArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

}