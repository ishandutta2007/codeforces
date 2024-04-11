import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;


public class B {
	static boolean[] isPrime=new boolean[1_000_001];
	static int[] factorOf=new int[1_000_001];

	public static void main(String[] args) {
		precomp();
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			HashMap<Integer, Integer> counts=new HashMap<>();
			for (int i:a) {
				i=getOddFactors(i);
				counts.put(i, counts.getOrDefault(i, 0)+1);
			}
			int zeroAns=0;
			for (int i:counts.keySet()) zeroAns=Math.max(zeroAns, counts.get(i));
			int oneAns=counts.getOrDefault(1, 0);
			for (int i:counts.keySet()) if (i!=1 && counts.get(i)%2==0) oneAns+=counts.get(i);
			int q=fs.nextInt();
			for (int qq=0; qq<q; qq++) {
				long type=fs.nextLong();
				if (type==0) {
					out.println(zeroAns);
				}
				else {
					out.println(Math.max(zeroAns, oneAns));
				}
			}
		}
		out.close();
	}

	static void precomp() {
		Arrays.fill(isPrime, true);
		for (int i=2; i<isPrime.length; i++) {
			if (!isPrime[i]) continue;
			factorOf[i]=i;
			for (int j=i*2; j<isPrime.length; j+=i) {
				isPrime[j]=false;
				factorOf[j]=i;
			}
		}
	}
	
	static int getOddFactors(int n) {
		int res=1;
		if (n==1) return res;
		while (n!=1) {
			int factor=factorOf[n];
			int nTimes=0;
			while (n%factor==0) {
				nTimes++;
				n/=factor;
			}
			if (nTimes%2!=0) res*=factor;
		}
		return res;
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