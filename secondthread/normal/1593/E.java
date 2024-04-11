import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

import com.sun.accessibility.internal.resources.accessibility;

/*
1
6 2
1 2
2 3
3 4
2 5
5 6
//answer is 1

 */
public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int k=fs.nextInt();
			k=Math.min(k, n+1);
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node();
			for (int i=1; i<n; i++) {
				int a=fs.nextInt()-1;
				int b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].adj.add(nodes[a]);
			}
			ArrayDeque<Node> bfs=new ArrayDeque<>();
			for (Node nn:nodes) {
				if (nn.adj.size()<2) {
					bfs.addLast(nn);
					nn.dist=0;
				}
			}
			while (!bfs.isEmpty()) {
				Node nn=bfs.removeFirst();
				for (Node a:nn.adj) {
					if (a.dist!=-1) continue;
					a.usedDegree++;
					if (a.adj.size()-a.usedDegree <=1) {
						//then it has at most one edge left
						a.dist=nn.dist+1;
						bfs.addLast(a);
					}
				}
			}
			
			int[] cs=new int[n+1];
			for (Node nn:nodes) {
				cs[nn.dist]++;
			}
			for (int i=1; i<cs.length; i++) cs[i]+=cs[i-1];
//			System.out.println(Arrays.toString(cs));
			System.out.println(n-cs[k-1]);
			
		}
	}

	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int dist=-1;
		int usedDegree=0;
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