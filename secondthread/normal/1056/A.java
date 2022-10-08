import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) throws FileNotFoundException {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		HashSet<Integer> possible=new HashSet<>();
		for (int i=0; i<n; i++) {
			int r=fs.nextInt();
			HashSet<Integer> contained=new HashSet<>();
			for (int j=0; j<r; j++) {
				if (i==0)
					possible.add(fs.nextInt());
				else
					contained.add(fs.nextInt());
			}
			if (i!=0) {
				HashSet<Integer> newhs=new HashSet<>();
				for (int k:possible)
					if (contained.contains(k))
						newhs.add(k);
				possible=newhs;
			}
		}
		for (int i:possible)
			System.out.print(i+" ");
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