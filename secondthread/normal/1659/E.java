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
Can the length even be 4?
00
01
10
11

each new number is a submask of the last
So you can't have both 1 and 2

So the answer to a query is 0, 1, or 2, but never 3

Q1: Can we go from a->b with every edge having some bit?
 -> answer will be 0
 
A: use 30 DJS
 
Q2: Can we get from a->b by losing the 1 bit <= losing the last other bit

Q2 Easy: Can we get to some edge which doesn't have a 1 bit 
without losing all other bits?

Every edge without a 1 bit goes to a special node -> finish
Q: Can we reach the finish from a?



 */
public class E {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
//		int T=fs.nextInt();
		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int m=fs.nextInt();
			Edge[] edges=new Edge[m];
			for (int i=0; i<m; i++) 
				edges[i]=new Edge(fs.nextInt()-1, fs.nextInt()-1, fs.nextInt());
			DJS[] usingBit=new DJS[30];
			DJS[] usingBitToSpecial=new DJS[30];
			for (int i=0; i<30; i++) {
				usingBit[i]=new DJS(n);
				usingBitToSpecial[i]=new DJS(n+1);
			}
			for (Edge e:edges) {
				for (int bit=0; bit<30; bit++) {
					if ((e.c&(1<<bit))==0) continue;
					usingBit[bit].union(e.a, e.b);
				}
				for (int bit=0; bit<30; bit++) {
					if ((e.c & 1)==0) {
						usingBitToSpecial[bit].union(e.a, n);
						usingBitToSpecial[bit].union(e.b, n);
					}
					if ((e.c&(1<<bit))==0) continue;
					usingBitToSpecial[bit].union(e.a, e.b);
				}
			}
			int nq=fs.nextInt();
			outer: for (int qq=0; qq<nq; qq++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				for (int bit=0; bit<30; bit++) {
					if (usingBit[bit].find(a)==usingBit[bit].find(b)) {
						out.println(0);
						continue outer;
					}
				}
				for (int bit=1; bit<30; bit++) {
					if (usingBitToSpecial[bit].find(a)==usingBitToSpecial[bit].find(n)) {
						out.println(1);
						continue outer;
					}
				}
				
				out.println(2);
			}
		}
		out.close();
	}
	
	static class Edge {
		int a, b, c;
		public Edge(int a, int b, int c) {
			this.a=a;
			this.b=b;
			this.c=c;
		}
	}
	
	static class DJS {
		int[] s;
		
		public DJS(int n) {
			Arrays.fill(s = new int[n], -1);
		}
		
		public int find(int i) {
			return s[i] < 0 ? i : (s[i] = find(s[i]));
		}
		
		public boolean union(int a, int b) {
			if ((a = find(a)) == (b = find(b))) return false;
			if(s[a] == s[b]) s[a]--;
			if(s[a] <= s[b]) s[b] = a; 
			else s[a] = b;
			return true;
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