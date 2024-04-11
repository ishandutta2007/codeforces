

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		Random r=new Random(5);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			long ansOld=solve3(a.clone(), n);
			System.out.println(ansOld);
			
//			int n=1+r.nextInt(5);
//			int[] a=new int[n];
//			for (int i=0; i<n; i++) a[i]=1+r.nextInt(10);
//			long solve1=solve2(a.clone(), n);
//			long solve2=solve3(a.clone(), n);
//			if (solve1!=solve2) throw null;
			
		}
	}
	
//	static long solve(int[] a, int n) {
//		long ans=0;
//		for (int l=0; l+1<n; l++) {
//			int bounceOffDist=n-l;
//			int farTurns=a[l]-bounceOffDist+1;
//			if (farTurns>0) {
//				a[l]-=farTurns;
//				ans+=farTurns;
//			}
//			while (a[l]>1) {
//				int at=l+a[l]--;
//				ans++;
//				while (at<n) {
//					int oldAt=at;
//					at+=a[at]--;
//					if (a[oldAt]==0) a[oldAt]++;
//				}
//			}
//		}
//		ans+=a[n-1]-1;
//		return ans;
//	}
	static long solve3(int[] a, int n) {
		long[] timesHit=new long[n];
		long ans=0;
		for (int l=0; l<n; l++) {
			int bounceOffDist=n-l;
			for (int dist=Math.min(bounceOffDist-1, a[l]); dist>1; dist--) {
				timesHit[l+dist]++;
			}
			long toAdd=Math.max(a[l]-1-timesHit[l], 0);
//			System.out.println("Adding "+toAdd+" "+Arrays.toString(timesHit));
			if (l!=n-1) {
				timesHit[l+1]+=Math.max(0, timesHit[l]-(a[l]-1));
			}
			ans+=toAdd;
		}
		return ans;
	}
	
	static long solve2(int[] a, int n) {
		long ans=0;
		while (!allOnes(a, n)) {
			int at=0;
			while (at<n) {
				int to=at+a[at];
				a[at]=Math.max(1, a[at]-1);
				at=to;
			}
			ans++;
		}
		return ans;
	}
	
	static boolean allOnes(int[] a, int n) {
		for (int i=0; i<n; i++) if (a[i]!=1) return false;
		return true;
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
		
		int[] readArray(int n) {
			int[] a=new int[n]; 
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		int nextInt () {
			return Integer.parseInt(next());
		}
	}

}