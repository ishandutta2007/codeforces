import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class B {

	static int mod;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		mod=fs.nextInt();
		int[] dp=new int[n+1];
		int[] cs=new int[n+2];
		dp[n]=1;
		cs[n]=1;
		//TODO: make this faster
		for (int fillIn=n-1; fillIn>0; fillIn--) {
			int ans=0;
//			for (int i=fillIn+1; i<=n; i++) ans=add(ans, dp[i]);
			ans=sub(cs[fillIn+1], cs[n+1]);
			for (int mul=2; true; mul++) {
				int lower=mul*fillIn;
				int higher=mul*fillIn+mul-1;
				if (lower>n) break;
				higher=Math.min(higher, n);
//				for (int i=lower; i<=higher; i++) ans=add(ans, dp[i]);
				ans=add(ans, sub(cs[lower], cs[higher+1]));
			}
			dp[fillIn]=ans;
			cs[fillIn]=add(cs[fillIn+1], dp[fillIn]);
		}
		System.out.println(dp[1]);
	}
	
	static int add(int a, int b) {
		a+=b;
		if (a>=mod) return a-mod;
		return a;
	}
	
	static int sub(int a, int b) {
		a-=b;
		if (a<0) a+=mod;
		else if (a>=mod) a-=mod;
		return a;
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