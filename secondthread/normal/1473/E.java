import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class E3 {
	
	static final int SIZE=1_300_000;
	
	static int[] stateNodes=new int[SIZE];
	static long[] stateCosts=new long[SIZE];
	static int stateId=0;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt(), m=fs.nextInt();
		Node[] nodes=new Node[n<<2];
		for (int i=0; i<n<<2; i++) nodes[i]=new Node();
		
		//4*n nodes, 18*m edges
		for (int i=0; i<m; i++) {
			int from=fs.nextInt()-1, to=fs.nextInt()-1;
			int baseCost=fs.nextInt();
			for (int copy=0; copy<nodes.length; copy+=n) {
				add(from+copy, to+copy, baseCost, nodes, true);
			}
			//usedMin, usedMax
			//00 01 10 11
			
			//take min here
			add(from+0*n, to+1*n, baseCost+baseCost, nodes, false);
			add(from+2*n, to+3*n, baseCost+baseCost, nodes, false);
			add(to+0*n, from+1*n, baseCost+baseCost, nodes, false);
			add(to+2*n, from+3*n, baseCost+baseCost, nodes, false);
			
			//take max here
			add(from+0*n, to+2*n, baseCost-baseCost, nodes, false);
			add(from+1*n, to+3*n, baseCost-baseCost, nodes, false);
			add(to+0*n, from+2*n, baseCost-baseCost, nodes, false);
			add(to+1*n, from+3*n, baseCost-baseCost, nodes, false);
			
			//take both here
			add(from+0*n, to+3*n, baseCost-baseCost+baseCost, nodes, false);
			add(to+0*n, from+3*n, baseCost-baseCost+baseCost, nodes, false);
		}
		
		PQ pq=new PQ();
		nodes[0].dist=0;
		stateCosts[stateId]=0;
		stateNodes[stateId]=0;
		pq.add(stateId++);
		
		while (!pq.isEmpty()) {
			int nextId=pq.remove(), next=stateNodes[nextId];
			long dist=stateCosts[nextId];
			Node at=nodes[next];
			if (dist!=at.dist) continue;
			for (int i=0; i<at.toList.size; i++) {
				long newCost=dist+at.costList.a[i];
				int to=at.toList.a[i];
				if (newCost<nodes[to].dist) {
					nodes[to].dist=newCost;
					stateNodes[stateId]=to;
					stateCosts[stateId]=newCost;
					pq.add(stateId++);
				}
			}
		}
		
		for (int i=1; i<n; i++)
			out.print(nodes[i+3*n].dist+" ");
		out.close();
	}
	
	static void add(int from, int to, int cost, Node[] nodes, boolean bidir) {
		nodes[from].toList.add(to);
		nodes[from].costList.add(cost);
		if (bidir) {
			nodes[to].toList.add(from);
			nodes[to].costList.add(cost);
		}
	}

	static class PQ {
		int[] a=new int[SIZE];
		int size=0;
		void add(int x) {
			a[++size]=x;
			int i=size;
			while (i>1) {
				if (stateCosts[a[i]]<stateCosts[a[i>>1]]) {
					int temp=a[i];
					a[i]=a[i>>1];
					a[i>>1]=temp;
				}
				i>>=1;
			}
		}
		
		boolean isEmpty() {
			return size==0;
		}
		
		int remove() {
			int ret=a[1];
			int i=1;
			a[1]=a[size--];
			while (i<<1<=size) {
				int l=i<<1, r=l+1;
				if (r>size) {
					if (stateCosts[a[l]]<stateCosts[a[i]]) {
						int temp=a[i];
						a[i]=a[l];
						a[l]=temp;
					}
					return ret;
				}
				int o=stateCosts[a[l]]<stateCosts[a[r]]?l:r;
				if (stateCosts[a[o]]>=stateCosts[a[i]]) {
					return ret;
				}
				int temp=a[i];
				a[i]=a[o];
				a[o]=temp;
				i=o;
			}
			return ret;
		}
	}
	
	static class Node {
		IntList toList=new IntList();
		IntList costList=new IntList();
		long dist=Long.MAX_VALUE;
	}
	
	static class IntList {
		int[] a=new int[17];
		int size=0;
		int get(int i) {
			return a[i];
		}
		void add(int x) {
			if (size==a.length) {
				int[] temp=new int[a.length<<1];
				for (int i=0; i<size; i++) temp[i]=a[i];
				a=temp;
			}
			a[size++]=x;
		}
		int size() {
			return size;
		}
	}
	
	static void ruffle_sort(int[] a) {
		//shandom_ruffle
		Random r=new Random();
		int n=a.length;
		for (int i=0; i<n; i++) {
			int oi=r.nextInt(n);
			int temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
		}
		
		//sort
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