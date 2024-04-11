import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt()*2, k=fs.nextInt();
			int[][] pairs=new int[k][2];
			boolean[] used=new boolean[n];
			for (int i=0; i<k; i++) {
				pairs[i]=fs.readArray(2);
				pairs[i][0]--; pairs[i][1]--;
				for (int j:pairs[i]) used[j]=true;
			}
			int[] unused=new int[n-k*2];
			int unusedInd=0;
			for (int i=0; i<n; i++) if (!used[i]) unused[unusedInd++]=i;
			int ans=0;
			int[][] make=new int[n/2][2];
			for (int i=0; i<k; i++) make[i]=pairs[i];
			for (int i=k; i<n/2; i++) {
				unusedInd=i-k;
				int from=unused[unusedInd], to=unused[unusedInd+unused.length/2];
				make[i]= new int[] {from, to};
			}
			for (int i=0; i<n/2; i++) {
//				System.out.println("Made "+Arrays.toString(make[i]));
				for (int j=i+1; j<n/2; j++) {
					int a=make[i][0], b=make[i][1], c=make[j][0], d=make[j][1];
					if (between(a, b, c) != between(a, b, d)) ans++; 
				}
			}
			System.out.println(ans);
		}
	}
	
	static boolean between(int a, int b, int c) {
		return c>Math.min(a, b) && c<Math.max(a, b);
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
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
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}