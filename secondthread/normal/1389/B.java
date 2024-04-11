import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class B {
	
	static int[][][] dp;
	static int[] a;
	
	public static void main(String[] args) throws InterruptedException {
		Thread t=new Thread(null, null,"", 1<<28) {
			public void run() {
				m();
			}
		};
		t.start();
		t.join();
	}
	
	public static void m() {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int movesLeft=fs.nextInt();
			int leftAllowed=fs.nextInt();
			a=fs.readArray(n);
			dp=new int[leftAllowed+1][2][n];
			for (int i=0; i<dp.length; i++)
				for (int j=0; j<dp[i].length; j++)
					Arrays.fill(dp[i][j], -1);
			int ans=go(leftAllowed, 0, 0, movesLeft);
			System.out.println(ans+a[0]);
		}
	}
	
	static int go(int leftAllowed, int leftLast, int index, int movesLeft) {
		if (dp[leftAllowed][leftLast][index]!=-1) return dp[leftAllowed][leftLast][index];
		if (movesLeft==0) {
			return 0;
		}
		int best=0;
		if (leftLast==0 && index>0 && leftAllowed>0) {
			//move left
			best=Math.max(best, go(leftAllowed-1, 1, index-1, movesLeft-1)+a[index-1]);
		}
		//move right
		best=Math.max(best, go(leftAllowed, 0, index+1, movesLeft-1)+a[index+1]);
		return dp[leftAllowed][leftLast][index]=best;
	}
	
	void sort(int[] a) {
		ArrayList<Integer> list=new ArrayList<>();
		for (int i:a) list.add(i);
		Collections.sort(list);
		for (int i=0; i<a.length; i++) a[i]=list.get(i);
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
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}

}