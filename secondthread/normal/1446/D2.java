import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
15
1 1 2 2 3 3 3 3 3 3 3 3 3 3 3
 */
public class D2 {

	//TODO: FIX THIS!
	static int MAX_VAL=200_001;
	
	static final boolean debug=false;
	
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		for (int i=0; i<n; i++) a[i]--;
		ArrayList<Integer>[] occurrancesOfList=new ArrayList[MAX_VAL];
		for (int i=0; i<MAX_VAL; i++) occurrancesOfList[i]=new ArrayList<>();
		for (int i=0; i<n; i++) occurrancesOfList[a[i]].add(i);
		int[][] occurrancesOf=new int[MAX_VAL][];
		for (int i=0; i<MAX_VAL; i++) {
			occurrancesOf[i]=new int[occurrancesOfList[i].size()];
			for (int j=0; j<occurrancesOf[i].length; j++) 
				occurrancesOf[i][j]=occurrancesOfList[i].get(j);
		}
		int mostFreq=0;
		for (int i=0; i<MAX_VAL; i++) 
			if (occurrancesOfList[i].size()>occurrancesOfList[mostFreq].size()) 
				mostFreq=i;
		
		int best=0;
		int[] bigOccs=occurrancesOf[mostFreq];
		for (int other=0; other<MAX_VAL; other++) {
			if (other==mostFreq) continue;
			int[] p2s=occurrancesOf[other];
			
			ArrayList<Integer> bigOccsToUse=new ArrayList<>();
			int nextToTake=0;
			int k=p2s.length+1;
			for (int i:p2s) {
				//TODO: binary search for firstThing > i
				int p1Ind=bs(bigOccs, i);
				nextToTake=Math.max(nextToTake, p1Ind-k);
				while (nextToTake<bigOccs.length && nextToTake<p1Ind+k) {
					bigOccsToUse.add(bigOccs[nextToTake++]);
				}
			}
			
			int totalThings=bigOccsToUse.size()+p2s.length;
			int[] positions=new int[totalThings];
			int[] deltas=new int[totalThings];
			int p1=0, p2=0;
			while (p1<bigOccsToUse.size() || p2<p2s.length) {
				if (p1==bigOccsToUse.size() || (p2!=p2s.length && p2s[p2]<bigOccsToUse.get(p1))) {
					deltas[p1+p2]=-1;
					positions[p1+p2]=p2s[p2];
					p2++;
					continue;
				}
				else {
					deltas[p1+p2]=1;
					positions[p1+p2]=bigOccsToUse.get(p1);
					p1++;
					continue;
				}
			}
			best=Math.max(best, go(positions, deltas, n));
		}
		System.out.println(best);
	}
	
	//returns the index of the first thing > x, or n-1 otherwise
	static int bs(int[] a, int x) {
		int min=0, max=a.length-1;
		while (min!=max) {
			int mid=(min+max)/2;
			if (a[mid]>x) {
				max=mid;
			}
			else {
				min=mid+1;
			}
		}
		min=Math.min(min, a.length-1);
		return min;
	}
	
	static final int oo=1_000_000_000;
	
	static int go(int[] positions, int[] deltas, int n) {
		
		if (debug) System.out.println("Trying positions: "+Arrays.toString(positions));
		if (debug) System.out.println("Deltas: "+Arrays.toString(deltas));
		
		//TODO: linear sweep
		int minPrefixSum=0, prefixSum=0, maxPrefixSum=0;;
		for (int i:deltas) {
			prefixSum+=i;
			minPrefixSum=Math.min(minPrefixSum, prefixSum);
			maxPrefixSum=Math.max(maxPrefixSum, prefixSum);
		}
		prefixSum=0;
		int[] first=new int[maxPrefixSum-minPrefixSum+10];
		int[] version=new int[maxPrefixSum-minPrefixSum+10];
		Arrays.fill(first, oo);
		
		first[0-minPrefixSum]=Math.min(first[0-minPrefixSum], 0);
		version[0-minPrefixSum]=-1;
		int best=0;
		for (int i=0; i<positions.length; i++) {
			//choose not to include this
			int endX=positions[i]-1;
			int startX=first[prefixSum-minPrefixSum];
			if (version[prefixSum-minPrefixSum]!=i-1)
				best=Math.max(best, endX-startX+1);
			
			prefixSum+=deltas[i];
			if (first[prefixSum-minPrefixSum] == oo) {
				first[prefixSum-minPrefixSum]=positions[i]+1;
				version[prefixSum-minPrefixSum]=i;
			}
		}
		
		int endX=n-1;
		int startX=first[prefixSum-minPrefixSum];
		if (version[prefixSum-minPrefixSum] != positions.length-1)
			best=Math.max(best, endX-startX+1);
		
		if (debug) System.out.println("First: "+Arrays.toString(first));
		if (debug) System.out.println("Returning "+best);
		if (debug) System.out.println();
		return best;
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