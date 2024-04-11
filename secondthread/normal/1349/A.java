import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class A {

	static int[] factor=new int[1_000_000];
	
	public static void main(String[] args) {
		precomp();
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
//		for (int i=0; i<100; i++) System.out.println(i+" "+factor[i]);
		
		ArrayList<Integer>[] times=new ArrayList[2_000_01];
		for (int i=0; i<times.length; i++) times[i]=new ArrayList<>();
		for (int cand:a) {
			while (cand!=1) {
				int prime=factor[cand];
				int tt=0;
				while (cand%prime==0) {
					tt++;
					cand/=prime;
				}
				times[prime].add(tt);
			}
		}
		long ans=1;
		for (int p=2; p<times.length; p++) {
			Collections.sort(times[p]);
			if (p==2) {
//				System.out.println(times[p].size()+" "+times[p]);
			}
			if (p==5) {
//				System.out.println(times[p].size()+" "+times[p]);
			}
			if (times[p].size()<=n-2) continue;
			if (times[p].size()==n-1) {
				ans*=slowPow(p, times[p].get(0));
			}
			else {
				ans*=slowPow(p, times[p].get(1));
			}
		}
		System.out.println(ans);
	}
	
	static long slowPow(long base, int e) {
		long ans=1;
		for (int i=0; i<e; i++) ans*=base;
		return ans;
	}
	
	static void precomp() {
		for (int i=2; i<1_000_000; i++) {
			if (factor[i]==0) {factor[i]=i;
			for (int j=i+i; j<factor.length; j+=i) factor[j]=i;
			}
		}
	}
	
	static long gcd(long a, long b) {
		if (b==0) return a;
		return gcd(b, a%b);
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> list=new ArrayList<>();
		for (int i:a) list.add(i);
		Collections.sort(list);
		for (int i=0; i<a.length; i++) a[i]=list.get(i);
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