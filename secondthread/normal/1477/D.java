import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

/*
1
2 1
1 2

1
4 2
1 2
3 4

1
6 4
1 2
1 3
3 5
3 6
 */
public class DFixed {

	static HashSet<Long> edges=new HashSet<>();
	
	public static void main(String[] args) throws InterruptedException {
		Thread t=new Thread(null, null, "T", 1<<28) {
			public void run() {
				SOLVE();
			}
		};
		t.start();
		t.join();
	}
	
	public static void SOLVE() {
		FastScanner fs=new FastScanner();
		
		PrintWriter out=new PrintWriter(System.out);
		//TODO: STACK TRICK!
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			edges.clear();
			int n=fs.nextInt(), m=fs.nextInt();
			for (int i=0; i<m; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				edges.add(toL(a, b));
				edges.add(toL(b, a));
			}

			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node(i+1);
			
			//Make max spanning forest on inverse of graph
			TreeSet<Integer> excluded=new TreeSet<>();
			for (int i=0; i<n; i++) excluded.add(i);
			ArrayList<Node> roots=new ArrayList<>();
			for (int root=0; root<n; root++) {
				if (!excluded.contains(root)) continue;
				roots.add(nodes[root]);
				ArrayDeque<Integer> bfs=new ArrayDeque<>();
				bfs.add(root);
				excluded.remove(root);
				while (!bfs.isEmpty()) {
					int next=bfs.remove();
					ArrayList<Integer> toReach=new ArrayList<>();
					for (int i:excluded) {
						if (!edges.contains(toL(next, i))) {
							//then we can reach on the antigraph
							toReach.add(i);
						}
					}
					for (int i:toReach) {
						excluded.remove(i);
						bfs.add(i);
						nodes[next].adj.add(nodes[i]);
					}
				}
			}
			
			
			//run greedy on max spanning forest
			ArrayList<ArrayList<Node>> groups=new ArrayList<>();
			for (Node root:roots) {
				root.go(groups, true);
			}
			
			int[] perm1=new int[n], perm2=new int[n];
			int id=0;
			for (ArrayList<Node> group:groups) {
				int size=group.size();
				for (int i=0; i<size; i++) perm1[i+id]=group.get(i).id-1;
				for (int i=0; i<size; i++) perm2[(i+1)%size+id]=group.get(i).id-1;
				id+=size;
			}
			perm1=indexOf(perm1);
			perm2=indexOf(perm2);
			for (int i=0; i<n; i++) {
				out.print(perm1[i]+" ");
			}
			out.println();
			for (int i=0; i<n; i++) {
				out.print(perm2[i]+" ");
			}
			out.println();
		}
		out.close();
	}
	
	static int[] indexOf(int[] a) {
		int[] toRet=new int[a.length];
		for (int i=0; i<a.length; i++) {
			toRet[a[i]]=i+1;
		}
		return toRet;
	}
	
	static long toL(int a, int b) {
		return a*1_000_000_000l+b;
	}
	
	
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		ArrayList<Node> myGroup=null; // root is at the end of a group
		int id;
		public Node(int id) {
			this.id=id;
		}
		
		public void go(ArrayList<ArrayList<Node>> groups, boolean root) {
			if (root && adj.size()==0) {
				//then I have to be alone
				myGroup=new ArrayList<>();
				myGroup.add(this);
				groups.add(myGroup);
				return;
			}
			
			//otherwise I will get matched
			//if I am not the root, my parent will take care of me
			//if I am the root and have >= 1 unmatched kid, then take care of him
			//otherwise, add myself to my kid's group (no unmatched kids, is root)
			
			ArrayList<Node> unmatchedKids=new ArrayList<>();
			for (Node n:adj) {
				n.go(groups, false);
				if (n.myGroup==null) unmatchedKids.add(n);
			}
			
			if (unmatchedKids.isEmpty()) {
				if (root) {
					adj.get(0).myGroup.add(0, this);
				}
				else {
					//parent will take care of me
				}
			}
			else {
				myGroup=unmatchedKids;
				myGroup.add(this);
				groups.add(myGroup);
			}
		}
		
		public String toString() {
			return id+"";
		}
	}

	static void ruffleSort(int[] a) {
		int n=a.length;
		Random r=new Random();
		for (int i=0; i<a.length; i++) {
			int oi=r.nextInt(n), temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
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