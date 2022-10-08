import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
/*
 */
public class B {

	static long[] xCoords, yCoords;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		char[] string=fs.next().toCharArray();
		int nQueries=fs.nextInt();
		int n=string.length;
		int[][] cs=new int[n+1][26];
		for (int i=1; i<=n; i++) {
			for (int x=0; x<26; x++) {
				cs[i][x]=cs[i-1][x]+(string[i-1]-'a' == x?1:0);
			}
		}
		
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQueries; qq++) {
			int l=fs.nextInt()-1, r=fs.nextInt()-1;
			if (l==r) {
				out.println("Yes");
			}
			else if (string[l]!=string[r]) {
				out.println("Yes");
			}
			else {
				//otherwise we need at least three different letters
				int nonzeroCount=0;
				for (int x=0; x<26; x++) {
					if (cs[r+1][x]-cs[l][x]>0) nonzeroCount++;
				}
				if (nonzeroCount>=3) {
					out.println("Yes");
				}
				else {
					out.println("No");
				}
			}
		}
		out.close();
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
		
		String next() {
			while (!st.hasMoreElements())
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
		long nextLong() {
			return Long.parseLong(next());
		}
	}

}