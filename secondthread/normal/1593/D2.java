import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
3
6
1 5 3 1 1 5
8
-1 0 1 -1 0 1 -1 0
4
1 1 1 1

1
8
-1 0 1 -1 0 1 -1 0

1
4
5 2 1 3

 */
public class D2Submitted {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
//		System.out.println(factorsOf(1000000));
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			for (int i=0; i<a.length; i++) a[i]+=1_000_000;
			int[] cs=new int[2_000_001];
			for (int i:a) cs[i]++;
			int maxInCS=cs[0];
			for (int i:cs) maxInCS=Math.max(maxInCS, i);
			if (maxInCS*2>=n) {
				System.out.println(-1);
				continue;
			}
			int ans=1;
			
			for (int i=0; i<n; i++) {
				for (int j=i+1; j<n; j++) {
					int diff=Math.abs(a[i]-a[j]);
					if (diff!=0) {
						ArrayList<Integer> factors=factorsOf(diff);
						for (int k:factors)
							if (works(k, a))
								ans=Math.max(ans, k);
					}
				}
			}
			
			System.out.println(ans);
		}
	}
	
	static ArrayList<Integer> factorsOf(int x) {
		x=Math.abs(x);
		ArrayList<Integer> ans=new ArrayList<>();
		for (int i=1; i*i<=x; i++) {
			if (x%i==0) {
				ans.add(i);
				ans.add(x/i);
			}
		}
		return ans;
	}
	
	static boolean works(int k, int[] a) {
		a=a.clone();
		for (int i=0; i<a.length; i++) {
			a[i]%=k;
		}
		sort(a);
		int last=a[0], count=0;
		for (int i:a) {
			if (i==last) {
				count++;
			}
			else {
				count=1;
				last=i;
			}
			if (count*2>=a.length) return true;
		}
		return false;
	}
	
	static int gcd(int a, int b) {
		if (b==0) return a;
		return gcd(b, a%b);
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