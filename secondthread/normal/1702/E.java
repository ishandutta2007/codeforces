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
/*
1
3
1 2
2 3
1 3
 */
public class E {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
//		int T=1;
		outer: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[][] input=new int[n][];
			for (int i=0; i<n; i++) input[i]=fs.readArray(2);
			ArrayList<Integer>[] withNum=new ArrayList[n];
			for (int i=0; i<n; i++) withNum[i]=new ArrayList<>();
			for (int i=0; i<n; i++)
				for (int j=0; j<2; j++)
					withNum[--input[i][j]].add(i);
			
			//if anyone has 3 => impossible
			for (ArrayList<Integer> list:withNum) {
				if (list.size()>=3) {
					out.println("NO");
					continue outer;
				}
			}
			
			ArrayList<Integer>[] adj=new ArrayList[n];
			for (int i=0; i<n; i++) adj[i]=new ArrayList<>();
			for (ArrayList<Integer> list:withNum) {
				for (int i=0; i<list.size(); i++) {
					for (int j=i+1; j<list.size(); j++) {
						adj[list.get(i)].add(list.get(j));
						adj[list.get(j)].add(list.get(i));
					}
				}
			}
			
			//check if bipartite
			boolean works=true;
			ArrayDeque<Integer> bfs=new ArrayDeque<>();
			boolean[] visited=new boolean[n];
			boolean[] color=new boolean[n];
			for (int i=0; i<n; i++) {
				if (visited[i]) continue;
//				System.out.println("Starting bfs at "+i);
				visited[i]=true;
				bfs.add(i);
				while (!bfs.isEmpty()) {
					int at=bfs.removeFirst();
//					System.out.println("  in "+at);
					for (int other:adj[at]) {
						if (!visited[other]) {
							visited[other]=true;
							color[other]=!color[at];
							bfs.add(other);
						}
						else if (color[other]==color[at]) {
							works=false;
						}
					}
				}
			}
			out.println(works?"YES":"NO");
		}
		out.close();
	}
	
	static final Random random=new Random();
	static final int mod=1_000_000_007;
	
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