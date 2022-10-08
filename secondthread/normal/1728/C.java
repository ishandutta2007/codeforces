import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Random;
import java.util.StringTokenizer;

import javax.imageio.ImageIO;

/*

Delete anything that matches

If anything has multiple digits, make it 1 digit
delete anything that matches in each

For everything that isn't 1, make it a 1

 */
public class C {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			int[] b=fs.readArray(n);
			HashMap<Integer, Integer> ma=new HashMap<>(), mb=new HashMap<>();
			for (int i:a) ma.put(i, ma.getOrDefault(i, 0)+1);
			for (int i:b) mb.put(i, mb.getOrDefault(i, 0)+1);
			for (int i:a) {
				if (mb.containsKey(i))
					kill(i, ma, mb);
			}

			//if anything has multiple digits, make each 1 digit
			int[] countsA=new int[10], countsB=new int[10];
			for (int i=0; i<10; i++) {
				countsA[i]+=ma.getOrDefault(i, 0);
				countsB[i]+=mb.getOrDefault(i, 0);
			}
			int moves=0;
			for (int x:ma.keySet()) {
				if (x<10) continue;
				int count=ma.get(x);
				int digits=(x+"").length();
				countsA[digits]+=count;
				moves+=count;
			}
			for (int x:mb.keySet()) {
				if (x<10) continue;
				int count=mb.get(x);
				int digits=(x+"").length();
				countsB[digits]+=count;
				moves+=count;
			}
			for (int i=2; i<10; i++) {
				moves+=Math.abs(countsA[i]-countsB[i]);
			}
			out.println(moves);
		}
		out.close();
	}

	static void kill(int i, HashMap<Integer, Integer> ma, HashMap<Integer, Integer> mb) {
		if (ma.get(i)==1) {
			ma.remove(i);
		}
		else {
			ma.put(i, ma.get(i)-1);
		}
		if (mb.get(i)==1) {
			mb.remove(i);
		}
		else {
			mb.put(i, mb.get(i)-1);
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