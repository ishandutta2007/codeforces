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


3 3
1 2
2 3
3 1

1
6
())((()))(()

1
5
())((()))(
1
5
()))((())(

1
4
)(()))((

 */
public class C {

	static PrintWriter out;
	
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		out=new PrintWriter(System.out);
		int T=fs.nextInt();
//		int T=10000;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt()*2;
			char[] a=fs.next().toCharArray();
			
			
//			int n=random.nextInt(5)*2;
//			char[] a=new char[n];
//			HashSet<Integer> indecies=new HashSet<>();
//			while (indecies.size()<n/2)
//				indecies.add(random.nextInt(n));
//			for (int i=0; i<n; i++) a[i]=indecies.contains(i)?'(':')';
//			System.out.println(a);
			
			
			if (possible(a)) {
				out.println(0);
				continue;
			}
			int[] prefixSums=new int[n+1];
			for (int i=1; i<=n; i++) prefixSums[i]=prefixSums[i-1]+(a[i-1]=='('?1:-1);
			// check if possible in 1
			// find the biggest before first negative
			
			int maxdex=0;
			for (int i=0; i<=n; i++) {
				if (prefixSums[i]<0) break;
				if (prefixSums[i]>prefixSums[maxdex]) maxdex=i;
			}
			
			int endMaxdex=n;
			for (int i=n; i>=0; i--) {
				if (prefixSums[i]<0) break;
				if (prefixSums[i]>prefixSums[endMaxdex]) endMaxdex = i;
			}
//			System.out.println(Arrays.toString(prefixSums));
//			System.out.println(endMaxdex+" "+maxdex);
			
			char[] oneTry=a.clone();
			reverse(oneTry, maxdex, endMaxdex-1);
			if (possible(oneTry)) {
				out.println(1);
				out.println(maxdex+1+" "+(endMaxdex-1 + 1));
				continue;
			}
//			System.err.println(Arrays.toString(prefixSums));
			
			// always possible in 2
			int fullMindex=0;
			int fullMaxdex=0;
			for (int i=0; i<=n; i++) {
				if (prefixSums[i]<prefixSums[fullMindex]) fullMindex=i;
				if (prefixSums[i]>prefixSums[fullMaxdex]) fullMaxdex=i;
			}
			char[] tryTwo=a.clone();
			out.println(2);
			if (fullMindex<fullMaxdex) {
				int aa=0;
				int cc=fullMindex-1;
				int dd=fullMindex;
				int gg=fullMaxdex-1;
				int hh=fullMaxdex;
				int jj=n-1;
				reverseP(tryTwo, aa, gg);
				reverseP(tryTwo, gg-(cc-aa), jj);
				if (!possible(tryTwo)) throw null;
			}
			else {
				int aa=0;
				int cc=fullMaxdex-1;
				int dd=fullMaxdex;
				int gg=fullMindex-1;
				int hh=fullMindex;
				int jj=n-1;
				reverseP(tryTwo, dd, jj);
				reverseP(tryTwo, aa, jj-(gg-dd+1));
//				out.println(tryTwo);
				if (!possible(tryTwo)) {
					out.close();
					throw null;
				}
			}
			
			
			if (!possible(tryTwo)) throw null; 
			
		}
		out.close();
	}
	static void reverse(char[] a, int fromInc, int toInc) {
		char[] middle=new char[toInc-fromInc+1];
		for (int i=0; i<middle.length; i++) middle[i]=a[fromInc+i];
		for (int i=0; i<middle.length; i++)
			a[fromInc+i]=middle[middle.length-1-i];
	}
	static void reverseP(char[] a, int fromInc, int toInc) {
		out.println(fromInc+1+" "+(toInc+1));
		char[] middle=new char[toInc-fromInc+1];
		for (int i=0; i<middle.length; i++) middle[i]=a[fromInc+i];
		for (int i=0; i<middle.length; i++)
			a[fromInc+i]=middle[middle.length-1-i];
	}
	
	static boolean possible(char[] a) {
		int count=0;
		for (char c:a) {
			if (c=='(') count++;
			else count--;
			if (count<0) return false;
		}
		if (count!=0) throw null;
		return true;
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