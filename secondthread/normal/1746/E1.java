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
public class E {
	static Scanner fs=new Scanner(System.in);
	public static void main(String[] args) {
		int n=fs.nextInt();
		ArrayList<Integer> startWith=new ArrayList<>();
		for (int i=1; i<=n; i++) {
			startWith.add(i);
		}
		// while (startWith.size()>2) {
		// 	startWith=eliminateThird(startWith);
		// 	System.out.println(startWith.size());
		// }
		// System.out.println(nQueries);
		go(startWith);
	}

	static void go(ArrayList<Integer> a) {
		// System.out.println("In go with "+a);
		if (a.size()==1) {
			finalGuess(a.get(0), a.get(0));
			return;
		}
		if (a.size()<=2) {
			finalGuess(a.get(0), a.get(1));
			return;
		}
		if (a.size()==3) {
			go(eliminateThird(a));
			return;
		}
		// go(eliminateFourth(a));
		go(eliminateThird(a));
	}

	static ArrayList<Integer> eliminateFourth(ArrayList<Integer> a) {
		ArrayList<Integer>[] groups=new ArrayList[4];
		for (int i=0; i<4; i++) groups[i]=new ArrayList<>();
		for (int i=0; i<a.size(); i++) {
			groups[i%4].add(a.get(i));
		}
		ArrayList<Integer> ac=new ArrayList<>();
		ArrayList<Integer> ad=new ArrayList<>();
		ac.addAll(groups[0]);
		ac.addAll(groups[2]);
		ad.addAll(groups[0]);
		ad.addAll(groups[3]);
		boolean acc=guess(ac);
		boolean add=guess(ad);
		ArrayList<Integer> alive=new ArrayList<>();
		for (int i=0; i<a.size(); i++) {
			boolean inAC=i%4==0 || i%4==2;
			boolean inAD=i%4==0 || i%4==3;
			if ((inAC^acc) && (inAD^add)) continue;
			alive.add(a.get(i));
		}
		return alive;
	}
	

	static int nQueries=0;
	//takes 4 queries
	//returns what is still alive
	static ArrayList<Integer> eliminateThird(ArrayList<Integer> alive) {
		int n=alive.size();
		ArrayList<Integer>[] groups=new ArrayList[3];
		for (int i=0; i<3; i++) groups[i]=new ArrayList<>();
		for (int i=0; i<alive.size(); i++) {
			groups[i%3].add(alive.get(i));
		}
		ArrayList<Integer> res=new ArrayList<>();
		int bad=getBadGroup(groups[0], groups[1], groups[2]);
		// System.out.println("Got bad group "+bad);
		for (int i=0; i<3; i++) {
			if (bad!=i) res.addAll(groups[i]);
		}
		return res;
	}

	static int getBadGroup(ArrayList<Integer> a, ArrayList<Integer> b, ArrayList<Integer> c) {
		ArrayList<Integer> ab=new ArrayList<>(), bc=new ArrayList<>(), ac=new ArrayList<>();
		ab.addAll(a);ab.addAll(b);
		ac.addAll(a);ac.addAll(c);
		bc.addAll(b);bc.addAll(c);
		boolean inC1=guess(c);
		if (!inC1) {
			//say AB
			boolean inC2=guess(c);
			if (!inC2) {
				//said cc
				return 2;
			}
		}
		
		//they just told us that it's in C
		//the second time, they told us it's in C
		boolean resBC=guess(bc);
		if (resBC) {
			//they said C, BC, so not in A
			return 0;
		}
		else {
			//they said C, A, so not in B
			return 1;
		}
		

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