import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/*
4 4 4
1 2
2 3
3 4
3 1
 */
public class D {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt(), m=fs.nextInt(), k=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(i);
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1,b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		
		if (m==n-1) {
			//TREE
			nodes[0].twoCol(0, null);
			ArrayList<Node>[] ofCol=new ArrayList[2];
			for (int i=0; i<2; i++) ofCol[i]=new ArrayList<>();
			for (Node nn:nodes) ofCol[nn.col].add(nn);
			out.println(1);
			ArrayList<Node> ans=ofCol[0].size()>=(k+1)/2?ofCol[0]:ofCol[1];
			for (int i=0; i<(k+1)/2; i++) 
				out.print(ans.get(i)+" ");
			out.println();
			out.close();
		}
		else {
			//FIND CYCLE
			nodes[0].dfs(null, new ArrayDeque<>());
			int cycleLen=cycle.size();
			for (int i=0; i<cycle.size(); i++) cycle.get(i).indexInCycle=i;
			
			int curBest=cycleLen;
			Node curStart=cycle.get(0), curEnd=cycle.get(cycleLen-1);
			for (Node a:cycle) {
				for (Node b:a.adj) {
					if (b.indexInCycle==-1) {
						continue;
					}
					Node first=a.indexInCycle<b.indexInCycle?a:b;
					Node second=a.indexInCycle<b.indexInCycle?b:a;
					int len1=second.indexInCycle-first.indexInCycle+1;
					if (len1!=2 && len1<curBest) {
						curBest=len1;
						curStart=first;
						curEnd=second;
					}
					int len2=cycleLen-second.indexInCycle+first.indexInCycle+1;
					if (len2!=2 && len2<curBest) {
						curBest=len2;
						curStart=second;
						curEnd=first;
					}
				}
			}
			
			ArrayList<Node> ans=new ArrayList<>();
			Node at=curStart;
			while (at!=curEnd) {
				ans.add(at);
				at=cycle.get((at.indexInCycle+1)%cycleLen);
			}
			ans.add(curEnd);
			
			if (ans.size()<=k) {
				out.println(2);
				out.println(ans.size());
				for (Node nn:ans)
					out.print(nn+" ");
				out.println();
			}
			else {
				out.println(1);
				for (int i=0; i<(k+1)/2; i++) {
					out.print(ans.get(i*2)+" ");
				}
				out.println();
			}
			out.close();
		}
	}
	
	static ArrayList<Node> cycle=new ArrayList<>();
	
	static class Node {
		int index;
		ArrayList<Node> adj=new ArrayList<>();
		int col=-1;
		boolean visited=false;
		int indexInCycle=-1;
		
		public Node(int index) {
			this.index=index;
		}
		public void twoCol(int col, Node par) {
			this.col=col;
			for (Node nn:adj) {
				if (nn==par) continue;
				nn.twoCol(col^1, this);
			}
		}
		//returns true if a cycle has been found
		public boolean dfs(Node par, ArrayDeque<Node> stk) {
			if (visited) {
				//pop off the stack until we get to me
				while (stk.peekLast()!=this) {
					cycle.add(stk.removeLast());
				}
				cycle.add(this);
				return true;
			}
			else {
				visited=true;
				stk.addLast(this);
				for (Node nn:adj) {
					if (nn==par) continue;
					if (nn.dfs(this, stk)) {
						return true;
					}
				}
				if (stk.removeLast() != this) throw null;
				return false;
			}
		}
		
		public String toString() {
			return ""+(index+1);
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