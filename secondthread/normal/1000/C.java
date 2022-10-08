import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		long[] starts=new long[n];
		long[] ends=new long[n];
		for (int i=0; i<n; i++) {
			starts[i]=fs.nextLong();
			ends[i]=fs.nextLong()+1;
		}
		
		HashSet<Long> crits=new HashSet<>();
		for (long i:starts) crits.add(i);
		for (long i:ends) crits.add(i);
		
		ArrayList<Long> sorted=new ArrayList<>();
		for (long l:crits) sorted.add(l);
		Collections.sort(sorted);
		
		HashMap<Long, Integer> compress=new HashMap<>();
		HashMap<Integer, Long> decompress=new HashMap<>();
		for (int i=0; i<sorted.size(); i++) {
			compress.put(sorted.get(i), i);
			decompress.put(i, sorted.get(i));
		}
		
		int size=sorted.size();
		int[] delta=new int[size];
		for (int i=0; i<n; i++) {
			delta[compress.get(starts[i])]++;
			delta[compress.get(ends[i])]--;
		}
		int[] cs=new int[size];
		cs[0]=delta[0];
		for (int i=1; i<size; i++) cs[i]=delta[i]+cs[i-1];
		
		long[] count=new long[n+1];
		for (int i=0; i<size-1; i++) {
			int overlap=cs[i];
			long dist=decompress.get(i+1)-decompress.get(i);
			count[overlap]+=dist;
		}
		for (int i=1; i<=n; i++) System.out.print(count[i]+" ");
		System.out.println();
		
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