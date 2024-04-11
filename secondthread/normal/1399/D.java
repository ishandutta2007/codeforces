import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/*
1
4
0011
 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[] a=fs.next().toCharArray();
			ArrayDeque<Integer> zs=new ArrayDeque<>(),
					os=new ArrayDeque<>();
			int[] ans=new int[n];
			int nPiles=0;
			int index=0;
			for (char c:a) {
				if (c=='0') {
					if (zs.isEmpty()) {
						nPiles++;
						ans[index]=nPiles;
						os.addLast(nPiles);
					}
					else {
						int p=zs.removeFirst();
						ans[index]=p;
						os.addLast(p);
					}
				}
				else {
					if (os.isEmpty()) {
						nPiles++;
						ans[index]=nPiles;
						zs.addLast(nPiles);
					}
					else {
						int p=os.removeFirst();
						ans[index]=p;
						zs.addLast(p);
					}
				}
				index++;
			}
			out.println(nPiles);
			for (int i:ans) out.print(i+" ");
			out.println();
		}
		out.close();
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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