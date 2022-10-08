import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			char[] s=fs.next().toCharArray();
			int x=fs.nextInt();
			int n=s.length;
			char[] ans=new char[n];
			Arrays.fill(ans, '1');
			for (int i=0; i<n; i++) {
				if (s[i]=='0') {
					if (legal(i-x, n)) ans[i-x]='0';
					if (legal(i+x, n)) ans[i+x]='0';
				}
			}
			boolean works=true;
			for (int i=0; i<n; i++) {
				if (s[i]=='1') {
					if (legal(i-x, n) && ans[i-x]=='1') continue;
					if (legal(i+x, n) && ans[i+x]=='1') continue;
					works=false;
				}
			}
			if (!works) {
				System.out.println(-1);
			}
			else {
				System.out.println(ans);
			}
		}
	}
	
	static boolean legal(int x, int n) {
		return x>=0 && x<n;
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