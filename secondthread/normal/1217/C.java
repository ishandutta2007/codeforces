import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		while (T-->0) {
			char[] line=fs.next().toCharArray();
			int n=line.length;
			int[] indexOfNextOne=new int[n];
			int lastOne=-1;
			for (int i=n-1; i>=0; i--) {
				if (line[i]=='1')
					lastOne=i;
				indexOfNextOne[i]=lastOne;
			}
			int count=0;
			for (int left=0; left<n; left++) {
				if (indexOfNextOne[left]==-1) continue;
				long val=0;
				for (int right=indexOfNextOne[left]; right<n; right++) {
					val<<=1;
					if (line[right]=='1') val++;
					int size=right-left+1;
					if (val==size) {
						count++;
//						break;
					}
					if (val>size) {
						break;
					}
				}
			}
			out.println(count);
		}
		out.close();
	}
	
//	static long value(char[] line, int from, int to) {
//		long ans=0;
//		for (int i=from; i<=to; i++) {
//			ans<<=1;
//			if (line[i]=='1')
//				ans++;
//		}
//		return ans;
//	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
	
}