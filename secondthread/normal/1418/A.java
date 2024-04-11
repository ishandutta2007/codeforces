import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			long nSticksPerMove=fs.nextInt()-1;
			long stickCostPerCoal=fs.nextInt();
			long torchesNeeded=fs.nextInt();
			long sticksNeeded=torchesNeeded+stickCostPerCoal*torchesNeeded-1;
			long nMoves=(sticksNeeded+nSticksPerMove-1)/nSticksPerMove+torchesNeeded;
			System.out.println(nMoves);
		}
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
		
		int nextInt() {
			return Integer.parseInt(next());
		}
	}

}