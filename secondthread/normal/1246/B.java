import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;
/*
6 3
1 3 9 8 24 1

 */
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int k=fs.nextInt();
		int[] factorOf=new int[100001];
		for (int p=2; p<factorOf.length; p++) {
			if (factorOf[p]!=0) continue;
			for (int j=p; j<factorOf.length; j+=p)
				if (factorOf[j]==0) factorOf[j]=p;
		}
		HashMap<HarmeyerHash, Integer> map=new HashMap<>();
		int[] a=new int[n];
		for (int i=0; i<n; i++) a[i]=fs.nextInt();
		long total=0;
		for (int i:a) {
			ArrayList<Integer> bases=new ArrayList<>(), exp=new ArrayList<>();
//			System.out.println("Processing "+i);
			while (i!=1) {
				int fact=factorOf[i];
				int times=0;
				while (i%fact==0) {
					i/=fact;
					times++;
				}
				bases.add(fact);
				exp.add(times);
			}
			HarmeyerHash seen=new HarmeyerHash(), needs=new HarmeyerHash();
			for (int j=0; j<bases.size(); j++) {
				for (int kk=0; kk<exp.get(j)%k; kk++) {
//					System.out.println("Adding to seen "+bases.get(j));
					seen.add(bases.get(j));
				}
				for (int kk=0; kk<(k-(exp.get(j)%k))%k; kk++) {
//					System.out.println("Adding to needs "+bases.get(j));
					needs.add(bases.get(j));
				}
			}
			total+=map.getOrDefault(needs, 0);
			map.put(seen, map.getOrDefault(seen, 0)+1);
		}
		System.out.println(total);
	}
	
	static class HarmeyerHash implements Comparable<HarmeyerHash> {
		static final long m1=8675309, m2=1_000_000_007;
		private long v1=0, v2=0;
		static final long s1=257, s2=619;
		static long[] s1Pow, s2Pow;
		
		public void add(int o) {
			v1=(v1*s1+o)%m1;
			v2=(v2*s2+o)%m2;
		}
		
		public int compareTo(HarmeyerHash o) {
			if (v1!=o.v1)
				return Long.compare(v1, o.v1);
				return Long.compare(v2, o.v2);
		}
		
		public int hashCode() {
			return (int) (v1^(v2*1753));
		}
		
		public boolean equals(Object o) {
			return compareTo((HarmeyerHash)o)==0;
		}
		
		static long fastPow(long val, long pow, long mod) {
			if (pow==0)
				return 1;
			long half=fastPow(val, pow/2, mod);
			if (pow%2==0)
				return half*half%mod;
			return half*half%mod*val%mod;
		}
		
		
		public HarmeyerHash clone() {
			HarmeyerHash toReturn=new HarmeyerHash();
			toReturn.v1=v1;
			toReturn.v2=v2;
			return toReturn;
		}
		
		public static HarmeyerHash[] getPrefixHashes(char[] word) {
			int n=word.length;
			s1Pow=new long[n+10];
			s2Pow=new long[n+10];
			s1Pow[0]=s2Pow[0]=1;
			for (int i=1; i<s1Pow.length; i++)
				s1Pow[i]=(s1Pow[i-1]*s1)%m1;
			for (int i=1; i<s2Pow.length; i++)
				s2Pow[i]=(s2Pow[i-1]*s2)%m2;
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
	}
	
}