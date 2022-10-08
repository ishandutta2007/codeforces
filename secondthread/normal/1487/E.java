import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Random;
import java.util.StringTokenizer;

//Good morning!
public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int[] ns=fs.readArray(4);
		int[][] as=new int[4][];
		for (int i=0; i<4; i++) as[i]=fs.readArray(ns[i]);
		Integer[][] sortedIndex=new Integer[4][];
		for (int i=0; i<4; i++) {
			sortedIndex[i]=new Integer[ns[i]];
			for (int j=0; j<ns[i]; j++) sortedIndex[i][j]=j;
			final int iInd=i;
			Arrays.sort(sortedIndex[i], (a, b) -> Integer.compare(as[iInd][a], as[iInd][b]));
		}
		HashSet<Integer>[] illegalAsForB=new HashSet[ns[1]];
		HashSet<Integer>[] illegalCsForB=new HashSet[ns[1]];
		HashSet<Integer>[] illegalDsForC=new HashSet[ns[2]];
		for (int i=0; i<ns[1]; i++) {
			illegalAsForB[i]=new HashSet<>();
			illegalCsForB[i]=new HashSet<>();
		}
		for (int i=0; i<ns[2]; i++)
			illegalDsForC[i]=new HashSet<>();
		
		int nEdges;
		nEdges=fs.nextInt();
		for (int i=0; i<nEdges; i++) {
			int from=fs.nextInt()-1, to=fs.nextInt()-1;
			illegalAsForB[to].add(from);
		}
		nEdges=fs.nextInt();
		for (int i=0; i<nEdges; i++) {
			int from=fs.nextInt()-1, to=fs.nextInt()-1;
			illegalCsForB[from].add(to);
		}
		nEdges=fs.nextInt();
		for (int i=0; i<nEdges; i++) {
			int from=fs.nextInt()-1, to=fs.nextInt()-1;
			illegalDsForC[from].add(to);
		}
		final int oo=5_000_000_00;
		for (int b=0; b<ns[1]; b++) {
			int toAdd=oo;
			for (int aInd:sortedIndex[0]) {
				if (illegalAsForB[b].contains(aInd)) continue;
				toAdd=as[0][aInd];
				break;
			}
			as[1][b]+=toAdd;
		}
		for (int c=0; c<ns[2]; c++) {
			int toAdd=oo;
			for (int dInd:sortedIndex[3]) {
				if (illegalDsForC[c].contains(dInd)) continue;
				toAdd=as[3][dInd];
				break;
			}
			as[2][c]+=toAdd;
		}
		
		for (int i=0; i<4; i++) {
			sortedIndex[i]=new Integer[ns[i]];
			for (int j=0; j<ns[i]; j++) sortedIndex[i][j]=j;
			final int iInd=i;
			Arrays.sort(sortedIndex[i], (a, b) -> Integer.compare(as[iInd][a], as[iInd][b]));
		}
		for (int b=0; b<ns[1]; b++) {
			int toAdd=oo;
			for (int cInd:sortedIndex[2]) {
				if (illegalCsForB[b].contains(cInd)) continue;
				toAdd=as[2][cInd];
				break;
			}
			as[1][b]+=toAdd;
		}
		int ans=oo;
		for (int i:as[1]) ans=Math.min(ans, i);
		
		if (ans<oo) {
			System.out.println(ans);
		}
		else {
			System.out.println(-1);
		}
	}

	// Use this instead of Arrays.sort() on an array of ints. Arrays.sort() is n^2
	// worst case since it uses a version of quicksort. Although this would never
	// actually show up in the real world, in codeforces, people can hack, so
	// this is needed.
	static void ruffleSort(int[] a) {
		//ruffle
		int n=a.length;
		Random r=new Random();
		for (int i=0; i<a.length; i++) {
			int oi=r.nextInt(n), temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
		}
		
		//then sort
		Arrays.sort(a);
	}
	
	// Use this to input code since it is faster than a Scanner
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