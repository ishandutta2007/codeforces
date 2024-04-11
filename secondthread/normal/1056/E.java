import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringTokenizer;

public class E {
	
	static HarmeyerHash[] prefixHashes;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=1;//fs.nextInt();
		for (int tt=0; tt<T; tt++) {
		char[] wordA=fs.next().toCharArray(), target=fs.next().toCharArray();
		prefixHashes=HarmeyerHash.getPrefixHashes(target);
		if (wordA[0]=='1') {
			for (int i=0; i<wordA.length; i++)
				wordA[i]=wordA[i]=='0'?'1':'0';
		}
		int num0s=0, num1s=0, n=target.length;
		for (char c:wordA)
			if (c=='0')
				num0s++;
			else
				num1s++;
		int numLeadingZeros=0;
		for (int i=0; i<wordA.length; i++) {
			if (wordA[i]=='1') {
				numLeadingZeros=i;
				break;
			}
		}
		
		
		int timesWorked=0;
		for (int zeroLen=1; num0s*zeroLen+num1s<=n; zeroLen++) {
			if (verify(num0s, num1s, n, wordA, target, zeroLen, numLeadingZeros)) {
				timesWorked++;
			}
		}
		System.out.println(timesWorked);
		}
	}
	
	static boolean verify(int num0s, int num1s, int n, char[] wordA, char[] target, int zeroLen, int numLeadingZeros) {
		
		if(num0s*zeroLen>n) {
			return false;
		}
		
		if (num1s==0) {
			if (n!=zeroLen*num0s)
				return false;
			for (int i=0; i<n; i++) {
				if (target[i]!=target[i%zeroLen])
					return false;
			}
			return true;
		}
		if ((n-zeroLen*num0s)%num1s!=0)
			return false;
		int oneLen=(n-zeroLen*num0s)/num1s;
		if (oneLen<=0)
			return false;
		
		int pos=0;
		HarmeyerHash zeroHash=HarmeyerHash.substringHash(prefixHashes, 0, zeroLen);
		HarmeyerHash oneHash=HarmeyerHash.substringHash(prefixHashes, zeroLen*numLeadingZeros, zeroLen*numLeadingZeros+oneLen);
		
		if (zeroHash.equals(oneHash))
			return false;
		
		for (int i=0; i<wordA.length; i++) {
			if (wordA[i]=='0') {
				if (!zeroHash.equals(HarmeyerHash.substringHash(prefixHashes, pos, pos+zeroLen))) {
					return false;
				}
				pos+=zeroLen;
			}
			else {
				if (!oneHash.equals(HarmeyerHash.substringHash(prefixHashes, pos, pos+oneLen))) {
					return false;
				}
				pos+=oneLen;
			}
		}
//		System.out.println("returning true for "+zeroLen+" "+oneLen);
		return true;
	}
	
	static class HarmeyerHash implements Comparable<HarmeyerHash> {
		static final long m1=8675309, m2=1_000_000_007;
		private long v1=0, v2=0;
		static final long s1=257, s2=619;
		static long[] s1Pow, s2Pow;
		
		public void add(char o) {
			v1=(v1*s1+o)%m1;
			v2=(v2*s2+o)%m2;
		}
		
		public int compareTo(HarmeyerHash o) {
			if (v1!=o.v1)
				return Long.compare(v1, o.v1);
				return Long.compare(v2, o.v2);
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
			//hash from 0 to (to-1)
			//remove hash from 0-(from-1)
			if (from==to)
				return new HarmeyerHash();
			HarmeyerHash old=prefixHashes[to].clone(), toSub=prefixHashes[from];
			int diff=to-from;
			//TODO: precomp this to remove the log factor
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

}