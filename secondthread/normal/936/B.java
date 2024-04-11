import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(i);
		for (int i=0; i<n; i++) {
			nodes[i].outDegree=fs.nextInt();
			for (int j=0; j<nodes[i].outDegree; j++) {
				int next=fs.nextInt()-1;
				nodes[i].canReach.add(nodes[next]);
				nodes[next].canReachMe.add(nodes[i]);
			}
		}
		
		//topsort for ties
		ArrayDeque<Node> toRemove=new ArrayDeque<>();
		for (Node nn:nodes) {
			if (nn.outDegree!=0) continue;
			toRemove.add(nn);
		}
		while (!toRemove.isEmpty()) {
			Node next=toRemove.removeFirst();
			next.isTieNode=false;
			for (Node nn:next.canReachMe) {
				nn.outDegree--;
				if (nn.outDegree==0) toRemove.add(nn);
			}
		}
		
		//topsort for wins/loses
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		for (Node nn:nodes) {
			if (nn.canReach.size()==0) {
				nn.canLose=true;
				bfs.add(nn);
			}
		}
		while (!bfs.isEmpty()) {
			Node next=bfs.remove();
			for (Node nn:next.canReachMe) {
				if (next.canLose && !nn.canWin) {
					nn.canWin=true;
					nn.winFrom=next.index;
					bfs.add(nn);
				}
				if (next.canWin && !nn.canLose) {
					nn.canLose=true;
					nn.loseFrom=next.index;
					bfs.add(nn);
				}
			}
		}
		
		int startNode=fs.nextInt()-1;
		//can tie if nodes[startNode].isTieNode;
		if (nodes[startNode].canWin) {
			PrintWriter out=new PrintWriter(System.out);
			out.println("Win");
			boolean isWin=true;
			while (nodes[startNode].canReach.size()!=0) {
				out.print(startNode+1+" ");
				if (isWin) startNode=nodes[startNode].winFrom;
				else startNode=nodes[startNode].loseFrom;
				isWin^=true;
			}
			out.println(startNode+1);
			out.close();
			return;
		}
		
		//otherwise, bfs to see if I can reach a lose state
		bfs=new ArrayDeque<>();
		bfs.add(nodes[startNode]);
		nodes[startNode].visited=true;
		while (!bfs.isEmpty()) {
			Node next=bfs.remove();
			if (next.isTieNode) {
				System.out.println("Draw");
				return;
			}
			for (Node adj:next.canReach) {
				if (!adj.visited) {
					adj.visited=true;
					bfs.add(adj);
				}
			}
		}
		System.out.println("Lose");
	}
	
	static class Node {
		boolean isTieNode=true;
		boolean canWin=false, canLose=false;
		int winFrom=-1;
		int loseFrom=-1;
		int outDegree=0;
		int index;
		ArrayList<Node> canReachMe=new ArrayList<>();
		ArrayList<Node> canReach=new ArrayList<>();
		boolean visited=false;
		
		public Node(int index) {
			this.index=index;
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