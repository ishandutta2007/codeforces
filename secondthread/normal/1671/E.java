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

 */
public class E {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
//		int T=fs.nextInt();
		int T=1;
		for (int tt=0; tt<T; tt++) {
			int height=fs.nextInt()-1;
			char[] a=fs.next().toCharArray();
			Node root=new Node(1, height, a);
			root.dfs();
			System.out.println(sub(root.ways, 0));
		}
	}
	
	static class Node implements Comparable<Node> {
		int val;
		long ways;
		int id;
		HarmeyerHash hash;
		Node[] kids;
		
		public Node(int index, int height, char[] a) {
			id=index;
			val=(a[index-1]=='A')?0:1;
			if (height==0) {
				return;
			}
			kids=new Node[2];
			kids[0]=new Node(index*2, height-1, a);
			kids[1]=new Node(index*2+1, height-1, a);
		}
		void dfs() {
			if (kids==null) {
				ways=1;
				hash=new HarmeyerHash();
				hash.add(val+1);
//				System.out.println("At node "+id+" "+hash.v1+" "+ways);
				return;
			}
			for (Node nn:kids) nn.dfs();
			Arrays.sort(kids);
			hash=new HarmeyerHash();
			hash.add(val+1);
			hash.append(kids[0].hash);
			hash.append(kids[1].hash);
			ways=mul(kids[0].ways, kids[1].ways);
			if (kids[0].compareTo(kids[1])!=0) {
				ways=mul(ways, 2);
			}
		}
		public int compareTo(Node o) {
			return hash.compareTo(o.hash);
		}
	}
	
	static class HarmeyerHash implements Comparable<HarmeyerHash> {
		static final long m1=8675309, m2=1_000_000_009;
		long v1=0, v2=0; int l=0;	
		static final long s1=257, s2=619;
		static long[] s1Pow, s2Pow;
		static boolean precomped=false;
		
		void add(int o) {
			v1=(v1*s1+o)%m1;
			v2=(v2*s2+o)%m2;
			l++;
		}
		
		public int compareTo(HarmeyerHash o) {
			if (v1!=o.v1)
				return Long.compare(v1, o.v1);
				return Long.compare(v2, o.v2);
		}
		
		public boolean equals(Object o) {
			return compareTo((HarmeyerHash)o)==0;
		}

		public int hashCode() {
			return (int)v1;
		}
		
		public HarmeyerHash clone() {
			HarmeyerHash toReturn=new HarmeyerHash();
			toReturn.v1=v1;
			toReturn.v2=v2;
			toReturn.l=l;
			return toReturn;
		}

		static void precomp() {
			if (precomped) return;
			precomped=true;
			s1Pow=new long[1000_000];
			s2Pow=new long[1000_000];
			s1Pow[0]=s2Pow[0]=1;
			for (int i=1; i<s1Pow.length; i++)
				s1Pow[i]=(s1Pow[i-1]*s1)%m1;
			for (int i=1; i<s2Pow.length; i++)
				s2Pow[i]=(s2Pow[i-1]*s2)%m2;
		}

		//need fastPow if o can be longer than 10^6
		void append(HarmeyerHash o) {
			precomp();
			v1=(v1*s1Pow[o.l]+o.v1)%m1;
			v2=(v2*s2Pow[o.l]+o.v2)%m2;
			l+=o.l;
		}
		
		public static HarmeyerHash[] getPrefixHashes(char[] word) {
			precomp();
			int n=word.length;
			HarmeyerHash[] toReturn=new HarmeyerHash[n+1];
			toReturn[0]=new HarmeyerHash();
			for (int i=1; i<=n; i++) {
				toReturn[i]=toReturn[i-1].clone();
				toReturn[i].add(word[i-1]);
			}
			return toReturn;
		}
		
		//inclusive, exclusive
		public static HarmeyerHash substringHash(HarmeyerHash[] prefixHashes, int from, int to) {
			if (from==to)
				return new HarmeyerHash();
			HarmeyerHash old=prefixHashes[to].clone(), toSub=prefixHashes[from];
			int diff=to-from;
			old.v1=(old.v1-(toSub.v1*s1Pow[diff])%m1+m1)%m1;
			old.v2=(old.v2-(toSub.v2*s2Pow[diff])%m2+m2)%m2;
			old.l=to-from;
			return old;
		}
	}
	
	static final Random random=new Random();
	static final int mod=998244353;
	
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