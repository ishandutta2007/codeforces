import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.Scanner;
import java.util.StringTokenizer;
/*


If we ask 3 queries, we can see there are two different results


If we ask the same query twice, we can see there are two different results, but we don't know where they switched from FT to TF


17 pairs of the same question
34 question

Now we need to see if we still match the original questions, or if not, where it flipped
TT TF or FT
TT TFTF TTTT

Base 3
A B C
A A A B B B C C C


Half the numbers we keep for every query 
-> ever get NN, we know it wasn't in that group
-> ever get YY, we know it wasn't in the other group
-> YN -> In that group and TF or not in that group and FT

Their state is [true number, last was lie]

1 | 3 => Y
1 | 4 => Y

10|10 => 1
10|01 => 1
Can't be 00
2 is not the answer

10|10 => 0
10|01 => 0
Can't be 11
1 is not the answer

10|10 => 0
10|01 => 1
Can't be 10
3 is not the answer

10|10 => 1
10|01 => 0
Can't be 01
4 is not the answer



1 | 3 => Y  T
1 | 4 => N  F
4 is not the answer?


This can get it down to 3...
ABC

Can't have two adjacent -s in a col
They can't give the same answer to the same question twice in a row (then we know the answer)

001 1 --+ or 
110 1 ++-
							011 0 +-- Tells us not index 1
011 1 -++ Tells us not index 0

001 0 ++- or 
001 1 --+
							011 0 +-- Tells us not index 1
011 1 -++ Tells us not index 0






Always keep elemtn


 */
public class E2 {
	static final int size=100;
	static Scanner fs=new Scanner(System.in);
	public static void main(String[] args) {
		dp=new int[size*2][size*2];
		dpto=new int[size*2][size*2][];
		for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], -1);
		for (int i=0; i<size; i++) {
			for (int j=0; j<size; j++) {
				go(i, j);
				// if (i+j<5) {
				// 	System.out.println(i+" "+j+" "+go(i, j));
				// }
			}
		}
		// System.out.println("Done with precalc");

		int n=fs.nextInt();
		ArrayList<Integer> startWith=new ArrayList<>();
		for (int i=1; i<=n; i++) {
			startWith.add(i);
		}
		solve(startWith, new ArrayList<>());
	}

	static int[][] dp;
	static int[][][] dpto;

	static int go(int sizeFree, int sizeJustRejected) {
		if (sizeFree+sizeJustRejected<3) {
			return 0;
		}
		if (dp[sizeFree][sizeJustRejected]!=-1) {
			return dp[sizeFree][sizeJustRejected];
		}
		// System.out.println(sizeFree+" "+sizeJustRejected);
		int cost=Integer.MAX_VALUE/2;
		int[] to=null;
		for (int a=0; a<=sizeFree; a++) {
			int b=sizeFree-a;
			if (b<a) break;
			for (int c=0; c<=sizeJustRejected; c++) {
				if (a+c<1 || a+c==sizeFree+sizeJustRejected) continue;
				int d=sizeJustRejected-c;
				int ans1=b>sizeJustRejected || d>0 ? go(a+c, b): Integer.MAX_VALUE/2;
				int ans2=a>sizeJustRejected || c>0 ? go(b+d, a): Integer.MAX_VALUE/2;
				int ans=1+Math.max(ans1, ans2);
				if (cost>ans) {
					cost=ans;
					to=new int[] {a, c};
				}
			}
		}
		dpto[sizeFree][sizeJustRejected]=to;
		return dp[sizeFree][sizeJustRejected]=cost;
	}

	static int[] bestChoice(int freeSize, int rejectedSize) {
		if (freeSize>=size || rejectedSize>=size) {
			return new int[] {freeSize/2, (rejectedSize+1)/2};
		}
		go(freeSize, rejectedSize);
		return dpto[freeSize][rejectedSize];
	}

	static void solve(ArrayList<Integer> freeGroup, ArrayList<Integer> justRejectedGroup) {
		// System.out.println("In solve "+freeGroup+" rejects: "+justRejectedGroup);
		ArrayList<Integer> all=new ArrayList<>();
		all.addAll(freeGroup);
		all.addAll(justRejectedGroup);
		if (all.size()<3) {
			if (all.size()==1) {
				finalGuess(all.get(0), all.get(0));
				return;
			}
			else {
				finalGuess(all.get(0), all.get(1));
				return;
			}
		}

		int[] sizes=bestChoice(freeGroup.size(), justRejectedGroup.size());
		// System.out.println("  Sizes: "+Arrays.toString(sizes));
		ArrayList<Integer> a=new ArrayList<>(), b=new ArrayList<>(), c=new ArrayList<>(), d=new ArrayList<>();
		for (int i=0; i<freeGroup.size(); i++) {
			if (i<sizes[0]) a.add(freeGroup.get(i));
			else b.add(freeGroup.get(i));
		}
		for (int i=0; i<justRejectedGroup.size(); i++) {
			if (i<sizes[1]) c.add(justRejectedGroup.get(i));
			else d.add(justRejectedGroup.get(i));
		}
		// AC for the AC
		ArrayList<Integer> ac=new ArrayList<>();
		ac.addAll(a);
		ac.addAll(c);
		boolean inAC=guess(ac);
		ArrayList<Integer> newFree=new ArrayList<>(), newRejects=new ArrayList<>();
		if (inAC) {
			newFree.addAll(a);
			newFree.addAll(c);
			newRejects.addAll(b);
		}
		else{
			newFree.addAll(b);
			newFree.addAll(d);
			newRejects.addAll(a);
		}
		solve(newFree, newRejects);
	}


	static boolean guess(ArrayList<Integer> nums) {
		StringBuilder builder=new StringBuilder();
		builder.append("? "+nums.size()+" ");
		for (int i:nums) builder.append(i+" ");
		System.out.println(builder.toString());
		System.out.flush();
		String next=fs.next();
		if (next.equals("YES")) return true;
		else return false;
	}

	static void finalGuess(int a, int b) {
		System.out.println("! "+a);
		String res=fs.next();
		if (res.equals(":)")) return;
		System.out.println("! "+b);
		return;
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