import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		long times=fs.nextLong();
		int smaller=2;
		while (toTen(smaller)<times) {
			smaller++;
		}
		smaller--;
		int nBigger=0;
		while (withNBigger(smaller, nBigger)<times) {
			nBigger++;
		}
		char[] word="codeforces".toCharArray();
		for (int i=0; i<word.length; i++) {
			if (i<nBigger) {
				for (int j=0; j<=smaller; j++) System.out.print(word[i]);
			}
			else {
				for (int j=0; j<smaller; j++) System.out.print(word[i]);
			}
		}
		System.out.println();
	}
	
	static long withNBigger(int smaller, int nBigger) {
		long base=toTen(smaller);
		for (int i=0; i<nBigger; i++) {
			base/=smaller;
			base*=smaller+1;
		}
		return base;
	}
	
	static long toTen(long base) {
		long ans=1;
		for (int i=0; i<10; i++) ans*=base;
		return ans;
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