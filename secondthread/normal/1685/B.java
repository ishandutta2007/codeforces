import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

/*


3 3
1 2
2 3
3 1


A B AB AB BA BA
1 1 2 2
BA AB BA B BAA

BA AB B AB BA A

B AB BA
BABBA

 */
public class B2 {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int a=fs.nextInt(), b=fs.nextInt(), c=fs.nextInt(), d=fs.nextInt(), aCount=0, bCount=0;
			char[] line=fs.next().toCharArray();
			for (char cc:line) if (cc=='A') aCount++; else bCount++;
			if (aCount!=a+c+d || bCount!=b+c+d) {
				out.println("NO");
				continue;
			}
			ArrayList<Integer> splits=new ArrayList<>();
			for (int i=1; i<line.length; i++)
				if (line[i]==line[i-1])
					splits.add(i);
			splits.add(0);
			splits.add(line.length);
//			out.println(splits);
			ArrayList<Group> groupsNuetral=new ArrayList<>();
			ArrayList<Group> groupsABPref=new ArrayList<>();
			ArrayList<Group> groupsBAPref=new ArrayList<>();
			Collections.sort(splits);
			for (int i=1; i<splits.size(); i++) {
				//if they start and end with the same, it's size/2 floored
				int first=splits.get(i-1);
				int last=splits.get(i)-1;
				if (line[first]==line[last]) {
					int toGive=(last-first)/2;
					groupsNuetral.add(new Group(toGive, toGive));
				}
				else {
					if (line[first]=='A') {
						//then we can have one more ABs
						int abs=(last-first+1)/2;
						int bas=abs-1;
						groupsABPref.add(new Group(abs, bas));
					}
					else {
						int bas=(last-first+1)/2;
						int abs=bas-1;
						groupsBAPref.add(new Group(abs, bas));
					}
				}
			}
			
			Collections.sort(groupsNuetral);
			Collections.sort(groupsABPref);
			Collections.sort(groupsBAPref);
//			System.out.println(groupsNuetral);
//			System.out.println(groupsABPref);
//			System.out.println(groupsBAPref);
			for (Group g:groupsABPref) {
				if (c>=g.abs) {
					c-=g.abs;
				}
				else {
					int toSub=c;
					c=0;
					d-=g.bas-toSub;
				}
			}
			for (Group g:groupsBAPref) {
				if (d>=g.bas) {
					d-=g.bas;
				}
				else {
					int toSub=d;
					d=0;
					c-=g.abs-toSub;
				}
			}
			for (Group g:groupsNuetral) {
				if (c>=g.abs) {
					c-=g.abs;
				}
				else {
					int toSub=c;
					c=0;
					d-=g.bas-toSub;
				}
			}
			out.println(d<=0 && c<=0 ? "YES":"NO");
		}
		out.close();
	}
	
	static class Group implements Comparable<Group> {
		int abs, bas;
		public Group(int abs, int bas) {
			this.abs=abs;
			this.bas=bas;
		}
		public int compareTo(Group o) {
			return Integer.compare(abs, o.abs);
		}
		public String toString() {
			return "ABs: "+abs+" BAs: "+bas;
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