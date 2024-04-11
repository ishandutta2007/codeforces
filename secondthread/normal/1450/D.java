import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeSet;

/* 
 * Subscribe to galen_colin!
 * https://tinyurl.com/galencolin
*/

public class D2 {
	
	static final boolean debug=false;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			for (int i=0; i<n; i++) a[i]--;
			ArrayList<Integer>[] indeciesOf=new ArrayList[n];
			for (int i=0; i<n; i++) indeciesOf[i]=new ArrayList<>();
			for (int i=0; i<n; i++) indeciesOf[a[i]].add(i);
			TreeSet<Integer> bounds=new TreeSet<>();
			bounds.add(-1);
			bounds.add(n);
			
			int[][] boundsFor=new int[n][];
			for (int value=0; value<n; value++) {
				boundsFor[value]=getBounds(value, indeciesOf[value], bounds);
				for (int i:indeciesOf[value]) bounds.add(i);
			}
			for (int i=1; i<n; i++) {
				boundsFor[i][0]=Math.max(boundsFor[i][0], boundsFor[i-1][0]);
				boundsFor[i][1]=Math.min(boundsFor[i][1], boundsFor[i-1][1]);
			}
			
			boolean[] possible=new boolean[n];
			for (int i=0; i<n; i++) {
				int biggest=n-i-1;
				int size=i+1;
				possible[i]=boundsFor[biggest][0]<=size && size <=boundsFor[biggest][1];
			}
			
			//TODO: probably don't need!
			boolean isPerm=true;
			for (ArrayList<Integer> l:indeciesOf) if (l.size()!=1) isPerm=false;
			if (isPerm) possible[0]=true;
			
			
			//TODO: printwriter
			for (boolean b:possible)
				out.print(b?1:0);
			out.println();
		}
		out.close();
	}
	
	//returns {min, max} bounds
	static int[] getBounds(int value, ArrayList<Integer> occs, TreeSet<Integer> bounds) {
		if (debug) System.out.println("Getting bound for value: "+value);
		if (occs.isEmpty()) {
			return new int[] {(int)1e9, -100};
		}
		int ptr=0;
		int min=Integer.MIN_VALUE;
		ArrayList<Integer> rangeSizes=new ArrayList<>();
		while (ptr<occs.size()) {
			int first=occs.get(ptr);
			int leftBound=bounds.lower(first);
			int rightBound=bounds.higher(first);
			int last=first;
			
			while (ptr+1<occs.size() && occs.get(ptr+1)<rightBound) {
				last=occs.get(++ptr);
			}
			
			int rangeSize=rightBound-leftBound-1;
			if (first==last && (first==leftBound+1 || first == rightBound-1)) {
				
			}
			else {
				rangeSizes.add(rangeSize-1);
			}
			
			rangeSizes.add(rangeSize);
			ptr++;
		}
		Collections.sort(rangeSizes);
		
		//bigger than second last thing
		if (rangeSizes.size()>1) min=Math.max(min, rangeSizes.get(rangeSizes.size()-2)+1);
		else min=1;
		
		//small enough that there is at least 1
		int max=rangeSizes.get(rangeSizes.size()-1);
		if (debug) System.out.println("Range sizes: "+rangeSizes);
		if (debug) System.out.println("Returning "+min+" "+max);
		if (debug) System.out.println();
		return new int[] {min, max};
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