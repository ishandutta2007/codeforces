import java.lang.*;
import java.util.*;
import java.io.*;

public class CF1067B {
	public static void getDistances(int v, int p, int cLevel, int[] dist, int[] par, ArrayList<ArrayList<Integer>> tree) {
//		System.out.printf("gd %d %d %d\n", v, cLevel, p);
//		if (p == -1) System.out.printf("ROOT CALL\n");
		dist[v] = cLevel;
		par[v] = p;
		for (int k = 0; k < tree.get(v).size(); ++k) {
			int nxt = tree.get(v).get(k);
			if (nxt == p) continue;
			getDistances(nxt, v, cLevel + 1, dist, par, tree);
		}
	}
	public static ArrayList<Integer> getDiameter (ArrayList<ArrayList<Integer>> tree) {
		int n = tree.size();
		ArrayList<Integer> ans = new ArrayList<Integer>();
		int[] dist = new int[n], par = new int[n];
		getDistances(0, -1, 0, dist, par, tree);
		int secondSearch = 0;
		for (int i = 1; i < n; ++i) {
			if (dist[i] > dist[secondSearch]) secondSearch = i;
		}
		getDistances(secondSearch, -1, 0, dist, par, tree);
		int thirdSearch = 0;
		for (int i = 1; i < n; ++i) {
			if (dist[i] > dist[thirdSearch]) thirdSearch = i;
		}
		for (int i = thirdSearch; i != secondSearch; i = par[i]) {
			ans.add(i);
		}
		ans.add(secondSearch);
		return ans;
	}
	public static void main(String[] args) throws IOException {
		Reader.init(System.in);
		int n = Reader.nextInt(), k = Reader.nextInt();
		ArrayList<ArrayList<Integer>> tree = new ArrayList<ArrayList<Integer>>(n);
		for (int i = 0; i < n; ++i) tree.add(new ArrayList<Integer>());
		for (int i = 0; i < n - 1; ++i) {
			int u = Reader.nextInt(), v = Reader.nextInt();
			--u; --v;
			tree.get(u).add(v);
			tree.get(v).add(u);
		}
		if (k > 69696969) {
			System.out.printf("No\n");
			return;
		}
		ArrayList<Integer> x = getDiameter(tree);	
		if (x.size() != k * 2 + 1) {
			System.out.printf("No\n");
			return;
		}
		int center = x.get(k);
		int[] dist = new int[n], par = new int[n];
		getDistances(center, -1, 0, dist, par, tree);
		// verify that root has degree >= 3, leaves are at dist k, all other vertices have degree >= 4
		boolean isValid = true;
		for (int i = 0; i < n; ++i) {
			if (i == center) {
				if (tree.get(i).size() < 3) isValid = false;
			} else if (tree.get(i).size() == 1) {
				if (dist[i] != k) isValid = false;
			} else {
				if (tree.get(i).size() < 4) isValid = false;
			}
		}
		if (isValid) System.out.printf("Yes\n");
		else System.out.printf("No\n");
		return;
	}
};

class Reader {
	static BufferedReader reader;
	static StringTokenizer tokenizer;

	/** call this method to initialize reader for InputStream */
	static void init(InputStream input) {
		reader = new BufferedReader(
					new InputStreamReader(input) );
		tokenizer = new StringTokenizer("");
	}

	/** get next word */
	static String next() throws IOException {
		while ( ! tokenizer.hasMoreTokens() ) {
			//TODO add check for eof if necessary
			tokenizer = new StringTokenizer(
				reader.readLine() );
		}
		return tokenizer.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt( next() );
	}
	static long nextLong() throws IOException {
		return Long.parseLong( next() );
	}
	static double nextDouble() throws IOException {
		return Double.parseDouble( next() );
	}
}