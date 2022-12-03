import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		DisjointSetForest dsf = new DisjointSetForest(n);
		long ans = 1;
		for (int i = 0; i < m; i++) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			if (dsf.find(x) != dsf.find(y)) {
				dsf.union(x, y);
				ans *= 2;
			}
		}
		System.out.println(ans);
	}
}

class DisjointSetForest {
	int[] parent;
	int[] rank;
	
	DisjointSetForest(int n) {
		parent = new int[n];
		Arrays.fill(parent, -1);
		rank = new int[n];
	}
	
	int find(int x) {
		if (parent[x] == -1) {
			return x;
		} else {
			return parent[x] = find(parent[x]);
		}
	}
	
	void union(int x, int y) {
		x = find(x);
		y = find(y);
		if (x != y) {
			if (rank[x] < rank[y]) {
				parent[x] = y;
			} else {
				parent[y] = x;
				if (rank[x] == rank[y]) {
					rank[x]++;
				}
			}
		}
	}
}