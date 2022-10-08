import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

/*
1
6 1
6 3 6 7 3 3
3 6


 */
public class E {

	static HashMap<Integer, Integer> compress;
	static HashSet<Long> badPairs;
	static int[] valueOfID;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int nBadPairs=fs.nextInt();
			int[] a=fs.readArray(n);
			badPairs=new HashSet<>();
			for (int i=0; i<nBadPairs; i++) {
				int first=fs.nextInt(), second=fs.nextInt();
				badPairs.add(toLong(first, second));
				badPairs.add(toLong(second, first));
			}
			for (int i:a) {
				badPairs.add(toLong(i, i));
			}
			
			comp(a);
			ArrayList<ArrayList<Integer>> nonnullBuckets=new ArrayList<>();
			ArrayList<Integer>[] buckets=new ArrayList[n+1];
			int[] countOfID=new int[a.length];
			for (int i:a) countOfID[i]++;
			for (int i=0; i<a.length; i++) {
				if (countOfID[i]!=0) {
					if (buckets[countOfID[i]]==null) {
						buckets[countOfID[i]]=new ArrayList<>();
						nonnullBuckets.add(buckets[countOfID[i]]);
					}
					buckets[countOfID[i]].add(i);
				}
			}
			long best=0;
			for (int i=0; i<nonnullBuckets.size(); i++) {
				for (int j=i; j<nonnullBuckets.size(); j++) {
					best=Math.max(best, getMax(nonnullBuckets.get(i), nonnullBuckets.get(j), countOfID));
				}
			}
			out.println(best);
		}
		out.close();
	}
	
	static long toLong(int a, int b) {
		return a*1_000_000_001l+b;
	}
	
	static boolean isBad(int a, int b) {
		return badPairs.contains(toLong(valueOfID[a], valueOfID[b]));
	}
	
	static long getMax(ArrayList<Integer> ids1, ArrayList<Integer> ids2, int[] countsOfID) {
		long best=0;
		ArrayList<Integer> smaller=ids1.size()<ids2.size()?ids1:ids2;
		ArrayList<Integer> bigger=smaller==ids1?ids2:ids1;
		int bestBig=-1;
		outer: for (int smallerIndex=smaller.size()-1; smallerIndex>=0; smallerIndex--) {
			for (int matchWith=bigger.size()-1; matchWith>bestBig; matchWith--) {
				int smallVal=smaller.get(smallerIndex), bigVal=bigger.get(matchWith);
				if (eval(smallVal, bigVal, countsOfID)<=best)
					break;
				if (!isBad(smallVal, bigVal)) {
					best=Math.max(best, eval(smallVal, bigVal, countsOfID));
					bestBig=matchWith;
					if (matchWith==bigger.size()-1)
						break outer;
					break;
				}
			}
		}
		return best;
	}
	
	static long eval(int a, int b, int[] countsOfID) {
		return (countsOfID[a]+countsOfID[b])*(long)(valueOfID[a]+valueOfID[b]);
	}
	
	static void comp(int[] a) {
		TreeSet<Integer> ts=new TreeSet<>();
		for (int i:a) ts.add(i);
		compress=new HashMap<>();
		valueOfID=new int[ts.size()];
		for (int i:ts) compress.put(i, compress.size());
		for (int i=0; i<a.length; i++) {
			valueOfID[compress.get(a[i])]=a[i];
			a[i]=compress.get(a[i]);
		}
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