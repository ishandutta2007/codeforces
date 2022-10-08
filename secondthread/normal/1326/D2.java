import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
1
abcdfdcecba

1
codeforces

1
ababacaba
1
sasdfdsababasdfdss

1
abac
 */
public class D2 {

	static HarmeyerHash[] prefixes, suffixes;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			char[] a=fs.next().toCharArray();
			int n=a.length;
			prefixes=HarmeyerHash.getPrefixHashes(a);
			char[] rev=new char[n];
			for (int i=0; i<n; i++) rev[i]=a[n-1-i];
			suffixes=HarmeyerHash.getPrefixHashes(rev);
			
			if (isPal(n, 0, n)) {
				out.println(a);
			}
			else {
				for (int i=0; i<n; i++) {
					if (a[i]!=a[n-1-i]) {
						int frontRemove=removeCountFront(i, n);
						int backRemove=removeBackFront(n-i-1, n);
//						System.out.println("Broke at "+i+" "+frontRemove+" "+backRemove);
						ArrayList<Character> ans=new ArrayList<>();
						if (frontRemove<=backRemove) {
							for (int j=0; j<n; j++) {
								if (j<i || j>=i+frontRemove) ans.add(a[j]);
							}
						}
						else {
							for (int j=0; j<n; j++) {
								if (j>n-1-i|| j<=n-1-i-backRemove) ans.add(a[j]);
							}
						}
						for (char c:ans) out.print(c);
						out.println();
						break;
					}
				}
			}
		}
		out.close();
	}
	
	static int removeCountFront(int firstIssue, int n) {
		int farIndex=firstIssue;
		while (!isPal(firstIssue, n-farIndex, n)) {
			farIndex++;
		}
		return farIndex-firstIssue;
	}
	static int removeBackFront(int lastIssue, int n) {
		int frontIndex=lastIssue;
		while (!isPal(frontIndex+1, n-1-lastIssue, n)) {
			frontIndex--;
		}
		return lastIssue-frontIndex;
	}
	
	static boolean isPal(int preLen, int postLen, int n) {
//		System.out.println("Trying isPal "+preLen+" "+postLen);
		return get(preLen, postLen, prefixes, n).compareTo(get(postLen, preLen, suffixes, n))==0;
	}
	
	static HarmeyerHash get(int preLen, int postLen, HarmeyerHash[] p, int n) {
		HarmeyerHash ret=HarmeyerHash.substringHash(p, 0, preLen);
		ret.append(HarmeyerHash.substringHash(p, n-postLen, n));
		return ret;
	}
	
	static class HarmeyerHash implements Comparable<HarmeyerHash> {
		static final long m1=8675309, m2=1_000_000_007;
		long v1=0, v2=0; int l=0;	
		static final long s1=257, s2=619;
		static long[] s1Pow, s2Pow;
		static boolean precomped=false;
		
		void add(char o) {
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
			s1Pow=new long[1000_002];
			s2Pow=new long[1000_002];
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
		
		String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		boolean hasNext() {
			String next=null;
			try {
				next = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (next==null) {
				return false;
			}
			st=new StringTokenizer(next);
			return true;
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}

}