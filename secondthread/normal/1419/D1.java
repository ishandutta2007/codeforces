import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		ruffleSort(a);		
		ArrayDeque<Integer> candidates=new ArrayDeque<>();
		int i;
		for (i=0; i<(n-1)/2; i++)
			candidates.add(a[i]);
		int ans=0;
		boolean haveOne=false;
		ArrayList<Integer> extracted=new ArrayList<>();
		ArrayList<Integer> skipped=new ArrayList<>();
//		System.out.println("Candidates: "+Arrays.toString(candidates));
		while (true) {
			while (i<n && !candidates.isEmpty() && a[i]==candidates.peekFirst()) {
				skipped.add(a[i]);
				i++;
			}
			if (i==n) {
				//run out of big items
				if (haveOne && !candidates.isEmpty()) ans++;
				while (!candidates.isEmpty()) skipped.add(candidates.removeFirst());
				break;
			}
			else if (candidates.isEmpty()) {
				if (haveOne) ans++;
				//run out of candidates
				while (i<n) skipped.add(a[i++]);
				break;
			}
			else {
				if (haveOne) ans++;
				haveOne=true;
				extracted.add(a[i++]);
				extracted.add(candidates.removeFirst());
			}
		}
		Collections.sort(skipped);
		Collections.reverse(skipped);
		extracted.addAll(skipped);
		
		PrintWriter out=new PrintWriter(System.out);
		out.println(ans);
		for (int ii:extracted) out.print(ii+" ");
		out.println();
		out.close();
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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