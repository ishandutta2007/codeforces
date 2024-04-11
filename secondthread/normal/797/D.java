import java.util.Arrays;
import java.util.Scanner;

public class BrokenBST {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int numberOfNodes=s.nextInt();
		Node[] nodes=new Node[numberOfNodes];
		for (int i=0; i<numberOfNodes; i++) {
			nodes[i]=new Node();
		}
		
		for (int i=0; i<nodes.length; i++) {
			nodes[i].value=s.nextInt();
			int left=s.nextInt(), right=s.nextInt();
			if (left!=-1) {
				nodes[i].left=nodes[left-1];
				nodes[left-1].hasParent=true;
			}
			if (right!=-1) {				
				nodes[i].right=nodes[right-1];
				nodes[right-1].hasParent=true;
			}
		}
		
		Node head=null;
		for (Node n:nodes) {
			if (!n.hasParent) {
				head=n;
			}
		}
		
		head.expand(-1000000001, 1000000001);
		
		
		Arrays.sort(nodes);
		int valueReachable=-1000000001;
		for (int i=0; i<nodes.length; i++) {
			if (nodes[i].value==valueReachable) {
				nodes[i].reachable=true;
			}
			else if (nodes[i].reachable) {
				valueReachable=nodes[i].value;
				for (int j=i-1; j>=0&&nodes[j].value==valueReachable; j--) {
					nodes[j].reachable=true;
				}
			}
		}

		int unreachableCount=0;
		for (Node n:nodes) {
			if (!n.reachable) {
				unreachableCount++;
			}
		}
		System.out.println(unreachableCount);
	}

}

class Node implements Comparable {
	public Node left=null, right=null;
	public int value=0;
	public boolean reachable=false, hasParent=false;
	
	public void expand(int minPossible, int maxPossible) {
		if (value<minPossible||value>maxPossible) {
			reachable=false;
		}
		else {
			reachable=true;
		}
		if (left!=null) {
			left.expand(minPossible, Math.min(maxPossible, value-1));
		}
		if (right!=null) {
			right.expand(Math.max(minPossible, value+1), maxPossible);
		}
	}

	public int compareTo(Object o) {
		Node other=(Node)o;
		return value-other.value;
	}
}