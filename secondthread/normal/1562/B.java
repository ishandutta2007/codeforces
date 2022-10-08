import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class B {

	static boolean[] isPrime=new boolean[1_000_00];
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		for (int i=0; i<isPrime.length; i++)
			isPrime[i]=isPrime(i);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			fs.next();
			String big=fs.next();
			int ans=0;
			for (int small=1; small<100_000; small++) {
				if (isPrime[small]) continue;
				if (!contains(big, small)) continue;
				ans=small;
				break;
			}
			System.out.println((""+ans).length());
			System.out.println(ans);			
		}
	}
	
	static boolean contains(String s, int x) {
		String me=x+"";
		int meInd=0;
		for (char c:s.toCharArray()) {
			if (c==me.charAt(meInd)) meInd++;
			if (meInd==me.length()) return true;
		}
		return meInd==me.length();
	}
	
	static boolean isPrime(int x) {
		if (x<2) return false;
		for (int i=2; (i*(long)i)<=x; i++) {
			if (x%i==0) return false;
		}
		return true;
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