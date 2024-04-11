import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		long[] vols=new long[n];
		ArrayList<Long> caps=new ArrayList<>();
		long totalVol=0;
		for (int i=0; i<n; i++) {
			vols[i]=fs.nextInt();
			totalVol+=vols[i];
		}
		for (int i=0; i<n; i++) {
			caps.add((long)fs.nextInt());
		}
		Collections.sort(caps);
		long total=caps.get(caps.size()-1)+caps.get(caps.size()-2);
		if (totalVol<=total) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
	}

	private static class FastScanner {
		private BufferedReader br;
		private StringTokenizer st;
		
		public FastScanner() {
			st=new StringTokenizer("");
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next() {
			if (st.hasMoreTokens()) {
				return st.nextToken();
			}
			while (!st.hasMoreTokens()) {
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return null;
		}
	}
	
}