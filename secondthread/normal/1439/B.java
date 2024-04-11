import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B {


	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		testcase: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), m=fs.nextInt(), k=fs.nextInt();
			ArrayList<Integer>[] adj=new ArrayList[n];
			for (int i=0; i<n; i++) adj[i]=new ArrayList<>();
			ArrayDeque<Integer> toRemove=new ArrayDeque<>();
			ArrayList<CliqueCand> possibleCliques=new ArrayList<>();
			int[] degree=new int[n];
			for (int i=0; i<m; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				degree[a]++; degree[b]++;
				adj[a].add(b);
				adj[b].add(a);
			}
			PriorityQueue<State> pq=new PriorityQueue<>();
			for (int i=0; i<n; i++) pq.add(new State(i, degree[i]));
			boolean[] removed=new boolean[n];
			while (!pq.isEmpty()) {
				State nextState=pq.remove();
				if (nextState.degree!=degree[nextState.node]) continue;
				if (nextState.degree>=k) {
					//then all the nodes that haven't been deleted are an answer
					ArrayList<Integer> ans=new ArrayList<>();
					for (int i=0; i<n; i++) if (!removed[i]) ans.add(i);
					out.println(1+" "+ans.size());
					for (int i:ans) out.print(i+1+" ");
					out.println();
					continue testcase;
				}
				else {
					//if the degree is exactly k-1, we need to check this clique
					if (nextState.degree==k-1) {
						CliqueCand cand=new CliqueCand();
						int[] elements=new int[k];
						cand.elements=elements;
						int elementsCount=1;
						elements[0]=nextState.node;
						for (int other:adj[nextState.node])
							if (!removed[other]) elements[elementsCount++]=other;
						possibleCliques.add(cand);
					}
					//either way, remove it
					removed[nextState.node]=true;
					for (int other:adj[nextState.node]) {
						if (removed[other]) continue;
						degree[other]--;
						pq.add(new State(other, degree[other]));
					}
				}
			}
			
			if (k*(long)(k-1) <= m*2) {
				// still need to check all of the candidate cliques
				ArrayList<CliqueCand>[] candsTouchingNode=new ArrayList[n];
				ArrayList<CliqueCand> allCands=new ArrayList<>();
				for (int i=0; i<n; i++) candsTouchingNode[i]=new ArrayList<>();
				for (CliqueCand c:possibleCliques) {
					for (int i:c.elements) candsTouchingNode[i].add(c);
					allCands.add(c);
				}
				
				int[] count=new int[n];
				for (int base=0; base<n; base++) {
					for (int i:adj[base]) count[i]++;
					// process all edge pairs including base now...
					for (CliqueCand c:candsTouchingNode[base])
						for (int i:c.elements)
							c.totalEdges+=count[i];
					
					for (int i:adj[base]) count[i]--;
				}
				// check all candidate cliques to see if any are full
				for (CliqueCand c:allCands) {
					if (c.totalEdges==(long)(k)*(k-1)) {
						out.println("2");
						for (int i:c.elements) {
							out.print(i+1+" ");
						}
						out.println();
						continue testcase;
					}
				}
			}
			out.println(-1);
		}
		out.close();//
	}
	
	static class CliqueCand {
		int totalEdges=0;
		int[] elements;
		
	}
	
	static class State implements Comparable<State> {
		int node;
		int degree;
		public State(int node, int degree) {
			this.node=node;
			this.degree=degree;
		}
		public int compareTo(State o) {
			return Integer.compare(degree, o.degree);
		}
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
//