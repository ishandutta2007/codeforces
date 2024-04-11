import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

/*


For some node they go 1, 2, 3, 4, 5 ...
For some parent, each of those are incremented by x, merge small to big
Sort at the root

We have 2 kids, k to distribute, how do we split them?
Give each floor(k/2), then we have 1 for each at most

 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			ans=0;
			int n=fs.nextInt();
			int nPaths=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node();
			for (int i=1; i<n; i++) {
				int par=fs.nextInt()-1;
				nodes[par].children.add(nodes[i]);
			}
			int[] score=fs.readArray(n);
			for (int i=0; i<n; i++) {
				nodes[i].myVal+=score[i];
			}
			nodes[0].nPaths+=nPaths;
			nodes[0].push();
			out.println(ans);
		}
		out.close();
	}

	static long ans=0;

	static class Node {
		ArrayList<Node> children=new ArrayList<>();
		int nPaths=0;
		long myVal=0;

		//returns the next path's value
		long push() {
			ans+=nPaths*myVal;
			int nKids=children.size();
			if (nKids==0) {
				return myVal;
			}
			int toPush=nPaths/nKids;
			nPaths%=nKids;
			ArrayList<Long> res=new ArrayList<>();
			for (Node c:children) {
				c.nPaths+=toPush;
				res.add(c.push());
			}
			Collections.sort(res);
			for (int i=0; i<nPaths; i++) {
				ans+=res.get(res.size()-1-i);
			}
			return myVal+res.get(res.size()-1-nPaths);
		}
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