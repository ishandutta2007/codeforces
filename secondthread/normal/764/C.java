import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class ProblemC {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		int numberOfNodes=Integer.parseInt(reader.readLine());
		Node[] nodes=new Node[numberOfNodes];
		for (int i=0; i<numberOfNodes; i++) {
			nodes[i]=new Node(i);
		}
		
		for (int i=0; i<numberOfNodes-1; i++) {
			String[] edge=reader.readLine().split(" ");
			int first=Integer.parseInt(edge[0])-1, second=Integer.parseInt(edge[1])-1;
			nodes[first].addConnection(nodes[second]);
			nodes[second].addConnection(nodes[first]);
		}
		
		String[] colors=reader.readLine().split(" ");
		for (int i=0; i<numberOfNodes; i++) {
			nodes[i].color=Integer.parseInt(colors[i]);
		}
		
		nodes[0].dfs(null, 0);
		Node farthest=nodes[0];
		for (Node n:nodes) {
			if (n.distance>farthest.distance) {
				farthest=n;
			}
		}
		
		farthest.dfs(null, 0);
		
		for (Node n:nodes) {
			if (n.distance>2) {
				System.out.println("NO");
				System.err.println("1");
				return;
			}
		}
		int oneDistanceCount=0, twoDistanceCount=0, zeroDistanceCount=0;
		for (Node n:nodes) {
			if (n.distance==0) {
				zeroDistanceCount++;
			}
			if (n.distance==1) {
				oneDistanceCount++;
			}
			if (n.distance==2) {
				twoDistanceCount++;
			}
		}
		if (oneDistanceCount==1) {
			//yes, the only one with 1
			System.out.println("YES");
			for (Node n:nodes) {
				if (n.distance==1) {
					System.out.println(n.index+1);
				}
			}
		}
		else if (twoDistanceCount>0) {
			Node oneToTake=null;
			for (Node n:nodes) {
				if (n.distance==1&&n.hasForeignNeighbors(null)) {
					if (oneToTake==null) {
						oneToTake=n;
					}
					else {
						System.out.println("NO");
						return;
					}
				}
			}
			System.out.println("YES\n"+(oneToTake.index+1));
			return;
		}
		else {
			LinkedList<Node> zerosBorderingOnes=farthest.getAllZerosBordingOnes(null);
			if (zerosBorderingOnes.size()>1) {
				System.out.println("NO");
			}
			else {
				if (zerosBorderingOnes.size()==0) {
					System.out.println("YES\n1");
				}
				else {
					System.out.println("YES\n"+(zerosBorderingOnes.get(0).index+1));
				}
			}
		}
	}

}

class Node {
	public int index;
	public int color;
	public ArrayList<Node> connected=new ArrayList<>();
	public int distance=0;
	
	public Node(int index) {
		this.index=index;
	}
	
	public void addConnection(Node other) {
		connected.add(other);
	}
	
	public void dfs(Node parent, int distance) {
		this.distance=distance;
		for (Node n:connected) {
			if (n!=parent) {
				if (n.color==color) {
					n.dfs(this, distance);
				}
				else {					
					n.dfs(this, distance+1);
				}
			}
		}
	}
	
	public LinkedList<Node> getAllZerosBordingOnes(Node parent) {
		boolean addedMyself=false;
		LinkedList<Node> toReturn=new LinkedList<Node>();
		for (Node n:connected) {
			if (n==parent) {
				continue;
			}
			if (n.distance==1) {
				if (!addedMyself) {
					addedMyself=true;
					toReturn.add(this);
				}
			}
			if (n.distance==0) {
				toReturn.addAll(n.getAllZerosBordingOnes(this));
			}
		}
		return toReturn;
	}
	
	public boolean hasForeignNeighbors(Node parent) {
		for (Node n:connected) {
			if (n.distance!=distance) {
				return true;
			}
		}
		return false;
	}
}