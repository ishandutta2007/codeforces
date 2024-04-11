import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class D {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			long l=fs.nextLong()-1, r=fs.nextLong()-1;
			for (int start=1; start<=n; start++) {
				if (start!=n) {
					int left=n-start;
					int curSize=left*2;
					if (l>=curSize || r<0) {
						l-=curSize;
						r-=curSize;
						continue;
					}
					ArrayList<Integer> gen=new ArrayList<>();
					for (int o=start+1; o<=n; o++) {
						gen.add(start);
						gen.add(o);
					}
					for (int i:gen) {
						if (l<=0&&r>=0) {
							out.print(i+" ");
						}
						l--;
						r--;
					}
				}
				else {
					//TODO: this
					ArrayList<Integer> gen=new ArrayList<>();
					gen.add(1);
					for (int i:gen) {
						if (l<=0&&r>=0) {
							out.print(i+" ");
						}
						l--;
						r--;
					}
				}
			}
			out.println();
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