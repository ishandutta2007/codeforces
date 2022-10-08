import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/*
2 4

1 2

1 2

1 1 1 2
2 2 1 2
1 2 2 2
1 2 1 1

2 1
1 2
1 2
2 2 1 2

6 1
3 2 1 3 1 3
1 2
1 3
2 4
2 5
4 6
1 4 1 5
 */
public class _700D4 {

	static Random random=new Random(5);
	static final boolean debug=false;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt();
		int nQ=fs.nextInt();
		int[] labels=fs.readArray(n);
		long[] randomized=new long[n+1];
		for (int i=0; i<=n; i++) randomized[i]=random.nextLong();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(randomized[labels[i]], i, labels[i]);
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].children.add(nodes[b]);
			nodes[b].children.add(nodes[a]);
		}
		int pstSize=n;
		int empty=createPST(0, pstSize);
		nodes[0].dfs(null, 0, empty, pstSize);
		for (int e=1; e<20; e++)
			for (Node nn:nodes)
				if (nn.lift[e-1]!=null)
					nn.lift[e]=nn.lift[e-1].lift[e-1];
		
		//12 seconds
		for (int qq=0; qq<nQ; qq++) {
			Node from=nodes[fs.nextInt()-1], to=nodes[fs.nextInt()-1];
			int min=fs.nextInt(), max=fs.nextInt();
			Node lca=from.LCA(to, 19);
			Node lcaPar=lca.par;
			int lcaParPST=lcaPar==null?empty:lcaPar.pst;

			long targetValue =rangeQuery(from.pst, 0, max, 0, pstSize) ^  
					rangeQuery(to.pst, 0, max, 0, pstSize) ^
					rangeQuery(lca.pst, 0, max, 0, pstSize) ^
					rangeQuery(lcaParPST, 0, max, 0, pstSize);
			
			//we want to find the earliest time it equals that targetSuffix
			
			int earliestTime=getXOR(from.pst, to.pst, lca.pst, lcaParPST, 0, pstSize, targetValue, max);
			if (earliestTime<min) {
				out.println(-1);
			}
			else {
				out.println(earliestTime);
			}
		}
		out.close();
	}
	
	static int getXOR(int p1, int p2, int p3, int p4, int leftmost, int rightmost, long targetValue, int rightOf) {
		if (leftmost==rightmost) {
			return leftmost;
		}
		int mid=(leftmost+rightmost)>>1;
		long leftXOR=rangeXOR[lChild[p1]]^rangeXOR[lChild[p2]]^rangeXOR[lChild[p3]]^rangeXOR[lChild[p4]];
		if (mid>=rightOf || leftXOR == targetValue) {
			//TODO: go left
			return getXOR(lChild[p1], lChild[p2], lChild[p3], lChild[p4], leftmost, mid, targetValue, rightOf);
		}
		else {
			return getXOR(rChild[p1], rChild[p2], rChild[p3], rChild[p4], mid+1, rightmost, targetValue^leftXOR, rightOf);
		}
	}
	
	//prefix xor equals
	//point sum;
	static long[] rangeXOR=new long[1_000_000_0];
	static int[] lChild=new int[1_000_000_0], rChild=new int[1_000_000_0];
	static int globalCounter=1;
		
	static int createPST(int leftmost, int rightmost) {
		int me=globalCounter++;
		if (leftmost!=rightmost) {
			int mid=(leftmost+rightmost)/2;
			lChild[me]=createPST(leftmost, mid);
			rChild[me]=createPST(mid+1, rightmost);
		}
		return me;
	}
	
	
	static int createPST(int lChildd, int rChildd, long rangeXORR) {
		int me=globalCounter++;
		lChild[me]=lChildd;
		rChild[me]=rChildd;
		rangeXOR[me]=rangeXORR;
		return me;
	}
	
	//need point update, range query
	
	static long rangeQuery(int me, int l, int r, int leftmost, int rightmost) {
		if (l<=leftmost && r>=rightmost) return rangeXOR[me];
		if (l>rightmost || r<leftmost) return 0;
		int mid=(leftmost+rightmost)>>1;
		return rangeQuery(lChild[me], l, r, leftmost, mid) ^rangeQuery(rChild[me], l, r, mid+1, rightmost);
	}
	
	static int pointXOR(int me, int i, long x, int leftmost, int rightmost) {
		if (leftmost==rightmost) {
			return createPST(0, 0, x^rangeXOR[me]);
		}
		int mid=(leftmost+rightmost)>>1;
		if (i<=mid) {
			int newLChild=pointXOR(lChild[me], i, x, leftmost, mid);
			return createPST(newLChild, rChild[me], rangeXOR[newLChild]^rangeXOR[rChild[me]]);
		}
		else {
			int newRChild=pointXOR(rChild[me], i, x, mid+1, rightmost);
			return createPST(lChild[me], newRChild, rangeXOR[lChild[me]]^rangeXOR[newRChild]);
		}
	}
	
//	static void printPST(PST pst, int leftmost, int rightmost) {
//		for (int i=leftmost; i<=rightmost; i++) System.out.print(pst.rangeQuery(i, i, leftmost, rightmost)+" ");
//		System.out.println();
//	}
	
	static class Node {
		int id;
		long data;
		int givenNumber;
		ArrayList<Node> children=new ArrayList<>();
		Node par;
		int depth;
		Node[] lift=new Node[20];
		int pst;
		
		public Node(long data, int id, int givenNumber) {
			this.data=data;
			this.givenNumber=givenNumber;
			this.id=id;
		}
		
		public void dfs(Node par, int depth, int pst, int pstSize) {
			this.par=lift[0]=par;
			this.depth=depth;
			this.pst=pointXOR(pst, givenNumber, data, 0, pstSize);
			if (par!=null) {
				children.remove(par);
			}
			for (Node nn:children) {
				nn.dfs(this, depth+1, this.pst, pstSize);
			}
		}
		
		public Node goUp(int toGoUp) {
			if (toGoUp==0) return this;
			int e=Integer.numberOfTrailingZeros(toGoUp);
			return lift[e].goUp(toGoUp-(1<<e));
		}
		
		public Node LCA(Node o, int maxLift) {
			if (depth!=o.depth) {
				if (depth>o.depth)
					return goUp(depth-o.depth).LCA(o, 19);
				return LCA(o.goUp(o.depth-depth), 19);
			}
			if (this==o) return this;
			if (lift[0]==o.lift[0]) return lift[0];
			while (lift[maxLift]==o.lift[maxLift]) maxLift--;
			return lift[maxLift].LCA(o.lift[maxLift], maxLift);
		}
		
		public String toString() {
			return id+"";
		}
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
		
		int[] readArray(int n) {
			int[] a=new int[n]; 
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		int nextInt () {
			return Integer.parseInt(next());
		}
	}

}