import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/*
1000000000 2
1000000000 2
 */
public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		long w=fs.nextInt(), m=fs.nextInt();
		if (w<=3) {
			System.out.println("YES");
			return;
		}
		int nDigits=0;
		long val=1;
		long[] bases=new long[100];
		while (val<=2e9) {
			bases[nDigits]=val;
			val*=w;
			nDigits++;
		}
		int[] values=new int[nDigits];
		Arrays.fill(values, -1);
		long curTotal=0;
		for (int i=0; i<nDigits; i++) curTotal-=bases[i];
		boolean works=false;
		outer:while (true) {
			int index=0;
			while (true) {
				values[index]++;
				curTotal+=bases[index];
				
				
				if (values[index]!=2) {
					if (Math.abs(curTotal)==m) {
//						System.out.println("Values: "+Arrays.toString(values));
						works=true;
					}
					break;
				}
				values[index]=-1;
				curTotal-=bases[index]*3;
				index++;
				if (index==nDigits) break outer;
			}
		}
		System.out.println(works?"YES":"NO");
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