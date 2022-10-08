import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		long ans=0;
		int[] dist=new int[n+1];
		int[] from=new int[n+1];
		int[] nOddChangedToGetHere=new int[n+1];
		Arrays.fill(dist, -1);
		dist[n]=0;
		ArrayDeque<Integer> bfs=new ArrayDeque<>();
		bfs.add(n);
		from[n]=-1;
		while (!bfs.isEmpty()) {
			int nEven=bfs.removeFirst();
			int nOdd=n-nEven;
			
			for (int nOddToChange=0; nOddToChange<=Math.min(nOdd, k); nOddToChange++) {
				int nEvenToChange=k-nOddToChange;
				int otherNode=nEven-nEvenToChange+nOddToChange;
				if (otherNode<0 || otherNode>n || nEvenToChange>nEven) continue;
				if (dist[otherNode]!=-1) continue;
				dist[otherNode]=dist[nEven]+1;
				from[otherNode]=nEven;
				nOddChangedToGetHere[otherNode]=nOddToChange;
				bfs.addLast(otherNode);
			}
		}
		ArrayList<Integer> nOddsChanged=new ArrayList<>();
		int at=0;
		if (dist[at]==-1) {
			System.out.println(-1);
			return;
		}
		while (at!=n) {
			nOddsChanged.add(nOddChangedToGetHere[at]);
			at=from[at];
		}
		ArrayDeque<Integer> even=new ArrayDeque<>(), odd=new ArrayDeque<>();
		for (int i=0; i<n; i++) even.addLast(i);
		for (int query=nOddsChanged.size()-1; query>=0; query--) {
			int nOddsToChange=nOddsChanged.get(query);
			int nEvensToChange=k-nOddsToChange;
			ArrayList<Integer> toQuery=new ArrayList<>();
			for (int i=0; i<nEvensToChange; i++) {
				int toMakeOdd=even.removeFirst();
				odd.addLast(toMakeOdd);
				toQuery.add(toMakeOdd);
			}
			for (int i=0; i<nOddsToChange; i++) {
				int toMakeEven=odd.removeFirst();
				even.addLast(toMakeEven);
				toQuery.add(toMakeEven);
			}
			ans^=query(toQuery, fs);
		}
		System.out.println("! "+ans);
	}
	
	static int query(ArrayList<Integer> toQuery, FastScanner fs) {
		System.out.print("? ");
		for (int i:toQuery) {
			System.out.print(1+i+" ");
		}
		System.out.println();
		return fs.nextInt();
	}
	
	static int gcd(int a, int b) {
		if (b==0) return a;
		return gcd(b, a%b);
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