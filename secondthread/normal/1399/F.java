import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

/*
 * 
1
4
1 5
2 4
2 3
3 4

1
7
1 10
2 8
2 5
3 4
4 4
6 8
7 7
 */
public class F {

	static int[][] dp;
	static boolean[][] have;
	static ArrayList<Seg>[] startAt, endAt;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			Seg[] segs=new Seg[n];
			for (int i=0; i<n; i++) 
				segs[i]=new Seg(fs.nextInt(), fs.nextInt());
			compress(segs);
//			for (Seg s:segs) System.out.println(s);
			startAt=new ArrayList[maxCoord]; 
			endAt=new ArrayList[maxCoord];
			have=new boolean[maxCoord][maxCoord];
			for (int i=0; i<maxCoord; i++) {
				startAt[i]=new ArrayList<>();
				endAt[i]=new ArrayList<>();
			}
			for (Seg s:segs) {
				startAt[s.l].add(s);
				endAt[s.r].add(s);
				have[s.l][s.r]=true;
			}
			dp=new int[maxCoord][maxCoord];
			for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], -1);
			int ans=go(0, maxCoord-1);
			System.out.println(ans);
		}
	}
	
	
	
	//stores lastTaken
	//careful with call from main
	static int go(int l, int r) {
		if (l>r) return 0;
		if (dp[l][r]!=-1) return dp[l][r];
		int ans=0;
		ans=Math.max(ans, go(l+1, r));
		ans=Math.max(ans, go(l, r-1));
		for (Seg s:startAt[l]) {
			if (s.r>=r)
				continue;
			int bonus=have[s.r+1][r]?1:0;
			ans=Math.max(ans, 1+go(l, s.r)+go(s.r+1, r)+bonus);
		}
		for (Seg s:endAt[r]) {
			if (s.l<=l)
				continue;
			int bonus=have[l][s.l-1]?1:0;
			ans=Math.max(ans, 1+go(s.l, r)+go(l, s.l-1)+bonus);
		}
//		System.out.println("DP "+l+" "+r+" gives "+ans);
		return dp[l][r]=ans;
	}
	
	static int maxCoord;
	
	static void compress(Seg[] segs) {
		TreeSet<Integer> xs=new TreeSet<>();
		for (Seg s:segs) {
			xs.add(s.l);
			xs.add(s.r);
		}
		xs.add(-(int)1e9);
		xs.add((int)1e9);
		HashMap<Integer, Integer> compress=new HashMap<>();
		for (int i:xs) compress.put(i, compress.size());
		for (Seg s:segs) {
			s.l=compress.get(s.l);
			s.r=compress.get(s.r);
		}
		maxCoord=compress.size();
	}
	
	static class Seg {
		int l, r;
		public Seg(int l, int r) {
			this.l=l;
			this.r=r;
		}
		
		public String toString() {
			return "("+l+" "+r+")";
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