import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeSet;
/*

 */
public class DavidsClass {
	
	static HarmeyerHash[] prefixHashes;
	static int[] sizeAtIndex;
	static TreeSet<Integer> zeros;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		char[] line=fs.next().toCharArray();
		int[] a=new int[n];
		for (int i=0; i<n; i++) a[i]=line[i]-'0';
		ArrayList<Integer> compressed=new ArrayList<>();
		sizeAtIndex=new int[n];
		boolean oddOnes=false;
		n=0;
		for (int i:a) {
			if (i==0) {
				if (oddOnes) {
					compressed.add(1);
				}
				oddOnes=false;
				compressed.add(0);
			}
			else {
				oddOnes^=true;
			}
			sizeAtIndex[n++]=compressed.size();
		}
		
		prefixHashes=HarmeyerHash.getPrefixHashes(compressed);
		
		zeros=new TreeSet<>();
		for (int i=0;i<n; i++) if (a[i]==0) zeros.add(i);
		int nQueries=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQueries; qq++) {
			int l1=fs.nextInt()-1, l2=fs.nextInt()-1, length=fs.nextInt();
			int r1=l1+length-1;
			int r2=l2+length-1;
			HarmeyerHash h1=getHash(l1, r1), h2=getHash(l2, r2);
			if (h1.equals(h2)) {
				out.println("Yes");
			}
			else {
				out.println("No");
			}
		}
		out.close();
	}
	
	static HarmeyerHash getHash(int l, int r) {
		Integer firstZeroI=zeros.ceiling(l);
		if (firstZeroI==null || firstZeroI>r) {
			//all ones;
			return ((l-r+1)%2==0)?new HarmeyerHash():one();
		}
		int lastZero=zeros.floor(r);
		int startIndex=sizeAtIndex[firstZeroI]-1;
		int endIndex=sizeAtIndex[lastZero]-1;
		HarmeyerHash base=HarmeyerHash.substringHash(prefixHashes, startIndex, endIndex+1);
		if ((startIndex-l+1)%2!=0) {
			HarmeyerHash newBase=one();
			newBase.append(base);
			base=newBase;
		}
		if ((r-endIndex+1)%2!=0) {
			base.add(1);
		}
		return base;
	}
	
	static HarmeyerHash one() {
		HarmeyerHash toReturn=new HarmeyerHash();
		toReturn.add(1);
		return toReturn;
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
		
		public static HarmeyerHash[] getPrefixHashes(ArrayList<Integer> word) {
			precomp();
			int n=word.size();
			HarmeyerHash[] toReturn=new HarmeyerHash[n+1];
			toReturn[0]=new HarmeyerHash();
			for (int i=1; i<=n; i++) {
				toReturn[i]=toReturn[i-1].clone();
				toReturn[i].add(word.get(i-1));
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


}