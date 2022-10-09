import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=fs.nextInt();
			int nGolds=0;
			while (nGolds+1<n && a[nGolds+1]==a[nGolds]) {
				nGolds++;
			}
			nGolds++;
			int nSilvers=nGolds;
			while (nGolds+nSilvers+1<n && a[nGolds+nSilvers+1]==a[nGolds+nSilvers]) nSilvers++;
			nSilvers++;

			int nBronzes=nGolds;
			while (nGolds+nSilvers+nBronzes+1<n && a[nGolds+nSilvers+nBronzes+1]==a[nGolds+nSilvers+nBronzes]) nBronzes++;
			nBronzes++;
			if ((nGolds+nSilvers+nBronzes)*2>n) {
				out.println("0 0 0");
			}
			else {
				int avail=nBronzes;
				while ((nGolds+nSilvers+nBronzes)*2<=n) {
					avail=nBronzes;
					while (nGolds+nSilvers+nBronzes+1<n && a[nGolds+nSilvers+nBronzes+1]==a[nGolds+nSilvers+nBronzes]) nBronzes++;
					nBronzes++;
				}
				out.println((nGolds)+" "+(nSilvers)+" "+(avail));
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
		
		int nextInt() {
			return Integer.parseInt(next());
		}
	}

}