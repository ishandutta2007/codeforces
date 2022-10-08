import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

public class B {

	static boolean[][][][] illegal;
	static boolean[][] cantPick;
	static int ans=0;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt(), maxOut=fs.nextInt();
		ArrayList<Edge>[] outgoing=new ArrayList[n], incoming=new ArrayList[n];
		for (int i=0; i<n; i++) {
			outgoing[i]=new ArrayList<>();
			incoming[i]=new ArrayList<>();
		}
		Edge[] edges=new Edge[m];
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1, c=fs.nextInt();
			Edge e;
			edges[i]=e=new Edge(a, b, c);
			outgoing[a].add(e);
			incoming[b].add(e);
		}
		//illegal[a][b][c][d] means if we size a uses edge b, can size c use edge e?
		illegal=new boolean[maxOut][maxOut][maxOut][maxOut];
		cantPick=new boolean[maxOut][maxOut];
		for (int i=0; i<n; i++) {
			Collections.sort(outgoing[i]);
			for (int j=0; j<outgoing[i].size(); j++) {
				outgoing[i].get(j).fromSize=outgoing[i].size()-1;
				outgoing[i].get(j).positionInFrom=j;
			}
		}
		for (int goingInto=0; goingInto<n; goingInto++) {
			if (incoming[goingInto].size()==0) {
				System.out.println(0);
				return;
			}
			boolean[][] have=new boolean[maxOut][maxOut];
			for (Edge e:incoming[goingInto]) {
				if (have[e.fromSize][e.positionInFrom]) cantPick[e.fromSize][e.positionInFrom]=true;
				have[e.fromSize][e.positionInFrom]=true;
			}
			for (int a=0; a<maxOut; a++) {
				for (int b=0; b<maxOut; b++) {
					if (!have[a][b]) continue;
					for (int c=0; c<maxOut; c++)
						for (int d=0; d<maxOut; d++)
							if (have[c][d] && a!=c) {
//								System.out.println("From node "+goingInto+" illegal to have "+a+" "+b+" and "+c+" "+d);
								illegal[a][b][c][d]=true;
							}
				}
			}
		}
		allPerms(new int[maxOut], 0);
		System.out.println(ans);
	}
	
	static class Edge implements Comparable<Edge> {
		int from, to, val;
		int positionInFrom, fromSize;
		
		public Edge(int from, int to, int val) {
			this.from=from;
			this.to=to;
			this.val=val;
		}
		
		public int compareTo(Edge o) {
			return Integer.compare(val, o.val);
		}
	}

	
	static void allPerms(int[] a, int positionAt) {
		if (positionAt==a.length) {
			ans++;
//			System.out.println(Arrays.toString(a));
			return;
		}
		outer: for (int toPlace=0; toPlace<=positionAt; toPlace++) {
			if (cantPick[positionAt][toPlace]) continue;
			for (int prev=0; prev<positionAt; prev++) {
				if (illegal[positionAt][toPlace][prev][a[prev]]) {
//					System.out.println("At position: "+positionAt+" can't place "+toPlace+" because of "+prev+" index is "+a[prev]);
					continue outer;
				}
			}
			a[positionAt]=toPlace;
			allPerms(a, positionAt+1);
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