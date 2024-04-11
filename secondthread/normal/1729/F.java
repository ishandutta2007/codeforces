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
1
1003004
4 1
1 2 1
 */
public class F {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			char[] line=fs.next().toCharArray();
			int[] cs=new int[line.length+1];
			for (int i=1; i<=line.length; i++)
				cs[i]=cs[i-1]+(line[i-1]-'0');

			int substringLen=fs.nextInt();
			int nQ=fs.nextInt();
			int[][] hit1=new int[9][];
			int[][] hit2=new int[9][];
			// System.out.println(Arrays.toString(cs));
			for (int end=substringLen-1; end<line.length; end++) {
				int total=(cs[end+1]-cs[end+1-substringLen])%9;
				int start=end+1-substringLen;
				if (hit1[total]==null) {
					hit1[total]=new int[] {start, end};
				}
				else if (hit2[total]==null) {
					hit2[total]=new int[] {start, end};
				}
			}
			for (int qq=0; qq<nQ; qq++) {
				int left=fs.nextInt()-1, right=fs.nextInt()-1, modVal=fs.nextInt();
				int scalar=(cs[right+1]-cs[left])%9;
				int ansl=-1, ansl2=-1;
				for (int v1=0; v1<9; v1++) {
					for (int v2=0; v2<9; v2++) {
						if ((v1*scalar+v2)%9!=modVal) continue;
						if (hit1[v1] == null) continue;
						if (hit1[v2] == null) continue;
						if (v1==v2 && hit2[v1]==null) continue;
						// System.out.println("Considering "+v1+" "+v2);

						int l1=hit1[v1][0];
						int l2=v1==v2?hit2[v2][0]:hit1[v2][0];
						if (ansl==-1 || ansl>l1 || (ansl==l1 &&ansl2>l2)) {
							ansl=l1;
							ansl2=l2;
							// System.out.println("Got "+l1+" "+l2);
						}
					}
				}
				//TODO: print stuff not 0-based!
				if (ansl==-1) {
					out.println(ansl+" "+ansl2);
				}
				else {
					out.println(ansl+1+" "+(ansl2+1));
				}
			}

		}
		out.close();
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