import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++)a[i]=fs.nextInt();
		ArrayList<Integer> ans=new ArrayList<>();
		outer: for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				if (a[i]==a[j])
					continue outer;
			}
			ans.add(a[i]);
		}
		System.out.println(ans.size());
		for (int i:ans)
			System.out.print(i+" ");
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
	}

}