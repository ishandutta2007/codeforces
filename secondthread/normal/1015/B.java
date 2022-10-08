import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class B {
	
	static ArrayDeque<Integer> swaps=new ArrayDeque<>();

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		char[] a=fs.next().toCharArray(), b=fs.next().toCharArray();
		int[] cs=new int[26];
		for (char c:a)
			cs[c-'a']++;
		for (char c:b)
			cs[c-'a']--;
		for (int i:cs) {
			if (i!=0) {
				System.out.println(-1);
				return;
			}
		}
		outer:for (int toFix=0; toFix<n; toFix++) {
			for (int other=toFix; other<n; other++) {
				if (a[other]==b[toFix]) {
					for (int k=other-1; k>=toFix; k--) {
						swap(k, a);
					}
					continue outer;
				}
			}
		}
		System.out.println(swaps.size());
		while (!swaps.isEmpty())
			System.out.print(swaps.remove()+" ");
		System.out.println();
	}
	
	static void swap(int pos, char[] a) {
		swaps.addLast(pos+1);
		char temp=a[pos];
		a[pos]=a[pos+1];
		a[pos+1]=temp;
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