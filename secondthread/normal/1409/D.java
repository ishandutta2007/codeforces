import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class D {

	static long[] tenPow=new long[20];
	
	public static void main(String[] args) {
		tenPow[0]=1;
		for (int i=1; i<=19; i++) tenPow[i]=tenPow[i-1]*10;
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			long n=fs.nextLong();
			int reqSum=fs.nextInt();
			long ans=(n>=tenPow[18]?tenPow[19]-n:tenPow[18]-n);
			
			if (curSum(n)<=reqSum) ans=0;
			
			long used=0;
			for (int digit=0; digit<18; digit++) {
				int curVal=digitVal(n, digit);
				if (curVal==0) continue;
				long increaseBy=(10-curVal)*tenPow[digit];
				used+=increaseBy;
				n+=increaseBy;
				if (curSum(n)<=reqSum) {
					ans=Math.min(ans, used);
				}
			}
			
			System.out.println(ans);
		}
	}
	
	static int curSum(long n) {
		int ans=0;
		for (int i=0; i<19; i++) ans+=digitVal(n, i);
		return ans;
	}
	
	static int digitVal(long n, int digit) {
		if (digit<18) {
			return (int) (n/tenPow[digit]%10);
		}
		if (digit>19) throw null;
		return (int) (n/tenPow[digit]);
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