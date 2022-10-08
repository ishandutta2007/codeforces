import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
/*
15
5 2
2 3
3 4
4 1
1 6
6 7
7 8
1 9
9 10
9 11
9 12
9 13
9 14val
9 15

15
1 2
2 3
3 4
4 5
5 6
6 7
7 8
5 9
9 10
9 11
9 12
9 13
9 14
9 15

4
2 3
2 1
2 4

4
1 2
1 3
1 4

5
4 2
2 5
5 1
5 3

5
5 4 
4 3
3 2
2 1


8
5 4
2 4
3 4
4 1
1 6
1 7
1 8
 */
public class C2 {
	
	static int n;
	static long[][] dp;

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		n=fs.nextInt();
		dp=new long[n][n];
		for (int i=0; i<n; i++) Arrays.fill(dp[i], -1);
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(i);
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		nodes[0].dfs(null);
		long best=-1;
		for (Node nn:nodes) {
			if (nn.par==null) continue;
			best=Math.max(best, go(nn.id, nn.par.id, nn.par.id, nn.id, nodes));
		}
		System.out.println(best);
	}
	
	static long go(int n1, int n2, int n1Near, int n2Near, Node[] nodes) {
		Node h1=nodes[n1], h2=nodes[n2], h1Adj=nodes[n1Near], h2Adj=nodes[n2Near];
		if (dp[n1][n2]!=-1) return dp[n1][n2];
		if (h1.isLeaf() && h2.isLeaf()) {
			return 1;
		}
		long ans=0;
		ArrayList<Node> candidates=new ArrayList<>();
		candidates.addAll(h1.adj);
		if (h1.par!=null) candidates.add(h1.par);
		
		for (Node nn:candidates) {
			if (nn==h1Adj) continue;
			long size=h1.sizeExcept(h1Adj), oSize=h2.sizeExcept(h2Adj);
			ans=Math.max(ans, size*oSize+go(nn.id, h2.id, h1.id, h2Adj.id, nodes));
		}
		
		candidates.clear();
		candidates.addAll(h2.adj);
		if (h2.par!=null) candidates.add(h2.par);
		for (Node nn:candidates) {
			if (nn==h2Adj) continue;
			long size=h1.sizeExcept(h1Adj), oSize=h2.sizeExcept(h2Adj);
			ans=Math.max(ans, size*oSize+go(nn.id, h1.id, h2.id, h1Adj.id, nodes));
		}
//		System.out.println("Answer for "+n1+" "+n2+" is "+ans);
		return dp[n1][n2]=ans;
	}
	

	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int id;
		Node par;
		long subtreeSize=1;
		public Node(int id) {
			this.id=id;
		}
		
		public void dfs(Node par) {
			this.par=par;
			if (par!=null) adj.remove(par);
			for (Node nn:adj) {
				nn.dfs(this);
				subtreeSize+=nn.subtreeSize;
			}
		}
		long sizeExcept(Node o) {
			if (o==par) {
				return subtreeSize;
			}
			return n-o.subtreeSize;
		}
		
		boolean isLeaf() {
			if (par==null) return adj.size()<=1;
			return adj.size()==0;
		}
		
		
	}
	
}