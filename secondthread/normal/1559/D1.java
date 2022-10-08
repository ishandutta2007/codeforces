import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
//		int T=fs.nextInt();
		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), m1=fs.nextInt(), m2=fs.nextInt();
			DisjointSet d1=new DisjointSet(n), d2=new DisjointSet(n);
			for (int i=0; i<m1; i++) d1.union(fs.nextInt()-1, fs.nextInt()-1);
			for (int i=0; i<m2; i++) d2.union(fs.nextInt()-1, fs.nextInt()-1);
			ArrayList<Integer> ans=new ArrayList<>();
			for (int i=0; i<n; i++)
				for (int j=i+1; j<n; j++)
					if (d1.find(i)!=d1.find(j) && d2.find(i) != d2.find(j)) {
						d1.union(i, j);
						d2.union(i, j);
						ans.add(i);
						ans.add(j);
					}
			
			System.out.println(ans.size()/2);
			for (int i=0; i<ans.size(); i+=2) {
				System.out.println(ans.get(i)+1+" "+(ans.get(i+1)+1));
			}
			
		}
	}
	
	static class DisjointSet {
		int[] s;
		
		public DisjointSet(int n) {
			Arrays.fill(s = new int[n], -1);
		}
		
		public int find(int i) {
			return s[i] < 0 ? i : (s[i] = find(s[i]));
		}
		
		public boolean union(int a, int b) {
			if ((a = find(a)) == (b = find(b))) return false;
			if(s[a] == s[b]) s[a]--;
			if(s[a] <= s[b]) s[b] = a; 
	        else s[a] = b;
			return true;
		}
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