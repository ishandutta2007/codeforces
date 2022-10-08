import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
3
1 2 1
1 2 1


3
1 2 1
1 3 4

3
1 2 1
33 53 61

3
1 2 1
4 3 1

2
1 5
5 11
 */
public class F {
	
	static ArrayList<Boolean> addToA=new ArrayList<>();
	static ArrayList<Long> nTimesAdded=new ArrayList<>();
	static boolean reversedTargets=false;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		long[] a=fs.readArray(n), b=fs.readArray(n);
		if (n==1) {
			if (a[0]==b[0]) {
				System.out.println("SMALL");
				System.out.println(0);
			}
			else {
				System.out.println("IMPOSSIBLE");
			}
			return;
		}
		else if (n==2) {
			if (eeuclid(b[0], b[1], true, a[0], a[1])) {
				printN2();
			}
			else {
				addToA.clear();
				nTimesAdded.clear();
				if (eeuclid(b[0], b[1], true, a[1], a[0])) {
					reversedTargets=true;
					printN2();
				}
				else {
					System.out.println("IMPOSSIBLE");
				}
			}
		}
		else {
			StringBuilder ops=new StringBuilder();
			int totalUndos=0;
			while (!match(a, b) && !matchRev(a, b)) {
				if (ascending(b)) {
					ops.append('P');
					unCS(b);
					totalUndos++;
					continue;
				}
				ops.append('R');
				reverse(b);
				if (ascending(b)) {
					ops.append('P');
					totalUndos++;
					unCS(b);
					continue;
				}
				System.out.println("IMPOSSIBLE");
				return;
			}
			if (!match(a, b)) {
				ops.append('R');
			}
			if (totalUndos>200_000) {
				System.out.println("BIG");
				System.out.println(totalUndos);
			}
			else {
				System.out.println("SMALL");
				System.out.println(ops.length());
				System.out.println(ops.reverse());
			}
		}
	}
	
	static void reverse(long[] b) {
		int n=b.length;
		long[] res=new long[n];
		for (int i=0; i<b.length; i++)
			res[i]=b[n-1-i];
		for (int i=0; i<n; i++) b[i]=res[i];
	}
	
	static boolean ascending(long[] b) {
		for (long i:b) if (i<1) return false;
		for (int i=1; i<b.length; i++) if (b[i]<=b[i-1]) return false;
		return true;
	}
	
	static void unCS(long[] b) {
		long cs=b[0];
		for (int i=1; i<b.length; i++) {
			b[i]-=cs;
			cs+=b[i];
		}
	}
	
	static boolean match(long[] a, long[] b) {
//		System.out.println("Looking at "+Arrays.toString(a)+" "+Arrays.toString(b));
		for (int i=0; i<a.length; i++) if (a[i]!=b[i]) return false;
		return true;
	}
	
	static boolean matchRev(long[] a, long[] b) {
		int n=a.length;
		for (int i=0; i<a.length; i++) if (a[i]!=b[n-1-i]) return false;
		return true;
	}

	static void printN2() {
		long totalTimes=0;
		for (long l:nTimesAdded)
			totalTimes+=l;
		if (totalTimes>200_000) {
			System.out.println("BIG");
			System.out.println(totalTimes);
			return;
		}
		System.out.println("SMALL");
		//then R=reverse, P=prefix sums
		StringBuilder sb=new StringBuilder("");
		if (reversedTargets) sb.append('R');
		boolean addingToA=false;
		for (int i=addToA.size()-1; i>=0; i--) {
			if (addingToA^addToA.get(i)) {
				sb.append('R');
				addingToA^=true;
			}
			for (int j=0; j<nTimesAdded.get(i); j++) {
				sb.append('P');
			}
		}
		if (addingToA) sb.append('R');
		System.out.println(sb.length());
		System.out.println(sb.toString());
	}
	
	//assume a>=b
	static boolean eeuclid(long a, long b, boolean normal, long finishA, long finishB) {
		if (b<=0) {
			return false;
		}
		if (b==finishB) {
			long toSub=a-finishA;
			if (toSub<0) return false;
			if (toSub%b!=0) return false;
			addToA.add(normal);
			nTimesAdded.add(toSub/b);
			return true;
		}
		long newA=a%b;
		long nBs=a/b;
		addToA.add(normal);
		nTimesAdded.add(nBs);
		return eeuclid(b, newA, !normal, finishB, finishA);
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
		long[] readArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}