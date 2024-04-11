import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class E {

	static int n, nPositions, nCheerleaders;
	static long[][] dp;
	static Person[] people;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		n=fs.nextInt(); nPositions=fs.nextInt(); nCheerleaders=fs.nextInt();
		dp=new long[1<<nPositions][n+1];
		for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], -1);
		people=new Person[n];
		for (int i=0; i<n; i++) people[i]=new Person();
		for (int i=0; i<n; i++) people[i].asCheerleader=fs.nextInt();
		for (int i=0; i<n; i++) people[i].asPlayer=fs.readArray(nPositions);
		
		Arrays.sort(people);
		long ans=go(0, 0, 0);
		System.out.println(ans);
	}
	
	
	static long go(int mask, int person, int cheerleadersTaken) {
		if (dp[mask][person]!=-1) return dp[mask][person];
		if (person==n) {
			if (mask==(1<<nPositions)-1) return 0;
			return Long.MIN_VALUE;
		}
		
		long best=Long.MIN_VALUE;
		//try as cheerleader
		if (cheerleadersTaken<nCheerleaders) {
			best=Math.max(best, people[person].asCheerleader+go(mask, person+1, cheerleadersTaken+1));
		}
		else {
			best=Math.max(best, go(mask, person+1, cheerleadersTaken));
		}
		for (int toBe=0; toBe<nPositions; toBe++) {
			if ((mask&(1<<toBe))!=0) continue;
			best=Math.max(best, people[person].asPlayer[toBe]+go(mask+(1<<toBe), person+1, cheerleadersTaken));
		}
		
		return dp[mask][person]=best;
	}
	
	static class Person implements Comparable<Person>{
		int asCheerleader;
		int[] asPlayer;
		
		public int compareTo(Person o) {
			return -Integer.compare(asCheerleader, o.asCheerleader);
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreElements())
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
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		
	}

}