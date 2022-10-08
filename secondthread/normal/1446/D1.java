import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {

	static int MAX_VAL=101;
	
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
		for (int other=0; other<MAX_VAL; other++) {
			if (other==mostFreq) continue;
			int[] p1s=occurrancesOf[mostFreq], p2s=occurrancesOf[other];
			int totalThings=p1s.length+p2s.length;
			int[] positions=new int[totalThings];
			int[] deltas=new int[totalThings];
			int p1=0, p2=0;
			while (p1<p1s.length || p2<p2s.length) {
				if (p1==p1s.length || (p2!=p2s.length && p2s[p2]<p1s[p1])) {
					deltas[p1+p2]=-1;
					positions[p1+p2]=p2s[p2];
					p2++;
					continue;
				}
				else {
					deltas[p1+p2]=1;
					positions[p1+p2]=p1s[p1];
					p1++;
					continue;
				}
			}
			best=Math.max(best, go(positions, deltas, n));
		}
		System.out.println(best);
	}
	
	static int go(int[] positions, int[] deltas, int n) {
//		System.out.println("Trying positions: "+Arrays.toString(positions));
//		System.out.println("Deltas: "+Arrays.toString(deltas));
		
		//TODO: linear sweep
		int minPrefixSum=0, prefixSum=0, maxPrefixSum=0;;
		for (int i:deltas) {
			prefixSum+=i;
			minPrefixSum=Math.min(minPrefixSum, prefixSum);
			maxPrefixSum=Math.max(maxPrefixSum, prefixSum);
		}
		prefixSum=0;
		int[] first=new int[maxPrefixSum-minPrefixSum+10];
		Arrays.fill(first, 1_000_000_000);
		first[0-minPrefixSum]=Math.min(first[0-minPrefixSum], 0);
//		int lastX=0;
		int best=0;
		for (int i=0; i<positions.length; i++) {
			//choose not to include this
			int endX=positions[i]-1;
			int startX=first[prefixSum-minPrefixSum];
			best=Math.max(best, endX-startX+1);
			
			prefixSum+=deltas[i];
			first[prefixSum-minPrefixSum]=Math.min(first[prefixSum-minPrefixSum], positions[i]+1);
//			lastX=positions[i]+1;
		}
		
		int endX=n-1;
		int startX=first[prefixSum-minPrefixSum];
		best=Math.max(best, endX-startX+1);
//		System.out.println("First: "+Arrays.toString(first));
//		System.out.println("Returning "+best);
//		System.out.println();
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