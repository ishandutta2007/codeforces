import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class F {

	static int[][] valueInBaseK=new int[1001][];
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		
		int n=fs.nextInt(), k=fs.nextInt();
		for (int i=0; i<valueInBaseK.length; i++) valueInBaseK[i]=inBase(i, k);
		
		int[][] ans=new int[n][];
		for (int from=n-1; from>=0; from--) {
			ans[from]=new int[from];
			for (int to=from-1; to>=0; to--) {
				ans[from][to]=firstDiff(from, to);
			}
		}
		
		out.println(firstDiff(n-1, 0)+1);
		for (int from=n-1; from>=0; from--) {
			for (int to=from-1; to>=0; to--) {
				out.print(ans[from][to]+1+" ");
			}
		}
			
		out.println();
		out.close();
	}
	
	static int firstDiff(int a, int b) {
		for (int i=11; i>=0; i--) if (valueInBaseK[a][i]!=valueInBaseK[b][i]) return i;
		throw null;
	}
	
	static int[] inBase(int x, int k) {
		int[] toReturn=new int[12];
		int exp=0;
		while (x!=0) {
			toReturn[exp++]=x%k;
			x/=k;
		}
		return toReturn;
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