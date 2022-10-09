

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class C {

	public static void solve(FastScanner fs) {	
		int n=fs.nextInt();
		Sequence[] seqs=new Sequence[n];
		for (int i=0; i<n; i++) seqs[i]=new Sequence(fs.next().toCharArray());
		
		HashMap<Integer, Integer> hashMap=new HashMap<>();
		for (Sequence s:seqs) {
			if (s.lowestTotal<s.endingTotal) continue;
			hashMap.put(s.endingTotal, hashMap.getOrDefault(s.endingTotal, 0)+1);
		}
		
		long total=0;
		for (Sequence s:seqs) {
			if (s.endingTotal<=0)
				continue;
			if (s.lowestTotal<0) 
				continue;
			total+=hashMap.getOrDefault(-s.endingTotal, 0);
		}
		long count=hashMap.getOrDefault(0, 0);
		total+=count*(count);
		System.out.println(total);
	}
	
	static class Sequence{
		int lowestTotal;
		int endingTotal;
		int index;
		
		public Sequence(char[] s) {
			int total=0;
			lowestTotal=0;
			for (int i=0; i<s.length; i++) {
				if (s[i]==')') total--;
				else total++;
				lowestTotal=Math.min(lowestTotal, total);
			}
			endingTotal=total;
		}
	}

	
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}