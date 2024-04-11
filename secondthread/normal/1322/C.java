import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), m=fs.nextInt();
			RightNode[] right=new RightNode[n];
			for (int i=0; i<n; i++) right[i]=new RightNode(fs.nextLong());
			for (int i=0; i<m; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				right[b].leftReachable.add(a);
			}
			HashMap<HarmeyerHash, Long> map=new HashMap<>();
			for (RightNode nn:right) {
				if (nn.leftReachable.isEmpty()) continue;
				Collections.sort(nn.leftReachable);
				HarmeyerHash res=nn.getHash();
				map.put(res, map.getOrDefault(res, 0l)+nn.value);
			}
			
			long gcd=0;
			for (Map.Entry<HarmeyerHash, Long> e:map.entrySet()) {
				gcd=gcd(gcd, e.getValue());
			}
			out.println(gcd);
		}
		out.close();
		
	}
	
	static long gcd(long a, long b) {
		if (b==0) return a;
		return gcd(b, a%b);
	}
	
	static class RightNode {
		long value;
		ArrayList<Integer> leftReachable=new ArrayList<>();
		public RightNode(long value) {
			this.value=value;
		}
		
		HarmeyerHash getHash() {
			HarmeyerHash res=new HarmeyerHash();
			for (int i:leftReachable)
				res.add(i);
			return res;
		}
	}
	
	static class HarmeyerHash implements Comparable<HarmeyerHash> {
		static final long m1=8675309, m2=1_000_000_007;
		long v1=0, v2=0; int l=0;	
		static final long s1=257, s2=619;
		static long[] s1Pow, s2Pow;
		static boolean precomped=false;
		
		void add(int o) {
			o++;
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



	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
}//