import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*

 */
public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int length=fs.nextInt();
			int nOnes=fs.nextInt();
			long total=length*(long)(length+1)/2;
			long zeros=countZeros(length, nOnes);
			out.println(total-zeros);
		}
		out.close();
	}
	
	static long countZeros(int length, int nOnes) {
		int nZeros=length-nOnes;
//		if (nZeros==0) return 0;
		int nGroups=nOnes+1;
		int smallSize=nZeros/nGroups, bigSize=smallSize+1;
		int nBig=nZeros%nGroups, nSmall=nGroups-nBig;
		long smallWays=(smallSize)*(long)(smallSize+1)/2;
		long bigWays=(bigSize)*(long)(bigSize+1)/2;
		return smallWays*nSmall+bigWays*nBig;
	}
	
	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			while (!st.hasMoreElements())
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

		long nextLong() {
			return Long.parseLong(next());
		}
	}
	
}