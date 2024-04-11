import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;
/*
1
4 6
1 2
1 3
2 3
2 4
3 4
3 4
 */
public class E {

	//TODO: remove seed!
	static Random rand=new Random(5);
	static PrintWriter out=new PrintWriter(System.out);	
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), m=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<nodes.length; i++)
				nodes[i]=new Node(i+1);
			for (int i=0; i<m; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].in.add(nodes[a]);
			}
			while (solve(nodes));
		}
		out.close();
	}

	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		ArrayList<Node> in=new ArrayList<>();
		//0=red, 1=blue, 2=rr, 3=bb, 4=x
		int color;
		int index;
		public Node(int index) {
			this.index=index;
		}
	}
	
	public static boolean solve(Node[] nodes) {
		int n=nodes.length;
		for (int i=0; i<n; i++) {
			boolean[] hasIn=new boolean[5];
			for (Node nn:nodes[i].in) {
				hasIn[nn.color]=true;
			}
			if (hasIn[2] && hasIn[3]) {
				nodes[i].color=4;
			}
			else if (hasIn[2]) {//forced to be blue
				if (hasIn[1]) {
					nodes[i].color=3;
				}
				else {
					nodes[i].color=1;
				}
			}
			else if (hasIn[3]) {//forced to be red
				if (hasIn[0]) {
					nodes[i].color=2;
				}
				else {
					nodes[i].color=0;
				}
			}
			else {
				if (!hasIn[0]) {
					nodes[i].color=0;
				}
				else if (!hasIn[1]) {
					nodes[i].color=1;
				}
				else {
					nodes[i].color=rand.nextInt(2)+2;
				}
			}
		}
		
		ArrayList<Node> red=new ArrayList<>(), blue=new ArrayList<>();
		for (Node nn:nodes) {
			if (nn.color==0 || nn.color==2||nn.color==4) red.add(nn);
			if (nn.color==1 || nn.color==3||nn.color==4) blue.add(nn);
		}
		
//		for (Node nn:nodes) {
//			System.out.println(nn.index+" "+nn.color);
//		}
		if (red.size()*7<=nodes.length*4) {
			out.println(red.size());
			for (Node nn:red) out.print(nn.index+" ");
			out.println();
			return false;
		}
		if (blue.size()*7<=nodes.length*4) {
			out.println(blue.size());
			for (Node nn:blue) out.print(nn.index+" ");
			out.println();
			return false;
		}
		return true;
		
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