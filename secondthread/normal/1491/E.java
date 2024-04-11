	import java.io.BufferedReader;
	import java.io.IOException;
	import java.io.InputStreamReader;
	import java.util.ArrayList;
	import java.util.StringTokenizer;
	
	public class GR13UpsolvingE {
	
		static int[] fibs;
		static int[] indexOfFib;
		
		public static void main(String[] args) {
			FastScanner fs=new FastScanner();
			int n=fs.nextInt();
			fibs=new int[31];
			indexOfFib=new int[3_000_000];
			fibs[0]=fibs[1]=1;
			indexOfFib[1]=1;
			for (int i=2; i<fibs.length; i++) {
				fibs[i]=fibs[i-1]+fibs[i-2];
//				System.out.println(fibs[i]);
				indexOfFib[fibs[i]]=i;
			}
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node();
			for (int i=1; i<n; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].adj.add(nodes[a]);
			}
			boolean works=go(nodes[0]);
			System.out.println(works?"YES":"NO");
		}
		
		static boolean go(Node n) {
			ArrayList<Node> relevant=new ArrayList<>();
			n.dfs(null, relevant);
			if (n.size<4) return true;
			if (indexOfFib[n.size]==0) return false;
			for (Node nn:relevant) {
				if (indexOfFib[nn.size]+1==indexOfFib[n.size] || indexOfFib[nn.size]+2 == indexOfFib[n.size]) {
					//chop at this guy
					Node par=nn.par;
					nn.adj.remove(par);
					par.adj.remove(nn);
					if (!go(nn)) {
//						nn.adj.add(par);
//						par.adj.add(nn);
						return false;
					}
					if (!go(par)) {
//						nn.adj.add(par);
//						par.adj.add(nn);
						return false;
					}
					return true;
				}
			}
			
			return false;
		}
		
		static class Node {
			ArrayList<Node> adj=new ArrayList<>();
			int size;
			Node par;
			
			public void dfs(Node par, ArrayList<Node> toAddTo) {
				this.par=par;
				this.size=1;
				for (Node nn:adj) {
					if (nn==par) continue;
					nn.dfs(this, toAddTo);
					size+=nn.size;
				}
				toAddTo.add(this);
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
			int nextInt() {
				return Integer.parseInt(next());
			}
		}
	
	}