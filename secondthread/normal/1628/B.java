import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Random;
import java.util.StringTokenizer;

/*
2
ab
bad
 */
public class B {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[][] strings=new char[n][];
			for (int i=0; i<n; i++) strings[i]=fs.next().toCharArray();
			
			//base cases
			for (char[] s:strings) {
				if (isPal(s)) {
					out.println("YES");
					continue outer;
				}
			}
			
			HashSet<Long> revs=new HashSet<>();
//			for (char[] s:strings) {
//				revs.add(hashRev(s));
//			}
			for (int i=n-1; i>=0; i--) {
				char[] s=strings[i];
				if (s.length==2) {
					//us or us plus any character
					long hashFull=hash(s);
					if (revs.contains(hashFull)) {
						out.println("YES");
						continue outer;
					}
					for (int toAdd=1; toAdd<=26; toAdd++) {
						if (revs.contains(hashFull*100+toAdd)) {
							out.println("YES");
							continue outer;
						}
					}
				}
				else {
					long hashFull=hash(s);
					if (revs.contains(hashFull)) {
						out.println("YES");
						continue outer;
					}
					long hash2=hash(new char[] {s[0], s[1]});
					if (revs.contains(hash2)) {
						out.println("YES");
						continue outer;
					}
				}
				revs.add(hashRev(s));
			}
			out.println("NO");
			
		}
		out.close();
	}
	
	static boolean isPal(char[] s) {
		return s[0]==s[s.length-1];
	}
	
	static long hash(char[] s) {
		long ans=0;
		for (char c:s) {
			ans*=100;
			ans+=c-'a'+1;
		}
		return  ans;
	}
	
	static long hashRev(char[] s) {
		long ans=0;
		for (int i=0; i<s.length; i++) {
			char c=s[s.length-1-i];
			ans*=100;
			ans+=c-'a'+1;
		}
		return  ans;
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