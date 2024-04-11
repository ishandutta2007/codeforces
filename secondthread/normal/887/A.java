import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		String line=new FastScanner().next();
		int oneIndex=Integer.MAX_VALUE;
		for (int i=0; i<line.length(); i++) {
			if (line.charAt(i)=='1') {
				oneIndex=Math.min(oneIndex, i);
			}
		}
		int count=0;
		for (int i=oneIndex; i<line.length(); i++) {
			if (line.charAt(i)=='0') {
				count++;
			}
		}
		System.out.println(count>=6?"yes":"no");
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
	}
	
}