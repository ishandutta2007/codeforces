import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		Random r=new Random(5);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), m=fs.nextInt();
//			int ans=solve(0, 30, n, m);
//			int n=r.nextInt(1000), m=r.nextInt(1000);
			int ans=solve(0, 30, n, m);
//			if (ans!=solveBF(n, m)) throw null;
//			System.out.println(solveBF(n, m));
			System.out.println(ans);
		}
	}
	
	// assume that there is some element in 
	// [minAns, minAns+1<<bit) that we don't hit
	static int solve(int minAns, int bit, int n, int m) {
		if (bit==-1) return minAns;
		if (bit<4) {
//			System.out.println("At: "+minAns+" "+bit);
		}
		if ((n&(1<<bit))==0) {
			//n doesn't have this bit
			//don't add bit comes first
			//check if m has everything where this is a 0
			if (m-minAns>=(1<<bit)-1) {
				//we hit everything in this range
				return solve(minAns+(1<<bit), bit-1, n, m);
			}
			else {
				return solve(minAns, bit-1, n, m);
			}
			
		}
		else {
			//adding bit comes first
			//check if m has everything where this is a 0
//			if (m>=minAns+(1<<bit)-1) {
//				solve(minAns+(1<<bit), bit+1, n, m);
//			}
//			else {
				return solve(minAns, bit-1, n, m-(1<<bit));
//			}
		}
	}
	
	static int solveBF(int n, int m) {
		boolean[] res=new boolean[1_000_000];
		for (int i=0; i<=m; i++) {
			res[n^i]=true;
		}
		for (int i=0; true; i++) if (!res[i]) return i;
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