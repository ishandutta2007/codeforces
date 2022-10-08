

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class G {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);	
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), nQ=fs.nextInt();
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=fs.nextInt();
			long maxPrefixSum=a[0], prefixSum=a[0];
			TreeMap<Long, Integer> prefixSums=new TreeMap<>();
			prefixSums.put(maxPrefixSum, 0);
			for (int i=1; i<n; i++) {
				prefixSum+=a[i];
				if (prefixSum>maxPrefixSum) {
					prefixSums.put(prefixSum, i);
					maxPrefixSum=prefixSum;
				}
			}
			
			for (int qq=0; qq<nQ; qq++) {
				long target=fs.nextLong();
				if (target<=prefixSums.lastKey()) {
					//want ceiling value
					out.print(prefixSums.ceilingEntry(target).getValue()+" ");
					continue;
				}
				if (prefixSum<=0) {
					out.print(-1+" ");
					continue;
				}
				long prefixSumAmount=target-prefixSums.lastKey();
				long cycles=(prefixSumAmount+prefixSum-1)/prefixSum;
				long totalTurns=cycles*n+prefixSums.ceilingEntry(target-prefixSum*cycles).getValue();
				out.print(totalTurns+" ");
			}
			out.println();
		}
		out.close();
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
		
		int nextInt () {
			return Integer.parseInt(next());
		}
		long nextLong () {
			return Long.parseLong(next());
		}
	}

}