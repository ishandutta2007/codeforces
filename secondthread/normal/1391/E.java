import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*
1
6 5
1 4
2 5
3 6
1 5
3 5
 */
public class E {

	static boolean killMePls = false;
	public static void main(String[] args) throws Exception {
		Thread.UncaughtExceptionHandler h = new Thread.UncaughtExceptionHandler() {
			public void uncaughtException(Thread t, Throwable e) {
				e.printStackTrace();
				killMePls = true;}
		};
		Thread t = new Thread(null, ()->m(), "", 1<<26);
		t.setUncaughtExceptionHandler(h);
		t.start();
		t.join();
		if(killMePls) {
			throw null;
		}
	}
	
	public static void m() {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		outer: for (int tt=0; tt<T; tt++) {
			firstOfPair=new NodeList();
			secondOfPair=new NodeList();
			int n=fs.nextInt(), m=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node(i+1);
			for (int i=0; i<m; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].adj.add(nodes[a]);
			}
			nodes[0].dfs(null, 1);
			for (Node nn:nodes) {
				if (nn.depth*2>=n) {
					out.println("PATH");
					out.println(nn.depth);
					while (nn.par!=null) {
						out.print(nn.id+" ");
						nn=nn.par;
					}
					out.println(nn.id);
					continue outer;
				}
			}
			if ((firstOfPair.size()+secondOfPair.size())*2>=n) {
				out.println("PAIRING");
				out.println(firstOfPair.size());
				while (!firstOfPair.isEmpty())
					out.println(firstOfPair.remove().id+" "+secondOfPair.remove().id);
			}	
			else {
				throw null;
			}
		}
		out.close();
	}
	
	static NodeList firstOfPair=new NodeList(),
			secondOfPair=new NodeList();
	
	static class Node {
		NodeList adj=new NodeList();
		Node par;
		boolean visited;
		int id, depth;
		
		public Node(int id) {
			this.id=id;
		}
		
		//returns unmatched things
		public NodeList dfs(Node from, int depth) {
			this.par=from;
			this.depth=depth;
			this.visited=true;
			NodeList haveLeft=new NodeList();
			for (int i=0; i<=adj.end; i++) {
				Node o=adj.nodes[i];
				if (o==from) continue; //par
				if (o.visited) continue;//back-edge
				NodeList unpaired=o.dfs(this, depth+1);
				while (!haveLeft.isEmpty() && !unpaired.isEmpty()) {
					firstOfPair.add(haveLeft.remove());
					secondOfPair.add(unpaired.remove());
				}
				if (!unpaired.isEmpty()) {
					haveLeft=unpaired;
				}
			}
			haveLeft.add(this);
			return haveLeft;
		}
	}
	
	static class NodeList {
		int start=0, end=-1;
		Node[] nodes=new Node[3];
		public void add(Node n) {
			if (end+1==nodes.length) {
				Node[] resized=new Node[nodes.length*2];
				for (int i=start; i<=end; i++)
					resized[i-start]=nodes[i];
				end-=start;
				start-=start;
				nodes=resized;
			}
			nodes[++end]=n;
		}
		
		public int size() {
			return end-start+1;
		}
		
		public Node remove() {
			return nodes[start++];
		}
		
		public boolean isEmpty() {
			return start>end;
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public FastScanner() {
			try {
				br=new BufferedReader(new FileReader("F.in"));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		
		public String next() {
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
		
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}

}