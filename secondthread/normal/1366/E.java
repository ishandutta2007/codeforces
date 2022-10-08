import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
3 1
2 2 2
1
 */
public class E {
	
	static final long mod=998244353;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt();
		int[] a=fs.readArray(n), b=fs.readArray(m);
		int[] bMatchIndex=new int[m];
		int[] bStartAfter=new int[m];
		Arrays.fill(bStartAfter, -1);
		int bIndex=m-1;
		for (int i=n-1; i>=0; i--) 
			if (bIndex>=0 && a[i]==b[bIndex]) {
				bMatchIndex[bIndex--]=i;
			}
			else if (bIndex>=0 && a[i]<b[bIndex]) {
				//impossible
				System.out.println(0);
				return;
			}
			else if (bIndex+1<m && a[i]<b[bIndex+1]) {
				bStartAfter[bIndex+1]=Math.max(bStartAfter[bIndex+1], i);
			}
		
		if (bStartAfter[0]!=-1 || bIndex!=-1) {
			System.out.println(0);
			return;
		}
		
		for (int i=1; i<m; i++) {
			bStartAfter[i]=Math.max(bStartAfter[i], bMatchIndex[i-1]);
		}
		
		long ans=1;
		for (int i=1; i<m; i++) {
			int nChoices=bMatchIndex[i]-bStartAfter[i];
			ans=ans*nChoices%mod;
		}
		System.out.println(ans);
		
		
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