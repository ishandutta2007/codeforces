import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class TrieProblem {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Trie trie=new Trie();
		trie.isRoot=true;
		for (int i=0; i<n; i++)
			trie.addWord(fs.next().toCharArray(), 0);

		PriorityQueue<Integer> returned=trie.dfs();
		int offset=trie.offset;
		long total=0;
		for (int i:returned) {
			total+=i+offset;
		}
		System.out.println(total);
	}
	
	private static class Trie implements Comparable<Trie> {
		boolean isWord=false;
		boolean isRoot=false;
		Trie[] connected=new Trie[26];
		ArrayList<Trie> children=new ArrayList<>();
		int size=0;
		int offset=0;
		
		public void addWord(char[] word, int index) {
			size++;
			if (index==word.length) {
				isWord=true;
				return;
			}
			int relevantEdge=word[index]-'a';
			if (connected[relevantEdge]==null)
				connected[relevantEdge]=new Trie();
			connected[relevantEdge].addWord(word, index+1);
		}

		public int compareTo(Trie o) {
			return size-o.size;
		}
		
		public PriorityQueue<Integer> dfs() {
			for (Trie t:connected) if (t!=null) children.add(t);
			Collections.sort(children);
			
			if (children.isEmpty()) {
				PriorityQueue<Integer> toReturn=new PriorityQueue<>((a, b)-> {return b-a;});
				toReturn.add(0);
				offset=0;
				return toReturn;
			}
			
			PriorityQueue<Integer> toReturn=children.get(0).dfs();
			offset=children.get(0).offset+1;
			for (int i=1; i<children.size(); i++) {
				PriorityQueue<Integer> returned=children.get(i).dfs();
				int oldOffset=children.get(i).offset+1;
				for (int j:returned)
					toReturn.add(j+oldOffset-offset);
			}
			if (!isRoot) {
				if (!isWord)
					toReturn.remove();
				toReturn.add(0-offset);
			}
			return toReturn;
		}
		
	}
	
	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		
		public FastScanner() {
			this(System.in);
		}
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