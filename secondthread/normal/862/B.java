import java.util.ArrayList;
import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		Node[] nodes=new Node[n];
		ArrayList<Integer>[] adj = new ArrayList[n];
		for (int i=0; i<n; i++) {
			nodes[i]=new Node();
		}
		for (int i=0; i<n-1; i++) {
			int a=s.nextInt()-1;
			int b=s.nextInt()-1;
			nodes[a].addChild(nodes[b]);
			nodes[b].addChild(nodes[a]);
		}
		nodes[0].label(true, null);
		int leftCount=0, rightCount=0;
		for (Node node:nodes) {
			if (node.left) {
				leftCount++;
			}
			else {
				rightCount++;
			}
		}
		System.out.println(leftCount*(long)rightCount-(n-1));
		
	}
	
	public static class Node {
		ArrayList<Node> children=new ArrayList<>();
		boolean left=false;
		
		public Node() {
			
		}
		
		public void addChild(Node other) {
			children.add(other);
		}
		
		public void label(boolean b, Node parent) {
			left=b;
			for (Node n:children) {
				if (n!=parent) {
					n.label(!b, this);
				}
			}
		}
	}
}