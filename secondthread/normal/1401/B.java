import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
/*
2 2 -> 0
2 1 -> 2
2 0 -> 0
1 2 -> -2
1 1 -> 0
1 0 -> 0
0 2 -> 0
0 1 -> 0
0 0 -> 0

1. 2s with their 1s
2. 1s with their non2s 

1
0 1 0
0 0 1
 */
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int[] a=fs.readArray(3);
			int[] b=fs.readArray(3);
			int score=Math.min(a[2], b[1]);
			a[2]-=score;
			b[1]-=score;
			a[0]+=a[2];
			a[2]=0;
			int toSub=Math.min(b[2], a[0]);
			a[0]-=toSub;
			b[2]-=toSub;
			int losePoints=Math.min(b[2], a[1]);
			System.out.println((score-losePoints)*2);
			
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