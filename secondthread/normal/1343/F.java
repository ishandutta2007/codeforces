import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;

public class F {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			Seg[] segs=new Seg[n-1];
			for (int i=0; i<n-1; i++) {
				int len=fs.nextInt();
				segs[i]=new Seg(len);
				for (int j=0; j<len; j++) segs[i].add(fs.nextInt()-1);
			}
			ArrayList<Integer> occursOnce=new ArrayList<>();
			for (int cand=0; cand<n; cand++) {
				int count=0;
				for (Seg s:segs) if (s.set.contains(cand)) count++;
				if (count==1) occursOnce.add(cand);
			}
//			System.out.println("occ");
			for (int i:occursOnce) {
//				System.out.println("Trying "+i);
				try {
					solve(i, segs, n);
				}
				catch (Throwable t) {
					continue;
				}
				continue outer;
			}
			throw null;
		}
	}
	
	static void solve(int last, Seg[] segs, int n) {
		int[] ans=new int[n];
		boolean[] used=new boolean[n];
		used[last]=true;
		ans[n-1]=last;
		int prev=last;
//		System.out.println("Starting with "+last);
		for (int placeIndex=n-2; placeIndex>=0; placeIndex--) {
			int bestToPlace=-1;
			int bestToPlaceTimes=-1;
			int zeroToPlace=-1;
			int zeroToPlaceTimes=-1;
			for (int toPlace=0; toPlace<n; toPlace++) {
				if (used[toPlace]) continue;
				int oldPartOf=0, newPartOf=0;
				for (Seg s:segs) {
					if (s.set.contains(prev)) {
						if (s.set.contains(toPlace)) oldPartOf++;
					}
					else {
						if (s.set.contains(toPlace)) newPartOf++;
					}
				}
				if (newPartOf==0) {
					if (oldPartOf>zeroToPlaceTimes) {
						zeroToPlaceTimes=oldPartOf;
						zeroToPlace=toPlace;
					}
				}
				else if (newPartOf==1) {
					if (oldPartOf>bestToPlaceTimes) {
						bestToPlaceTimes=oldPartOf;
						bestToPlace=toPlace;
					}
				}
			}
			int nextPlace=bestToPlace==-1?zeroToPlace:bestToPlace;
//			System.out.println("Placed "+nextPlace);
			prev=nextPlace;
			used[nextPlace]=true;
			ans[placeIndex]=nextPlace;
		}
		boolean[] at=new boolean[n];
		for (Seg s:segs) {
			int end=s.verify(ans);
			if (at[end]) throw null;
			at[end]=true;
		}
		for (int i=0; i<n; i++) {
			System.out.print(ans[i]+1+" ");
		}
		System.out.println();
	}
	
	static class Seg {
		int len;
		ArrayList<Integer> list=new ArrayList<>();
		HashSet<Integer> set=new HashSet<>();
		public Seg(int len) {
			this.len=len;
		}
		
		public void add(int i) {
			list.add(i);
			set.add(i);
		}
		int verify(int[] ans) {
			outer: for (int endAt=list.size()-1; endAt<ans.length; endAt++) {
				for (int i=0; i<list.size(); i++) {
					if (!set.contains(ans[endAt-i])) continue outer;
				}
				return endAt;
			}
			throw null;
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