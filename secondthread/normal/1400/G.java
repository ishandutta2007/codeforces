import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class G {

	//dp[mask][subFromK] = multiple of (n choose k-subFromK) with
	//						the given edge mask
	static int[][] dp;
	static int oo=1_000_000_000;
	
	public static void main(String[] args) {
		precomp();
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int m=fs.nextInt();
		Node[] nodes=new Node[n];
		Edge[] edges=new Edge[m];
		for (int i=0; i<n; i++) 
			nodes[i]=new Node(fs.nextInt(), fs.nextInt(), i);
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			edges[i]=new Edge(nodes[a], nodes[b]);
		}
		dp=new int[1<<m][60];
		for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], oo);
		
		boolean[] hit=new boolean[n];
		ArrayList<Integer> specialNodes=new ArrayList<>();
		for (Edge e:edges) {
			specialNodes.add(e.from.index);
			specialNodes.add(e.to.index);
		}
		int[] nPeopleDelta=new int[n+2];
		for (Node nn:nodes) {
			nPeopleDelta[nn.l]++;
			nPeopleDelta[nn.r+1]--;
		}
		int nPeopleAlive=0;
		long ans=0;
		for (int nPeople=1; nPeople<=n; nPeople++) {
			nPeopleAlive+=nPeopleDelta[nPeople];
			int edgeMask=0;
			for (int i=0; i<m; i++) {
				if (edges[i].l<=nPeople && edges[i].r>=nPeople) 
					edgeMask+=1<<i;
			}
			if (dp[edgeMask][0]==oo) {
			
				int[] multipliers=new int[60];
				//TODO: actually calculate it
				for (int subMask=edgeMask; true; subMask=(subMask-1)&edgeMask) {
					//look at all submasks of edges
					boolean shouldSubtract=Integer.bitCount(subMask)%2==1;
					
					int nHit=0;
					for (int i=0; i<m; i++) {
						if ((subMask&(1<<i))!=0) {
							//include edge
							int person=edges[i].from.index;
							if (!hit[person]) {
								hit[person]=true;
								nHit++;
							}
							person=edges[i].to.index;
							if (!hit[person]) {
								hit[person]=true;
								nHit++;
							}
						}
					}
					multipliers[nHit]+=(shouldSubtract?-1:1);
					for (int i:specialNodes) hit[i]=false;
					
					if (subMask==0) break;
				}
				
				for (int i=0; i<dp[edgeMask].length; i++)
					dp[edgeMask][i]=multipliers[i];
			}
			
//			System.out.println("nPeopleAlive: "+nPeopleAlive+" nPeople: "+nPeople);
			//TODO: calculate and print answer
			if (nPeopleAlive<nPeople) continue;
			
			//otherwise we need to pick k=nPeople from n=nPeopleAlive
			long total=0;
			for (int toSub=0; toSub<dp[edgeMask].length; toSub++) {
				long nCk=nCk(nPeopleAlive-toSub, nPeople-toSub);
//				System.out.println("Considering toSub: "+toSub+" nCk: "+nCk+" dp: "+dp[edgeMask][toSub]);
				total=add(total, mul(dp[edgeMask][toSub], nCk));
			}
			ans=add(ans, total);
			
		}
		System.out.println(ans);
		
	}
	
	static long[] facts, invFacts;
	
	static void precomp() {
		facts=new long[500_000];
		invFacts=new long[500_000];
		facts[0]=1;
		for (int i=1; i<facts.length; i++) facts[i]=mul(i, facts[i-1]);
		for (int i=0; i<facts.length; i++) invFacts[i]=pow(facts[i], mod-2);
	}
	
	static long nCk(int n, int k) {
		if (k<0) return 0;
		if (k>n) return 0;
		if (n<0) return 0;
		return mul(facts[n], mul(invFacts[n-k], invFacts[k]));
	}
	
	static long mod=998244353;
	
	static long pow(long base, long e) {
		if (e==0) return 1;
		long half=pow(base, e/2);
		if (e%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	
	static long mul(long a, long b) {
		return a*b%mod;
	}
	
	static long add(long a, long b) {
		return ((a+b)%mod+mod)%mod;
	}
	
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	
	static class Edge {
		int l, r;
		Node to, from;
		public Edge(Node to, Node from) {
			this.to=to;
			this.from=from;
			l=Math.max(from.l, to.l);
			r=Math.min(from.r, to.r);
		}
	}
	
	static class Node {
		int l, r, index;
		public Node(int l, int r, int index) {
			this.l=l;
			this.r=r;
			this.index=index;
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