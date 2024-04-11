import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int nBoys=fs.nextInt(), nGirls=fs.nextInt(), nPairs=fs.nextInt();
			int[] boyDegree=new int[nBoys], girlDegree=new int[nGirls];
			for (int i=0; i<nPairs; i++)
				boyDegree[fs.nextInt()-1]++;
			for (int i=0; i<nPairs; i++)
				girlDegree[fs.nextInt()-1]++;
			long ans=nC2(nPairs);
			for (int i:boyDegree) ans-=nC2(i);
			for (int i:girlDegree) ans-=nC2(i);
			System.out.println(ans);
		}
	}
	
	static long nC2(long n) {
		return n*(n-1)/2;
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}