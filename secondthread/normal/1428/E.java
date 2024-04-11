import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		PriorityQueue<Seg> pq=new PriorityQueue<>();
		k-=n;
		for (int i=0; i<n; i++) {
			pq.add(new Seg(1, fs.nextInt()));
		}
		for (int i=0; i<k; i++) {
			Seg giveTo=pq.remove();
			giveTo.parts++;
			pq.add(giveTo);
		}
		long total=0;
		while (!pq.isEmpty()) total+=pq.remove().cost();
		System.out.println(total);
	}
	
	static class Seg implements Comparable<Seg> {
		int parts, len;
		public Seg(int parts, int len) {
			this.parts=parts;
			this.len=len;
		}
		
		long cost() {
			int smallerSize=len/parts;
			int nBigger=len%parts;
			int nSmaller=parts-nBigger;
			long smallerCost=smallerSize*(long)smallerSize;
			long biggerCost=(smallerSize+1)*(long)(smallerSize+1);
			return smallerCost*nSmaller+biggerCost*nBigger;
		}
		
		long benefitOfOne() {
			long oCost=cost();
			parts++;
			long nCost=cost();
			parts--;
			return oCost-nCost;
		}
		
		public int compareTo(Seg o) {
			return Long.compare(o.benefitOfOne(), benefitOfOne());
		}
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