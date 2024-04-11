import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int cap1=fs.nextInt(), cap2=fs.nextInt();
			int nSs=fs.nextInt(), nAs=fs.nextInt();
			int sWeight=fs.nextInt(), aWeight=fs.nextInt();
			if (sWeight>aWeight) {
				int temp=nSs;
				nSs=nAs;
				nAs=temp;
				
				temp=sWeight;
				sWeight=aWeight;
				aWeight=temp;
			}
			long ans=0;
			for (int toKeep=0; toKeep<=nSs; toKeep++) {
				if (toKeep*(long)sWeight>cap1) continue;
				int oKeep=Math.min(nSs-toKeep, cap2/sWeight);
				int myLeft=cap1-toKeep*sWeight;
				int hisLeft=cap2-oKeep*sWeight;
				int myAs=Math.min(myLeft/aWeight, nAs);
				int hisAs=Math.min(hisLeft/aWeight, nAs-myAs);
				ans=Math.max(ans, toKeep+oKeep+myAs+hisAs);
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