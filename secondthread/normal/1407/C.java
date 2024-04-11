import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
/*
1 3 2
 */
public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		boolean[] used=new boolean[n];
		int prevIndex=0;
		int[] ans=new int[n];
		for (int i=1; i<n; i++) {
			System.out.println("? "+(prevIndex+1)+" "+(i+1));
			int modValue=fs.nextInt()-1;
			System.out.println("? "+(i+1)+" "+(prevIndex+1));
			int modValue2=fs.nextInt()-1;
			if (modValue<modValue2) {
				ans[i]=modValue2;
				used[ans[i]]=false;
				prevIndex=prevIndex;
			}
			else {
				ans[prevIndex]=modValue;
				used[ans[prevIndex]]=false;
				prevIndex=i;
			}
		}
		for (int i=0; i<used.length; i++)
			if (!used[i]) ans[prevIndex]=i;
		System.out.print("! ");
		for (int i=0; i<n; i++)
			System.out.print(ans[i]+1+" ");
		System.out.println();
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