import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), nSubsets=fs.nextInt();
			Subset[] subsets=new Subset[nSubsets+1];
			
			for (int i=0; i<nSubsets; i++) subsets[i]=new Subset(fs);
			boolean[] chosen=new boolean[n];
			for (Subset s:subsets) if (s!=null) for (int i:s.indecies) chosen[i-1]=true;
			ArrayList<Integer> unchosen=new ArrayList<>();
			for (int i=0; i<n; i++) if (!chosen[i]) unchosen.add(i+1);
			subsets[nSubsets]=new Subset(unchosen);
			nSubsets++;
			
			//TODO: find max index, max value, everything else value
			int maxValue=getMax(subsets, 0, nSubsets-1, fs);
			System.err.println("Max value: "+maxValue);
			int min=0, max=nSubsets-1;
			while (min!=max) {
				int mid=(min+max)/2;
				System.err.println("max: "+max+" min: "+min+" mid: "+mid);
				int val=getMax(subsets, min, mid, fs);
				if (val==maxValue) {
					max=mid;
				}
				else {
					min=mid+1;
				}
			}
			System.err.println("Max index "+max);
			boolean[] included=new boolean[nSubsets];
			Arrays.fill(included, true);
			included[min]=false;
			int elseValue=getMax(subsets, included, fs);
			System.out.print("!");
			for (int i=0; i<nSubsets-1; i++) if (i==max) System.out.print(" "+elseValue); else System.out.print(" "+maxValue);
			System.out.println();
			System.out.flush();
			String verdict=fs.next();
			//should be 'Correct'
		}
	}
	
	static int getMax(Subset[] subsets, int from, int to, FastScanner fs) {
		boolean[] included=new boolean[subsets.length];
		for (int i=from; i<=to; i++) included[i]=true;
		return getMax(subsets, included, fs);
	}
	
	static int getMax(Subset[] subsets, boolean[] in, FastScanner fs) {
		ArrayList<Integer> included=new ArrayList<>();
		for (int s=0; s<in.length; s++) {
			if (in[s]) for (int i:subsets[s].indecies) included.add(i);
		}
		Collections.sort(included);
		System.out.print("? "+included.size());
		for (int i:included) System.out.print(" "+i);
		System.out.println();
		System.out.flush();
		int max=fs.nextInt();
		return max;
	}
	
	static class Subset {
		int value;
		int[] indecies;
		public Subset(FastScanner fs) {
			int n=fs.nextInt();
			indecies=fs.readArray(n);
		}
		public Subset(ArrayList<Integer> list) {
			int n=list.size();
			indecies=new int[n];
			for (int i=0; i<n; i++) indecies[i]=list.get(i);
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