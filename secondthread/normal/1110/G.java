import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class _GlobalRound1G {
	
	static long oo=(long)1e18;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			ArrayList<Node> nodesList=new ArrayList<>();
			int n=fs.nextInt();
			for (int i=0; i<n; i++) nodesList.add(new Node());
			for (int i=1; i<n; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodesList.get(a).adj.add(nodesList.get(b));
				nodesList.get(b).adj.add(nodesList.get(a));
			}
			char[] colors=fs.next().toCharArray();
			for (int i=0; i<n; i++) nodesList.get(i).white=colors[i]=='W';
			for (int i=0; i<nodesList.size(); i++) {
				Node nn=nodesList.get(i);
				if (nn.white) {
					Node n1=new Node();
					Node n2=new Node();
					Node n3=new Node();
					nn.adj.add(n1);
					n1.adj.add(nn);
					n1.adj.add(n2);
					n2.adj.add(n1);
					n1.adj.add(n3);
					n3.adj.add(n1);
					nodesList.add(n1);
					nodesList.add(n2);
					nodesList.add(n3);
				}
			}
			n=nodesList.size();
			Node[] nodes=new Node[n];
			for (int i=0; i<nodes.length; i++)
				nodes[i]=nodesList.get(i);
			boolean win=false;
			for (Node nn:nodes) {
				if (nn.adj.size()>3) {
					win=true;
				}
				if (nn.adj.size()==3) {
					Collections.sort(nn.adj);
					if (nn.adj.get(1).adj.size()>1) {
						//then we have two nontrivial edges
						win=true;
					}
				}
			}
			
			//only case left is the bone case
			int interestingNodes=0;
			for (Node nn:nodes) if (nn.adj.size()>2) interestingNodes++;
			if (interestingNodes==2 && n%2==1) win=true;
			
			System.out.println(win?"White":"Draw");
		}
	}
	
	static class Node implements Comparable<Node> {
		ArrayList<Node> adj=new ArrayList<>();
		boolean white;
		
		public int compareTo(Node o) {
			return Integer.compare(adj.size(), o.adj.size());
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
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		
	}

}