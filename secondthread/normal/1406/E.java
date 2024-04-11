import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;
import java.util.StringTokenizer;

// 1 5 6 7
public class E {

	static int SQRT=317;
//	static int SQRT=4;
//	static int MAX_N=10;
	static int MAX_N=100_000;
	static boolean[] shouldBeAlive;
	static int nAlive;
	
	static int n;
	
	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);

		n=fs.nextInt();
		shouldBeAlive=new boolean[n+1];
		Arrays.fill(shouldBeAlive, true);
		shouldBeAlive[0]=false;
		nAlive=n;
		
		int ans=1;
		int[] primes=getPrimes();
		//small: delete, check size (not many)
		for (int p:primes) {
			if (p>=SQRT) continue;
			//delete then check size
			QUERY_B(p, fs);
			killAllMultiplesOf(p);
		}
		
		int aliveReal=QUERY_A(1, fs);
		if (aliveReal!=nAlive) {
			System.err.println("Contains a small prime");
			for (int prime:primes) {
				if (prime<SQRT) {
					long prev=1;
					int prod=prime;
					while (true) {
						int c=QUERY_A(prod, fs);
						if (c==0) {
							break;
						}
						prev=prod;
						prod*=prime;
					}
					ans*=prev;
				}
				else {
					int deleted=QUERY_B(prime, fs);
					int supposeToBeDeleted=killAllMultiplesOf(prime);
					if (deleted!=supposeToBeDeleted) {
						ans*=prime;
					}
				}
			}
			//count occurrences of each prime factor
			QUERY_C(ans);
		}
		else {
			System.err.println("Just one big prime");
			//just one big prime
			
			//misses the case in which it is just a big prime
			//fix:
			//save the sqrt queries until we know that at least 1 will hit
			
			// if none hit, we have 408 queries left to find just one big prime
			// sqrt decomp on the primes
			
			ArrayList<ArrayList<Integer>> buckets=getBuckets(primes);
			for (ArrayList<Integer> bucket:buckets) {
				for (int p:bucket) {
					QUERY_B(p, fs);
					killAllMultiplesOf(p);
				}
				aliveReal=QUERY_A(1, fs);
				if (aliveReal!=nAlive) {
					//TODO: find which prime caused that
					for (int p:bucket) {
						int c=QUERY_A(p, fs);
						if (c!=0) {
							QUERY_C(p);
							return;
						}
					}
				}
			}
			QUERY_C(1);
		}
		
		
		
	}
	
	static int QUERY_A(int val, Scanner fs) {
		if (val>n) return 0;
		System.out.println("A "+val);
		return fs.nextInt();
	}
	
	static int QUERY_B(int val, Scanner fs) {
		if (val>n) return 0;
		System.out.println("B "+val);
		return fs.nextInt();
	}
	
	static void QUERY_C(int val) {
		System.out.println("C "+val);
	}
	
	static ArrayList<ArrayList<Integer>> getBuckets(int[] a) {
		ArrayList<ArrayList<Integer>> res=new ArrayList<>();
		ArrayList<Integer> curBucket=new ArrayList<>();
		for (int i:a) {
			curBucket.add(i);
			if (curBucket.size()>=100) {
				res.add(curBucket);
				curBucket=new ArrayList<>();
			}
		}
		res.add(curBucket);
		return res;
	}
	
	static int[] getPrimes() {
		ArrayList<Integer> res=new ArrayList<>();
		for (int i=2; i<=MAX_N; i++)
			if (isPrime(i)) res.add(i);
		int[] ans=new int[res.size()];
		for (int i=0; i<ans.length; i++) ans[i]=res.get(i);
		return ans;
	}
	
	static int killAllMultiplesOf(int of) {
		int count=0;
		for (int val=of; val<shouldBeAlive.length; val+=of) {
			if (shouldBeAlive[val]) {
				shouldBeAlive[val]=false;
				nAlive--;
				count++;
			}
		}
		return count;
	}
	
	static boolean isPrime(int n) {
		for (int i=2; i*i<=n; i++)
			if (n%i==0) return false;
		return true;
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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