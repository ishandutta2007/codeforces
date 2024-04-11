import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class B {
	
	static long mod=998244353;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		char[] line=fs.next().toCharArray();
		int firstDiff=-1, lastDiff=-1;
		for (int i=1; i<n; i++) {
			if (line[i]!=line[0]&&firstDiff==-1)
				firstDiff=i;
		}
		for (int i=n-1; i>=0; i--) {
			if (line[i]!=line[n-1]&&lastDiff==-1)
				lastDiff=i;
		}
//		System.out.println(firstDiff+" "+lastDiff);
		if (firstDiff>lastDiff) {
			System.out.println(n+1);
		}
		else {
			long firstSize=firstDiff+1, lastSize=n-lastDiff;
//			System.out.println(firstSize+" "+lastSize);
			if (line[0]==line[n-1]) {
				System.out.println((firstSize*lastSize)%mod);
			}
			else {
				firstSize--;
				System.out.println(firstSize+lastSize);
			}
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
			
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}