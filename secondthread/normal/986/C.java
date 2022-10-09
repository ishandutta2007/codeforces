import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringTokenizer;
/*

 */
public class _485C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int N=fs.nextInt();
		int nNodes=fs.nextInt();
		int[] exists=new int[1<<N];
		int[] subsetSum=new int[1<<N];
		for (int i=0; i<nNodes; i++) exists[fs.nextInt()]=1;
		if (exists[0]!=0) {
			System.out.println(1);
			return;
		}
		for (int i=0; i<1<<N; i++) subsetSum[i]=exists[i];
		for (int i=0; i<N; i++) 
			for (int mask=0; mask<1<<N; mask++)
				if ((mask&(1<<i))!=0)
					subsetSum[mask]+=subsetSum[mask^(1<<i)];

		DisjointSet dj=new DisjointSet(1<<N);
		int fullMask=(1<<N)-1;
		boolean[] mergeWithAllSubsets=new boolean[1<<N];
		for (int i=0; i<1<<N; i++) {
			if (exists[i]!=1) continue;
			int inverse=i^fullMask;
			if (subsetSum[inverse]!=0) {
				mergeWithAllSubsets[i]=mergeWithAllSubsets[inverse]=true;
//				System.out.println("Should merge "+bits(i)+" and "+bits(inverse)+" with all subsets");
				dj.union(i, inverse);
			}
		}
		ArrayDeque<Integer> toMerge=new ArrayDeque<>();
		boolean[] merged=new boolean[1<<N];
		for (int i=0; i<1<<N; i++) {
			if (mergeWithAllSubsets[i]) {
				merged[i]=true;
				toMerge.add(i);
			}
		}
		while (!toMerge.isEmpty()) {
			int next=toMerge.remove();
			for (int bit=0; bit<N; bit++) {
				if ((next&(1<<bit))==0)
					continue;
				int i=next-(1<<bit);
				if (subsetSum[i]!=0) {
//					System.out.println("  merging "+bits(i)+" "+bits(next));
					dj.union(next, i);
					if (!merged[i]) {
						toMerge.add(i);
						merged[i]=true;
					}
				}
			}
		}
		boolean[] counted=new boolean[1<<N];
		int components=0;
		for (int i=0; i<1<<N; i++) {
			if (exists[i]!=1) continue;
			if (counted[dj.find(i)]) continue;
			counted[dj.find(i)]=true;
//			System.out.println("Found uncounted comp: "+bits(i));
			components++;
		}
		System.out.println(components);
		
	}
	
	static String bits(int n) {
		String toReturn="";
		for (int i=4; i>=0; i--) toReturn+=(n&(1<<i))==0?'0':'1';
		return toReturn;
	}
	
	static class DisjointSet {
		int[] s;
		
		public DisjointSet(int n) {
			Arrays.fill(s = new int[n], -1);
		}
		
		public int find(int i) {
			return s[i] < 0 ? i : (s[i] = find(s[i]));
		}
		
		public boolean union(int a, int b) {
			if ((a = find(a)) == (b = find(b))) return false;
			if(s[a] == s[b]) s[a]--;
			if(s[a] <= s[b]) s[b] = a; else s[a] = b;
			return true;
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
	}
	
}