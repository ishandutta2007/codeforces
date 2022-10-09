import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class TerrableProblem {

	public static void main(String[] args) throws NumberFormatException, IOException, InterruptedException {
		BufferedReader s=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(s.readLine());
		ArrayList<Number> A=new ArrayList<>(), B=new ArrayList<>();
		String[] line=s.readLine().split(" ");
		for (int i=0; i<n; i++) {
			A.add(new Number(i, Integer.parseInt(line[i])));
		}
		line=s.readLine().split(" ");
		for (int i=0; i<n; i++) {
			B.add(new Number(i, Integer.parseInt(line[i])));
		}
		Collections.sort(A);
		Collections.sort(B);
		Node bst=getBST(A);
		int[] toReturn=new int[B.size()];
		for (int i=B.size()-1; i>=0; i--) {
			Node toRemove=getSmallestGreaterOrEqualTo(bst, toReturn[i]);
			//printTree(bst);
			//Thread.sleep(10);
			//System.out.println();
			//System.out.println(toRemove.value);
			if (toRemove!=bst) {
				toRemove.remove();
			}
			else {
				bst=toRemove.remove();
				//System.out.println("here "+(bst==null));
			}
			toReturn[B.get(i).originalSpot]=toRemove.value;
		}
		for (int i:toReturn) {
			System.out.print(i+" ");
		}
	}
	
	private static void printTree(Node bst) {
		if (bst==null) {
			return;
		}
		System.out.print(bst.value+"{");
		if (bst.getLeftChild()!=null)
			printTree(bst.getLeftChild());
		System.out.print(",");
		if (bst.getRightChild()!=null)
			printTree(bst.getRightChild());
		System.out.print("}");
	}
	
	private static Node getBST(ArrayList<Number> numbers) {
		Node fake=new Node(-1);
		generateRangeAsLeftChild(fake, 0, numbers.size()-1, numbers);
		return fake.remove();
	}
	
	private static void generateRangeAsLeftChild(Node n, int start, int end, ArrayList<Number> numbers) {
		if (start>end) {
			return;
		}
		int middleIndex=(start+end)/2;
		n.setLeftChild(new Node(numbers.get(middleIndex).value));
		if (start!=end) {
			
			generateRangeAsLeftChild(n.getLeftChild(), start, middleIndex-1, numbers);
			generateRangeAsRightChild(n.getLeftChild(), middleIndex+1, end, numbers);
		}
	}
	
	private static void generateRangeAsRightChild(Node n, int start, int end, ArrayList<Number> numbers) {
		if (start>end) {
			return;
		}
		int middleIndex=(start+end)/2;
		n.setRightChild(new Node(numbers.get(middleIndex).value));
		if (start!=end) {
			generateRangeAsLeftChild(n.getRightChild(), start, middleIndex-1, numbers);
			generateRangeAsRightChild(n.getRightChild(), middleIndex+1, end, numbers);
		}
	}
	
	public static Node getSmallestGreaterOrEqualTo(Node bst, int value) {
		if (bst==null) {
			return null;
		}
		if (bst.value>=value) {
			
			Node smaller=getSmallestGreaterOrEqualTo(bst.getLeftChild(), value);
			if (smaller!=null) {
				return smaller;
			}
			return bst;
		}
		return getSmallestGreaterOrEqualTo(bst.getRightChild(), value);
	}
}

class Number implements Comparable<Number> {
	int originalSpot, value;
	public Number(int originalSpot, int value) {
		this.originalSpot=originalSpot;
		this.value=value;

	}
	
	public int compareTo(Number o) {
		return value-o.value;
	}
	
}

class Node {
	private Node leftChild, rightChild;
	private Node parent;
	int value;
	
	public Node(int value) {
		this.value=value;
	}
	
	public void setLeftChild(Node n) {
		n.parent=this;
		this.leftChild=n;
	}
	
	public void setRightChild(Node n) {
		n.parent=this;
		this.rightChild=n;
	}
	
	public Node getLeftChild() {
		return leftChild;
	}
	
	public Node getRightChild() {
		return rightChild;
	}
	
	public Node getParent() {
		return parent;
	}
	
	public Node getGreatestChild() {
		Node n=this;
		while (n.rightChild!=null) {
			n=n.rightChild;
		}
		return n;
	}
	
	public Node getLeastChild() {
		Node n=this;
		while (n.leftChild!=null) {
			n=n.leftChild;
		}
		return n;
	}
	
	public Node remove() {
		if (leftChild==null&&rightChild==null) {
			if (parent==null) {
				return null;
			}
			if (parent.leftChild==this) {
				parent.leftChild=null;
			}
			if (parent.rightChild==this) {
				parent.rightChild=null;
			}
		}
		else if (rightChild==null) {
			if (parent==null) {
				leftChild.parent=null;
				return leftChild;
			}
			if (parent.leftChild==this) {
				parent.setLeftChild(leftChild);
			}
			if (parent.rightChild==this) {
				parent.setRightChild(leftChild);
			}
		}
		else if (leftChild==null) {
			if (parent==null) {
				rightChild.parent=null;
				return rightChild;
			}
			if (parent.leftChild==this) {
				parent.setLeftChild(rightChild);
			}
			if (parent.rightChild==this) {
				parent.setRightChild(rightChild);
			}
		}
		else {
			if (parent==null) {
				Node replacement=getLeastChild();
				replacement.remove();
				replacement.parent=null;
				return replacement;
			}
			if (parent.leftChild==this) {
				Node replacement=getGreatestChild();
				replacement.remove();
				parent.setLeftChild(replacement);
				return replacement;
			}
			if (parent.rightChild==this) {
				Node replacement=getLeastChild();
				replacement.remove();
				parent.setRightChild(replacement);
				return replacement;
			}
		}
		return null;
	}
}