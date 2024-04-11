import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		char[] line=fs.next().toCharArray();
		Pos[] orig=new Pos[n];
		for (int i=0; i<n; i++) 
			orig[i]=new Pos(line[i]);
		
		ArrayDeque<Integer>[] positionsOf=new ArrayDeque[26];
		for (int i=0; i<positionsOf.length; i++) positionsOf[i]=new ArrayDeque<>();
		for (int i=0; i<n; i++) {
			int val=line[n-1-i]-'a';
			positionsOf[val].addLast(i);
		}
		for (int i=0; i<n; i++) {
			orig[i].finalPos=positionsOf[orig[i].val-'a'].removeFirst();
		}
		
		BIT bit=new BIT(n);
		long inv=0;
		for (int i=n-1; i>=0; i--) {
			inv+=bit.read(orig[i].finalPos);
			bit.update(orig[i].finalPos, 1);
		}
		System.out.println(inv);
	}
	
	static class Pos implements Comparable<Pos> {
		int finalPos;
		char val;
		public Pos(char val) {
			this.val=val;
		}
		
		public int compareTo(Pos o) {
			return Integer.compare(val, o.val);
		}
	}

	static class BIT {
		int n;
		int[] tree;
		
		public BIT(int n) {
			this.n = n;
			tree = new int[n + 2];
		}
		
		int read(int i) {
			i++;
			int sum = 0;
			while (i > 0) {
				sum += tree[i];
				i -= i & -i;
			}
			return sum;
		}
		
		void update(int i, int val) {
			i++;
			while (i <= n) {
				tree[i] += val;
				i += i & -i;
			}
		}

		// if the BIT is a freq array, returns the
		// index of the kth item, or n if there are fewer
		// than k items.
		int getKth(int k) {
			int e=Integer.highestOneBit(n), o=0;
			for (; e!=0; e>>=1) {
				if (e+o<=n && tree[e+o]<=k) {
					k-=tree[e+o];
					o+=e;
				}
			}
			return o;
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