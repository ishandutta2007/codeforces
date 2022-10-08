import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=fs.nextInt();
			char[] a=fs.next().toCharArray();
			sort(a);
			if (k==1) {
				System.out.println(a);
				continue;
			}
			int[] cs=new int[26];
			for (char c:a) cs[c-'a']++;
			StringBuilder[] sbs=new StringBuilder[k];
			for (int i=0; i<k; i++) {
				sbs[i]=new StringBuilder(a[i]+"");
				cs[a[i]-'a']--;
			}
			if (sbs[0].toString().equals(sbs[k-1].toString())) {
				int nonzero=0;
				for (int i:cs) if (i!=0) nonzero++;
				if (nonzero==1) {
					//then split equally
					System.out.print(sbs[0]);
					int nonzeroInd=0;
					for (int i=0; i<cs.length; i++) if (cs[i]!=0) nonzeroInd=i;
					for (int i=0; i<(cs[nonzeroInd]+k-1)/k; i++) System.out.print((char)('a'+nonzeroInd));
					System.out.println();
				}
				else {
					//give all to the first person
					System.out.print(sbs[0]);
					for (int i=k; i<n; i++) System.out.print(a[i]);
					System.out.println();
				}
			}
			else {
				System.out.println(sbs[k-1].toString());
			}
		}
	}
	
	static void sort(char[] a) {
		ArrayList<Character> l=new ArrayList<>();
		for (char c:a) l.add(c);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
	
}