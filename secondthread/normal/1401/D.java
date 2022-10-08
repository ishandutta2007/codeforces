import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
/*
1
6
1 2
2 3
2 4
4 6
4 5
6
2 3 5 7 11 13
 */
public class D {

	static long mod=(long)1e9+7;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node();
			for (int i=1; i<n; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].adj.add(nodes[a]);
			}
			int nPrimes=fs.nextInt();
			int[] factors=fs.readArray(nPrimes);
			ruffleSort(factors);
			
			n--;
			long[] values=new long[n];
			Arrays.fill(values, 1);
			//combine last
			for (int i=nPrimes-1; i>=0; i--) {
				int index=Math.max(0, n-i-1);
				values[index]=mul(values[index], factors[i]);
			}
			
			long[] edgeWeights=new long[n];
			nodes[0].dfs(null);
			for (int i=1; i<=n; i++) {
				long times=nodes[i].subtreeSize*(long)(n+1-nodes[i].subtreeSize);
				edgeWeights[i-1]=times;
			}
			ruffleSort(edgeWeights);
			ruffleSort(values);
			
			long ans=0;
			for (int i=0; i<n; i++) {
//				System.out.println("Matching edgeWeight "+edgeWeights[i]+" with values: "+values[i]);
				ans=(ans+mul(edgeWeights[i], values[i]))%mod;
			}
			System.out.println(ans);
		}
	}
	
	static long mul(long a, long b) {
		return a*b%mod;
	}
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int subtreeSize;
		
		public void dfs(Node par) {
			this.subtreeSize=1;
			for (Node nn:adj) if (nn!=par) {
				nn.dfs(this);
				this.subtreeSize+=nn.subtreeSize;
			}
		}
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	
	static void ruffleSort(long[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n);
			long temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
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
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}