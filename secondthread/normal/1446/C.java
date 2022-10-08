import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		Trie t=new Trie();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		for (int i:a) t.insert(i, 30);
		int maxKeep=Trie.go(t);
		System.out.println(n-maxKeep);
	}

	static class Trie {
		Trie[] kids=new Trie[2];
		int subtreeSize=0;
		int depth;
		
		public void insert(int i, int bit) {
			subtreeSize++;
			this.depth=bit;
			if (bit!=0) {
				int val=((i&(1<<bit))!=0)?1:0;
				if (kids[val]==null) kids[val]=new Trie();
				kids[val].insert(i, bit-1);
			}
		}
		
		static int size(Trie t) {
			return t==null?0:t.subtreeSize;
		}
		
		//returns the max kept
		static int go(Trie me) {
			if (me==null) return 0;
			if (me.depth==0) {
				return me.subtreeSize;
			}
			//keep left
			int add=Math.min(1, size(me.kids[1]));
			int best=add+go(me.kids[0]);
			
			add=Math.min(1, size(me.kids[0]));
			best=Math.max(best, add+go(me.kids[1]));
			
//			System.out.println("One node with bit "+me.depth+" returning "+best);
			return best;
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