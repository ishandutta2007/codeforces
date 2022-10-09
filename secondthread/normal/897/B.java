import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int k=fs.nextInt();
		long mod=fs.nextInt();
		long sum=0;
		for (int i=1; i<=k; i++) {
//			System.out.println(i+" "+dup(i));
			sum+=dup(i);
			sum%=mod;
		}
		System.out.println(sum);
	}
	
	private static long dup(long start) {
		String s=start+"";
		StringBuilder sb=new StringBuilder(s);
		sb.reverse();
		s+=sb.toString();
		return Long.parseLong(s);
	}

	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			try {
				br = new BufferedReader(new InputStreamReader(System.in));
				// br = new BufferedReader(new FileReader("testdata.out"));
				st = new StringTokenizer("");
			} catch (Exception e) {
				e.printStackTrace();
			}
		}

		public String next() {
			if (st.hasMoreTokens())
				return st.nextToken();
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
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

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public String nextLine() {
			String line = "";
			try {
				line = br.readLine();
			} catch (Exception e) {
				e.printStackTrace();
			}
			return line;
		}
	}
}