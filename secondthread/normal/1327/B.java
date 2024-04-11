import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*

 */
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			boolean[] used=new boolean[n];
			int unmarriedDaughter=-1;
			for (int i=0; i<n; i++) {
				int nE=fs.nextInt();
				boolean married=false;
				for (int j=0; j<nE; j++) {
					int o=fs.nextInt()-1;
					if (used[o]||married) continue;
					married=true;
					used[o]=true;
				}
				if (!married) unmarriedDaughter=i;
			}
			if (unmarriedDaughter==-1) {
				out.println("OPTIMAL");
			}
			else {
				out.println("IMPROVE");
				int other=0;
				while (used[other]) other++;
				out.println(unmarriedDaughter+1+" "+(other+1));
			}
		}
		out.close();
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		boolean hasNext() {
			String next=null;
			try {
				next = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (next==null) {
				return false;
			}
			st=new StringTokenizer(next);
			return true;
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}

}