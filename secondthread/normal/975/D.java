import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int a=fs.nextInt();
		fs.next();
		HashMap<Long, Integer> set=new HashMap<>();
		HashMap<Long, Integer> valuesHit=new HashMap<>();
		long ans=0;
		for (int i=0; i<n; i++) {
			fs.next();
			long dx=fs.nextLong()+1000000001l;
			long dy=fs.nextLong()+1000000001l;;
			long concat=(dx<<32l)|dy;
			long val=a*dx-dy;
			int count=set.getOrDefault(val, 0);
			int differentCount=count-valuesHit.getOrDefault(concat, 0);
			ans+=2*differentCount;
			set.put(val, count+1);
			valuesHit.put(concat, valuesHit.getOrDefault(concat, 0)+1);
		}
		System.out.println(ans);

	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
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
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
	}
	
}