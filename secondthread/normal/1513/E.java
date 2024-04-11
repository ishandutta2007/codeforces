
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class E {

	static long mod=1_000_000_007;
	static long[] facts=new long[200_000];
	static long[] factInvs=new long[200_000];
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		precomp();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		long sum=0;
		for (int i:a) sum+=i;
		if (sum%n!=0) {
			System.out.println(0);
			return;
		}
		for (int i=0; i<n; i++) a[i]-=sum/n;
		HashMap<Integer, Integer> countsOf=new HashMap<>();
		for (int i:a) countsOf.put(i, countsOf.getOrDefault(i, 0)+1);
		int posCount=0, negCount=0;
		for (int i:a) {
			if (i>0) posCount++;
			if (i<0) negCount++;
		}
		if (posCount==0 && negCount==0) {
			System.out.println(1);
			return;
		}
		if (posCount==1 || negCount==1) {
			//anything works
			//TODO: not actually facts[n], because we might have dupes
			long ways=facts[n];
			for (Map.Entry<Integer, Integer> e:countsOf.entrySet()) {
				ways=mul(ways, factInvs[e.getValue()]);
			}
			System.out.println(ways);
			return;
		}
		
		int zeroCount=n-posCount-negCount;
		//otherwise positives all need to be on one side
		// TODO: set ways to the number of ways to have all positives
		// on the left, all negatives on the right
		long posWays=facts[posCount];
		long negWays=facts[negCount];
		for (Map.Entry<Integer, Integer> e:countsOf.entrySet()) {
			if (e.getKey()>0) {
				posWays=mul(posWays, factInvs[e.getValue()]);
			}
			else if (e.getKey()<0) {
				negWays=mul(negWays, factInvs[e.getValue()]);
			}
		}
		long ways=mul(posWays, negWays);
		ways=mul(ways, 2);
		
		//TODO: count ways of putting zeros anywhere
		ways=mul(ways, nCk(n, zeroCount));
		System.out.println(ways);
	}
	
	static long nCk(int n, int k) {
		return mul(facts[n], mul(factInvs[k], factInvs[n-k]));
	}
	
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	static long mul(long a, long b) {
		return a*b%mod;
	}
	static long fastExp(long base, long exp) {
		if (exp==0) return 1;
		long half=fastExp(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	static void precomp() {
		facts[0]=1;
		for (int i=1; i<facts.length; i++) facts[i]=mul(i, facts[i-1]);
		for (int i=0; i<facts.length; i++) factInvs[i]=fastExp(facts[i], mod-2);
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
		
		int[] readArray(int n) {
			int[] a=new int[n]; 
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		int nextInt () {
			return Integer.parseInt(next());
		}
	}

}