import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

//Good morning!
/*
1
6
1 2 2 3 4
32 78 69 5 41
 */
public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		//TODO: stack trick?
		outer: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) {
				nodes[i]=new Node(i+1);
			}
			for (int i=1; i<n; i++) {
				int par=fs.nextInt()-1;
				nodes[par].adj.add(nodes[i]);
			}
			for (int i=1; i<n; i++) {
				int label=fs.nextInt();
				nodes[i].label=label;
			}
			nodes[0].dfs(0);
			
			ArrayList<Node>[] nodesAt=new ArrayList[n];
			for (int i=0; i<n; i++) nodesAt[i]=new ArrayList<>();
			for (Node nn:nodes) nodesAt[nn.depth].add(nn);
			for (int depth=n-1; depth>0; depth--) {
				if (nodesAt[depth].isEmpty()) continue;
				for (Node nn:nodesAt[depth]) nn.getValue();
				ArrayList<Node> sorted1=(ArrayList<Node>) nodesAt[depth].clone(), sorted2=(ArrayList<Node>) nodesAt[depth].clone();
				ArrayList<Node> sorted3=(ArrayList<Node>) nodesAt[depth].clone(), sorted4=(ArrayList<Node>) nodesAt[depth].clone();
				Collections.sort(sorted1, (a, b) -> -Long.compare(a.value+a.label, b.value+b.label));
				Collections.sort(sorted2, (a, b) -> -Long.compare(a.value-a.label, b.value-b.label));
				Collections.sort(sorted3, (a, b) -> -Long.compare(a.label, b.label));
				Collections.sort(sorted4, (a, b) -> -Long.compare(-a.label, -b.label));
				ArrayList<Node> checkWith=new ArrayList<>();
//				checkWith=sorted1;
				checkWith.add(sorted1.get(0));
				checkWith.add(sorted2.get(0));
				checkWith.add(sorted3.get(0));
				checkWith.add(sorted4.get(0));
				if (sorted1.size()>1) {
					checkWith.add(sorted1.get(1));
					checkWith.add(sorted2.get(1));
					checkWith.add(sorted3.get(1));
					checkWith.add(sorted4.get(1));
				}
				for (Node first:nodesAt[depth]) {
					for (Node other:checkWith) {
						if (first==other) {
							first.valueForParent=Math.max(first.valueForParent, first.value);
						}
						first.valueForParent=Math.max(first.valueForParent, 
								Math.max(first.value, other.value)+
								Math.abs(first.label-other.label));
					}
				}
			}
			nodes[0].getValue();
			System.out.println(nodes[0].value);
		}
	}
	
	static class Node {
		long value;
		long valueForParent=0;
		int label, id;
		ArrayList<Node> adj=new ArrayList<>();
		int depth;
		
		public Node(int id) {
			this.id=id;
		}
		public void dfs(int depth) {
			this.depth=depth;
			for (Node nn:adj) {
				nn.dfs(depth+1);
			}
		}
		public void getValue() {
			for (Node nn:adj) {
				this.value=Math.max(value, nn.valueForParent);
			}
//			System.out.println("Got value for node "+id+" "+value);
		}
		
	}

	// Use this instead of Arrays.sort() on an array of ints. Arrays.sort() is n^2
	// worst case since it uses a version of quicksort. Although this would never
	// actually show up in the real world, in codeforces, people can hack, so
	// this is needed.
	static void ruffleSort(int[] a) {
		//ruffle
		int n=a.length;
		Random r=new Random();
		for (int i=0; i<a.length; i++) {
			int oi=r.nextInt(n), temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
		}
		
		//then sort
		Arrays.sort(a);
	}
	
	// Use this to input code since it is faster than a Scanner
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