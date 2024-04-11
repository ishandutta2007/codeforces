import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
1
6 2 4
1 1 2 2 2 2

1
4 0 4
4 4 4 3
 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), nL=fs.nextInt(), nR=fs.nextInt();
			int[] l=fs.readArray(nL), r=fs.readArray(nR);
			int[] lCS=new int[n+1], rCS=new int[n+1];
			for (int i:l) lCS[i]++;
			for (int i:r) rCS[i]++;
			int freePairs=0;
			for (int i=0; i<=n; i++) {
				int count=Math.min(lCS[i], rCS[i]);
				lCS[i]-=count;
				rCS[i]-=count;
				freePairs+=count;
			}
			
			int toRemove=Math.abs(nL-nR);
			int[] removeCS;
			if (nL>nR)
				removeCS=lCS;
			else
				removeCS=rCS;
			int cost=0;
			for (int i=0; i<=n; i++) {
				if (removeCS[i]>1) {
					int doubleCount=Math.min(toRemove, 
							removeCS[i]-removeCS[i]%2);
					if (doubleCount%2!=0) throw null;
//					System.out.println("Double count "+doubleCount);
					freePairs+=doubleCount/2;
					cost+=doubleCount/2;
					toRemove-=doubleCount;
					removeCS[i]-=doubleCount;
				}
			}

//			System.out.println("Initial cost: "+cost+" "+toRemove+" "+freePairs);
			cost+=toRemove/2;
			cost+=(n-2*freePairs)/2;
			
			System.out.println(cost);
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