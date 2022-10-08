import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt();
		int nTowers=fs.nextInt();
		HashSet<Integer>[] towers=new HashSet[nTowers];
		for (int i=0; i<nTowers; i++) towers[i]=new HashSet<>();
		int potential=n-1;
		for (int i=0; i<n; i++) {
			int tower=fs.nextInt()-1;
			if (towers[tower].contains(i-1)) potential--;
			towers[tower].add(i);
		}
		out.println(potential);
		for (int qq=1; qq<nTowers; qq++) {
			int t1=fs.nextInt()-1, t2=fs.nextInt()-1;
			HashSet<Integer> smaller=towers[t1].size()<towers[t2].size()?towers[t1]:towers[t2];
			HashSet<Integer> bigger=smaller==towers[t1]?towers[t2]:towers[t1];
			int[] smallerValues=new int[smaller.size()];
			int smallerIndex=0;
			for (int i:smaller)
				smallerValues[smallerIndex++]=i;
			sort(smallerValues);
			for (int i=0; i<smallerValues.length; i++) {
				if (i<smallerValues.length-1 && smallerValues[i+1]==smallerValues[i]+1)
					potential++;
				bigger.add(smallerValues[i]);
				if (bigger.contains(smallerValues[i]-1)) potential--;
				if (bigger.contains(smallerValues[i]+1)) potential--;
			}
			
			towers[t1]=bigger;
			out.println(potential);
		}
		out.close();
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