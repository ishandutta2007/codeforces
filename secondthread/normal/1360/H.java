import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
/*
1
3 3
010
001
111
 */
public class H {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int nToRemove=fs.nextInt(), nBits=fs.nextInt();
			long nLeft=(1l<<nBits)-nToRemove;
			long[] removed=new long[nToRemove];
			for (int j=0; j<nToRemove; j++) {
				char[] ans=fs.next().toCharArray();
				for (int i=0; i<nBits; i++)
					if (ans[nBits-1-i]=='1') removed[j]+=1l<<i;
			}
			Arrays.sort(removed);
			long index=(nLeft-1)/2;
//			System.out.println("Index: "+index);
			for (long i:removed) if (i<=index) index++;
			String ans=Long.toBinaryString(index);
			while (ans.length()<nBits) ans='0'+ans;
			System.out.println(ans);
		}
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