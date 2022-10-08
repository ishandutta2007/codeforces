import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int k=fs.nextInt();
		int[] a=fs.readArray(n);
		char[] line=fs.next().toCharArray();
		char last='-';
		ArrayList<Run> runs=new ArrayList<>();
		Run cur=new Run();
		for (int i=0; i<n; i++) {
			if (line[i]!=last) {
				last=line[i];
				runs.add(cur);
				cur=new Run();
			}
			cur.values.add(a[i]);
		}
		runs.add(cur);
		long ans=0;
		for (Run r:runs) ans+=r.takeUpToK(k);
		System.out.println(ans);
		
	}
	
	static class Run {
		ArrayList<Integer> values=new ArrayList<>();
		long takeUpToK(int k) {
			Collections.sort(values);
			long ans=0;
			if (values.size()<=k) {
				for (int i:values) ans+=i;
			}
			else {
				for (int i=0; i<k; i++) ans+=values.get(values.size()-1-i);
			}
			return ans;
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

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
	
}