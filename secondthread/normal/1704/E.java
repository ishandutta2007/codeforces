import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

import javax.xml.stream.events.EndDocument;
/*

Operations:

Gift: start, size
Add two gifts together:
	start=min(a.start, b.start)
	size=a.size+b.size;

Add two numbers
starts will always be small

We only need to compare things if they are < n (>n => they will overlap)


1
3 2
1 1 1
1 2
2 3
	
	
1
10 11
998244353 0 0 0 998244353 0 0 0 0 0
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
1 3
7 9
 */
public class E2 {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
//		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), m=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node(fs.nextInt());
			for (int i=0; i<m; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].indegree++;
			}
			ArrayDeque<Node> bfs=new ArrayDeque<>();
			for (Node nn:nodes) {
				if (nn.indegree==0) bfs.add(nn);
			}
			ArrayList<Node> topSorted=new ArrayList<>();
			while (!bfs.isEmpty()) {
				Node now=bfs.removeFirst();
				topSorted.add(now);
				for (Node nn:now.adj) {
					nn.indegree--;
					if (nn.indegree==0) {
						bfs.addLast(nn);
					}
				}
			}
			
			for (Node nn:topSorted) {
				nn.compressGifts();
				for (Node to:nn.adj) {
					nn.tryGiveTo(to);
				}
			}
			
//			for (Node nn:topSorted) {
//				System.out.println(nn.gifts);
//			}
			long ans=0;
			Node last=topSorted.get(topSorted.size()-1);
			if (!last.gifts.isEmpty()) {
				last.compressGifts();
				Gift lastG=last.gifts.get(last.gifts.size()-1);
				ans=(lastG.startTime+lastG.amount)%mod;
			}
			out.println(ans);
		}
		out.close();
	}
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int indegree=0;
		int startAmount;
		ArrayList<Gift> gifts=new ArrayList<>();
		public Node(int startAmount) {
			this.startAmount=startAmount;
			if (startAmount!=0) {
				gifts.add(new Gift(startAmount, 0));
			}
		}
		
		//assume o is an outEdge, give all gifts
		void tryGiveTo(Node o) {
			for (Gift g:gifts) {
				o.gifts.add(new Gift(g.amount, g.startTime+1));
			}
		}
		
		void compressGifts() {
			if (gifts.isEmpty()) return;
			Collections.sort(gifts);
			ArrayList<Gift> real=new ArrayList<>(gifts.size());
			Gift last=gifts.get(0);
			for (int i=1; i<gifts.size(); i++) {
				Gift next=gifts.get(i);
				if (last.intersect(next)) {
					last.addSize(next.amount);
				}
				else {
					real.add(last);
					last=next;
				}
			}
			real.add(last);
			gifts=real;
		}
	}
	
	// TODO: have to be really careful about how things overlapping the mod intersect.
	static class Gift implements Comparable<Gift> {
		long amount; // <mod => real value
					//mod..2*mod-1 => compressed
		int startTime;
		public Gift(long amount, int startTime) {
			this.amount=amount;
			this.startTime=startTime;
		}
		boolean intersect(Gift o) {
			long myEnd=startTime+amount, hisEnd=o.startTime+o.amount;
			return !(myEnd<o.startTime || hisEnd<startTime);
		}
		public int compareTo(Gift o) {
			return Integer.compare(startTime, o.startTime);
		}
		void addSize(long toAdd) {
			amount+=toAdd;
			if (amount>=mod) {
				amount=amount%mod+mod;
			}
		}
		public String toString() {
			return "{start: "+startTime+", amount: "+amount+"}";
		}
	}
	
	static final Random random=new Random();
	static final int mod=998244353;
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	static long mul(long a, long b) {
		return (a*b)%mod;
	}
	static long exp(long base, long exp) {
		if (exp==0) return 1;
		long half=exp(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	static long[] factorials=new long[2_000_001];
	static long[] invFactorials=new long[2_000_001];
	static void precompFacts() {
		factorials[0]=invFactorials[0]=1;
		for (int i=1; i<factorials.length; i++) factorials[i]=mul(factorials[i-1], i);
		invFactorials[factorials.length-1]=exp(factorials[factorials.length-1], mod-2);
		for (int i=invFactorials.length-2; i>=0; i--)
			invFactorials[i]=mul(invFactorials[i+1], i+1);
	}
	
	static long nCk(int n, int k) {
		return mul(factorials[n], mul(invFactorials[k], invFactorials[n-k]));
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
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