import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class G {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			if (n<4) {
				System.out.println(-1);
				continue;
			}
			int[] four= {2, 4, 1, 3};
			int[] five= {2, 4, 1, 3, 5};
			int[] six= {1, 4, 2, 6, 3, 5};//5 3 6 2 4 1
			int[] seven= {7, 4, 2, 6, 3, 1, 5};//5 1 3 6 2 4 7
			for (int i=0; i<seven.length; i++) seven[i]=8-seven[i];
			if (n%4==0) {
				for (int i=0; i<n; i+=4)
					for (int j=0; j<4; j++) System.out.print(i+four[j]+" ");
				System.out.println();
			}
			if (n%4==1) {
				for (int i=0; i<n-5; i+=4)
					for (int j=0; j<4; j++) System.out.print(i+four[j]+" ");
				for (int i=0; i<5; i++)
					System.out.print(n-5+five[i]+" ");
				System.out.println();
			}
			if (n%4==2) {
				for (int i=0; i<n-6; i+=4)
					for (int j=0; j<4; j++) System.out.print(i+four[j]+" ");
				for (int i=0; i<6; i++)
					System.out.print(n-6+six[i]+" ");
				System.out.println();
			}
			if (n%4==3) {
				for (int i=0; i<n-7; i+=4)
					for (int j=0; j<4; j++) System.out.print(i+four[j]+" ");
				for (int i=0; i<7; i++)
					System.out.print(n-7+seven[i]+" ");
				System.out.println();
			}
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}
	
	public void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

}