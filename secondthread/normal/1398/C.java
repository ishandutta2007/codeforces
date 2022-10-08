import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;
import java.util.StringTokenizer;

/*
1
3
120
 */
public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[] line=fs.next().toCharArray();
			HashMap<Integer, Integer> countsOf=new HashMap<>();
			int[] cs=new int[n+1];
			for (int i=1; i<=n; i++) cs[i]=cs[i-1]+line[i-1]-'0';
			countsOf.put(0, 1);
			long ans=0;
			for (int i=1; i<=n; i++) {
				int toSub=i;
				int curVal=cs[i]-toSub;
//				System.out.println("At "+i+" toSub: "+toSub+" curVal: "+curVal);
				ans+=countsOf.getOrDefault(curVal, 0);
				countsOf.put(curVal, countsOf.getOrDefault(curVal, 0)+1);
//				System.out.println(ans);
			}
			System.out.println(ans);
			
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