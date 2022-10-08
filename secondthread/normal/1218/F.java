import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		long str=fs.nextInt();
		long[] required=new long[n];
		for (int i=0; i<n; i++) required[i]=fs.nextInt();
		long gainPerDrink=fs.nextInt();
		long[] costs=new long[n];
		for (int i=0; i<n; i++) costs[i]=fs.nextInt();
		PriorityQueue<Long> buyable=new PriorityQueue<>();
		long total=0;
		for (int i=0; i<n; i++) {
			buyable.add(costs[i]);
			while (str<required[i]) {
				if (buyable.isEmpty()) {
					System.out.println("-1");
					return;
				}
				total+=buyable.remove();
				str+=gainPerDrink;
			}
		}
		System.out.println(total);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}

}