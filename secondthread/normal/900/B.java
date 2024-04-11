import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.MathContext;
import java.util.Arrays;
import java.util.StringTokenizer;

public class b {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int numerator=fs.nextInt();
		int denom=fs.nextInt();
		int digit=fs.nextInt();
		long amountLeft=numerator*10;
		for (int counter=1; counter<1000000; counter++) {
			int goesIntoTimes=(int) (amountLeft/denom);
			amountLeft-=goesIntoTimes*denom;
			if (goesIntoTimes==digit) {
				System.out.println(counter);
				return;
			}
			amountLeft*=10;
		}
		System.out.println(-1);
		return;
	}
	
	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			br=new BufferedReader(new InputStreamReader(System.in));
			st=new StringTokenizer("");
		}
		
		public String next() {
			if (st.hasMoreTokens())
				return st.nextToken();
			while (!st.hasMoreTokens())
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
	}

}