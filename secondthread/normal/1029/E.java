import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
/*
7
1 2
2 3
2 4
4 5
4 6
5 7

5
1 2
2 3
3 4

7
1 2
2 3
3 4
3 5
3 6
6 7
 */
public class Round506e {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++)
			nodes[i]=new Node(i+1);
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		nodes[0].dfs(null);
		int ans=0;
		for (Node nn:nodes[0].adj) {
			for (Node nnn:nn.adj) {
				ans+=nnn.go(1, 0);
			}
		}
		System.out.println(ans);
	}
	
	static class Node {
		int[][] dp=new int[2][2];
		ArrayList<Node> adj=new ArrayList<>();
		int index;
		
		public Node (int index) {
			this.index=index;
		}
		
		public void dfs(Node par) {
			if (par!=null) adj.remove(par);
			for (Node n:adj) {
				n.dfs(this);
			}
			for (int i=0; i<dp.length; i++)
				Arrays.fill(dp[i], -1);
		}
		
		int go(int connectedToParent, int needToConnect) {
			if (dp[connectedToParent][needToConnect]!=-1) return dp[connectedToParent][needToConnect];
			if (needToConnect!=0) {
				int ans=1;
				//then every kid gets me for free
				for (Node nn:adj) {
					ans+=nn.go(1, 0);
				}
				return dp[connectedToParent][needToConnect]=ans;
			}
			if (adj.size()==0) {
				return connectedToParent>0?0:1;
			}
			int costOfConnecting=1;
			for (Node nn:adj) {
				costOfConnecting+=nn.go(1, 0);
			}
			
			//we need to force at least one person to connect
			int fullCost=0;
			for (Node nn:adj) {
				if (nn.go(0, 0)>nn.go(0, 1)) throw null;
				fullCost+=nn.go(0, 0);
			}
			int costOfNotConnecting=1000_000_000;
			if (connectedToParent==0) {
				//then we need to force at least one person to connect
				for (Node nn:adj) {
					costOfNotConnecting=Math.min(costOfNotConnecting, fullCost-nn.go(0, 0)+nn.go(0, 1));
				}
			}
			else {
				costOfNotConnecting=fullCost;
			}
			return dp[connectedToParent][needToConnect]=Math.min(costOfConnecting, costOfNotConnecting);
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		String next() {
			while (!st.hasMoreElements())
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
	}

}