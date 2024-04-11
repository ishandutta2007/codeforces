import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Scanner;

public class _LiftLevel5B {

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node(i);
			for (int i=1; i<n; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].adj.add(nodes[a]);
			}
			int k1=fs.nextInt();
			for (int i=0; i<k1; i++) {
				int ind=fs.nextInt()-1;
				nodes[ind].inSubtree=true;
			}
			int k2=fs.nextInt();
			boolean[] otherPicked=new boolean[n];
			int firstOtherPicked=-1;
			for (int i=0; i<k2; i++) otherPicked[firstOtherPicked=(fs.nextInt()-1)]=true;
			System.out.println("B "+(firstOtherPicked+1)); System.out.flush();
			int hisNode=fs.nextInt()-1;
			
			bfs(nodes[hisNode]);
			Node closest=null;
			for (Node nn:nodes) {
				if (nn.inSubtree) {
					if (closest==null || closest.dist>nn.dist) closest=nn;
				}
			}
			
			System.out.println("A "+(closest.index+1)); System.out.flush();
			int hisVersion=fs.nextInt()-1;
			if (otherPicked[hisVersion]) {
				System.out.println("C "+(closest.index+1));
			}
			else {
				System.out.println("C -1");
			}
			System.out.flush();
		}
	}
	
	static void bfs(Node from) {
		from.dist=0;
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		bfs.add(from);
		while (!bfs.isEmpty()) {
			Node next=bfs.remove();
			for (Node nn:next.adj) {
				if (nn.dist!=-1) continue;
				nn.dist=next.dist+1;
				bfs.add(nn);
			}
		}
	}
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int dist=-1;
		boolean inSubtree=false;
		int index;
		public Node(int index) {
			this.index=index;
		}
	}
	
}