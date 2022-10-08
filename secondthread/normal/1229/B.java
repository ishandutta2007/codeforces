import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
public class B {
	
	static final long mod=1_000_000_007;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) {
			nodes[i]=new Node(fs.nextLong(), i+1);
		}
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].children.add(nodes[b]);
			nodes[b].children.add(nodes[a]);
		}
		nodes[0].dfs(null, 0);
		for (int e=1; e<=20; e++) {
			for (Node nn:nodes) {
				if (nn.lift[e-1]!=null) {
					nn.lift[e]=nn.lift[e-1].lift[e-1];
					if (nn.lift[e]!=null) {
						nn.gcdLift[e]=gcd(nn.gcdLift[e-1], nn.lift[e-1].gcdLift[e-1]);
					}
				}
			}
		}
		
		long total=0;
		for (Node nn:nodes) {
//			System.out.println("Solving for index: "+nn.index);
			total+=nn.solve(nn.value, 20, 0);
			total%=mod;
		}
		System.out.println(total);
	}
	
	static long gcd(long a, long b) {
		if (b==0) return a;
		return gcd(b, a%b);
	}
	
	static class Node {
		long value;
		Node[] lift=new Node[21];
		long[] gcdLift=new long[21];
		int depth;
		int index;
		
		ArrayList<Node> children=new ArrayList<>();
		
		public Node(long value, int index) {
			this.value=value;
			this.index=index;
		}
		
		void dfs(Node par, int depth) {
			if (par!=null) children.remove(par);
			this.depth=depth;
			lift[0]=par;
			if (par!=null) gcdLift[0]=gcd(value, par.value);
			for (Node n:children) {
				n.dfs(this, depth+1);
			}
		}
		
		//should count yourself
		long solve(long gcd, int maxJump, int prevLength) {
			if (lift[0]==null) {
				return (gcd*(prevLength+1))%mod;
			}
			while (lift[maxJump]==null) maxJump--;
			while (maxJump>=0&&(gcd==0?gcdLift[maxJump]!=0:gcdLift[maxJump]%gcd!=0)) {
				maxJump--;
			}
//			System.out.println("For node: "+index+" jumping: "+maxJump+" "+gcdLift[0]+" gcd: "+gcd);
			if (maxJump==-1) {
				long newLength=prevLength+1;
				long toAdd=(newLength)*gcd;
//				System.out.println("\tAdding "+toAdd);
				return (toAdd+lift[0].solve(gcd(gcd, lift[0].value), 20, 0))%mod;
			}
			int newLength=(1<<maxJump)+prevLength;
			long ans=(lift[maxJump].solve(gcd, maxJump, newLength))%mod;
			return ans;
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
					// TODO Auto-generated catch block
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
	}
	
}