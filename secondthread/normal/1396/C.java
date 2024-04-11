import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class C {

	static int nRooms;
	static long[][] dp;
	static long[] dp2;
	static long r1, r2, r3;
	static long travelTime;
	static int[] nEnemies;
	
	public static void main(String[] args) throws InterruptedException {
		Thread t=new Thread(null, null, "", 1<<29) {
			public void run() {
				new C();
			}
		};
		t.start();
		t.join();
	}
	
	public C() {
		FastScanner fs=new FastScanner();
		nRooms=fs.nextInt();
		r1=fs.nextLong();
		r2=fs.nextLong();
		r3=fs.nextLong();
		travelTime=fs.nextLong();
		nEnemies=fs.readArray(nRooms);
		dp=new long[nRooms+1][2];
		dp2=new long[nRooms+1];
		Arrays.fill(dp2, -1);
		for (int i=0; i<dp.length; i++) {
			Arrays.fill(dp[i], -1);
		}
		long ans=go(0, 0);
		System.out.println(ans);
	}
	
	static long go(int position, int freeGoBack) {
		if (position==nRooms) {
			return -travelTime;
		}
		if (dp[position][freeGoBack]!=-1) return dp[position][freeGoBack];
//		long best=(long)1e18;
		long best=go2(position);
		if (freeGoBack==1) {
			//P P P P P [AWG]
			best=Math.min(best, r1*nEnemies[position]+r3+travelTime+go(position+1, 0));
			
			//P P P P P [P, 2 travels, P]
			//get 2*travelTime for free
			best=Math.min(best, r1*(nEnemies[position]+1)+r1+travelTime+go(position+1, 0));
			
			//L L L L L [L, 2 travels, P]
			//get 2*travelTime for free
			best=Math.min(best, r2+r1+travelTime+go(position+1, 0));
		}
		else {
			//P P P P P [AWG]
			best=Math.min(best, r1*nEnemies[position]+r3+travelTime+go(position+1, 0));
			
			//P P P P P [P, 2 travels, P]
			best=Math.min(best, r1*(nEnemies[position]+1)+2*travelTime+r1+travelTime+go(position+1, 1));
			
			//L L L L L [L, 2 travels, P]
			best=Math.min(best, r2+2*travelTime+r1+travelTime+go(position+1, 1));
		}
//		System.out.println("Dp at position "+position+" freeBack: "+freeGoBack+" = "+best);
		return dp[position][freeGoBack]=best;
	}
	
	static long go2(int position) {
		if (dp2[position]!=-1) return dp2[position];
		long best=(long)1e18;
		if (position==nRooms-1) {
			best=r1*nEnemies[position]+r3;
		}
		else {
			best=Math.min(best, travelTime*2+r1+Math.min(r1*(nEnemies[position]+1), r2) + go2(position+1));
		}
		return dp2[position]=best;
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