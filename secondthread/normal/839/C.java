import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class journey {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(in.readLine());
		ArrayList<Node> nodes=new ArrayList<>();
		for (int i=0; i<n; i++) {
			nodes.add(new Node());
		}
		for (int i=0; i<n-1; i++) {
			String[] line=in.readLine().split(" ");
			int a=Integer.parseInt(line[0])-1;
			int b=Integer.parseInt(line[1])-1;
			nodes.get(a).addChild(nodes.get(b));
			nodes.get(b).addChild(nodes.get(a));
		}
		nodes.get(0).root();
		System.out.printf("%06f\n", nodes.get(0).getAverageHeight());
	}

}

class Node {
	ArrayList<Node> children=new ArrayList<>();
	
	public void addChild(Node toAdd) {
		children.add(toAdd);
	}
	
	public void removeChilde(Node child) {
		children.remove(child);
	}
	
	public double getAverageHeight() {
		if (children.isEmpty()) {
			return 0;
		}
		else {
			double total=0;
			for (Node n:children) {
				total+=n.getAverageHeight();
			}
			total/=children.size();
			return total+1;
		}
	}
	
	public void root() {
		for (Node n:children) {
			n.removeChilde(this);
			n.root();
		}
	}
}