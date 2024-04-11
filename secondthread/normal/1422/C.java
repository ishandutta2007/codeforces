import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {

	public static final long mod=(int)1e9+7;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		char[] line=fs.next().toCharArray();
		int n=line.length;
		int[] values=new int[n];
		for (int i=0; i<n; i++) values[i]=line[n-1-i]-'0';
		
		long total=0;
		long tenValues=0; 
		long tenPow=1;
		long multiple=1;
		int nBiggerNumbers=n-1;
		for (int i:values) {
			//range is of bigger numbers
			total=add(total, mul(i, mul(nC2(nBiggerNumbers), tenPow)));
			
			//delete smaller numbers
			total=add(total, mul(i, tenValues));
			
			tenValues=add(tenValues, mul(tenPow, multiple));
			multiple=add(multiple, 1);
			tenPow=mul(tenPow, 10);
			nBiggerNumbers--;
		}
		System.out.println(total);
	}
	
	static long nC2(long n) {
		return add(n*(n+1)/2, 0);
	}
	
	
	static long add(long a, long b) {
		return ((a+b)%mod+mod)%mod;
	}
	
	static long mul(long a, long b) {
		return ((a*b)%mod+mod)%mod;
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