import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++)
			a[i]=fs.nextInt()-1;
		int greatest=a[0];
		int secondGreatest=-1;
		int[] breakCount=new int[n];
		
		int[] indexOf=new int[n];
		for (int i=0; i<n; i++)
			indexOf[a[i]]=i;

		boolean[] iWouldCount=new boolean[n];
		iWouldCount[a[0]]=true;
		
		for (int i=1; i<n; i++) {
			int value=a[i];
			if (value>secondGreatest&&value<greatest) {
				breakCount[greatest]++;
//				breakCount[value]++;
//				System.out.println("found a break at "+greatest);
			}			
			if (value>greatest) {
				secondGreatest=greatest;
				greatest=value;
				iWouldCount[value]=true;
			}
			else if (value>secondGreatest) {
				secondGreatest=value;
			}
		}
//		System.out.println(Arrays.toString(iWouldCount));
//		System.out.println(Arrays.toString(breakCount));
		
		for (int i=0; i<n; i++) {
			if (iWouldCount[i])
				breakCount[i]--;
		}
		
		int best=0;
		for (int i=1; i<n; i++) {
			if (breakCount[i]>breakCount[best])
				best=i;
		}
		System.out.println(best+1);
	}
	
	
	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			br=new BufferedReader(new InputStreamReader(System.in));
			st=new StringTokenizer("");
		}
		
		public String next() {
			if (st.hasMoreTokens())
				return st.nextToken();
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
	}

}