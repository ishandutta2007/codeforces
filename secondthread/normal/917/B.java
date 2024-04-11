import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {
	private static Node[] nodes;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int m=fs.nextInt();
		nodes=new Node[n];
		for (int i=0; i<n; i++)
			nodes[i]=new Node(i);
		for (int i=0; i<m; i++) {
			int from=fs.nextInt()-1;
			int to=fs.nextInt()-1;
			int weight=fs.next().charAt(0)-'a';
			nodes[from].addEdge(nodes[to], weight);
		}
		
		int[][][][] dp=new int[n][n][2][26];
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				for (int k=0; k<2; k++)
					Arrays.fill(dp[i][j][k], -1);
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				int winner=go(dp, i, j, 0, 0);
				if (winner==0) {
					System.out.print("A");
				}
				else {
					System.out.print("B");
				}
			}
			System.out.println();
		}
		
	}
	
	private static int go(int[][][][] dp, int aPos, int bPos, int turn, int lastChar) {
		if (dp[aPos][bPos][turn][lastChar]!=-1)
			return dp[aPos][bPos][turn][lastChar];
		boolean canWin=false;
		if (turn==0) {
			for (int i=0; i<nodes[aPos].connected.size(); i++) {
				if (nodes[aPos].weights.get(i)<lastChar) {
					continue;
				}
				if (go(dp, nodes[aPos].connected.get(i).index, bPos, -(turn-1), nodes[aPos].weights.get(i))==turn) {
					canWin=true;
				}
			}
		}
		else {
			for (int i=0; i<nodes[bPos].connected.size(); i++) {
				if (nodes[bPos].weights.get(i)<lastChar) {
					continue;
				}
				if (go(dp, aPos, nodes[bPos].connected.get(i).index, -(turn-1), nodes[bPos].weights.get(i))==turn) {
					canWin=true;
				}
			}
		}
		
		if (canWin) {
			return dp[aPos][bPos][turn][lastChar]=turn;
		}
		else {
			return dp[aPos][bPos][turn][lastChar]=-(turn-1);
		}
	}
	
	static class Node {
		ArrayList<Node> connected=new ArrayList<>();
		ArrayList<Integer> weights=new ArrayList<>();
		int index;
		
		public Node(int index) {
			this.index=index;
		}
		
		public void addEdge(Node o, int weight) {
			connected.add(o);
			weights.add(weight);
		}
		
	}
	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
			st = new StringTokenizer("");
		}

		public FastScanner(File f) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(f));
			st = new StringTokenizer("");
		}

		String next() {
			while (!st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
	
}