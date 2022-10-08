import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			char[] line=fs.next().toCharArray();
			if (line.length%2!=0) {
				System.out.println("NO");
				continue;
			}
			int counter=0;
			for (char c:line) { 
				if (c==')') counter--;
				else counter++;
				if (counter<0) {
					System.out.println("NO");
					continue outer;
				}
			}
			counter=0;
			for (int i=line.length-1; i>=0; i--) {
				char c=line[i];
				if (c=='(') counter--;
				else counter++;
				if (counter<0) {
					System.out.println("NO");
					continue outer;
				}
			}
			System.out.println("YES");
		}
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