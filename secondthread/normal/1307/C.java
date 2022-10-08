import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		char[] a=fs.next().toCharArray();
		long[] letterCounts=new long[26];
		long[][] valueCounts=new long[26][26];
		for (int i=0; i<a.length; i++) {
			int cur=a[i]-'a';
			for (int old=0; old<26; old++) {
				valueCounts[old][cur]+=letterCounts[old];
			}
			letterCounts[cur]++;
		}
		long ans=0;
		for (long l:letterCounts) ans=Math.max(ans, l);
		for (long[] ll:valueCounts)
			for (long l:ll) ans=Math.max(ans, l);
		System.out.println(ans);
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

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
	
}