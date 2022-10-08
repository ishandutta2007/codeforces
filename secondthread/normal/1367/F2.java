import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeSet;
/*
9
5
4 7 2 2 9
5
3 5 8 1 7
5
1 2 2 4 5
2
0 1
3
0 1 0
4
0 1 0 0
4
0 1 0 1
4
0 1 0 2
20
16 15 1 10 0 14 0 10 3 9 2 5 4 5 17 9 10 20 0 9

1
2
0 1

1
3
1 2 3


1
7
2 1 1 2 2 2 1 
 */
public class F {

	public static void main(String[] args) throws FileNotFoundException {
//		Random r=new Random(5);
//		int T=100000;
//		for (int tt=0; tt<T; tt++) {
//			ArrayList<Integer> list=new ArrayList<>();
//			int n=1+r.nextInt(10);
//			for (int i=0; i<n; i++) list.add(r.nextInt(10));
//			Collections.sort(list);
//			int ll=r.nextInt(10);
//			int rr=r.nextInt(10);
//			int myAns=nInRange(list, ll, rr);
//			int jury=nInRangeBrute(list, ll, rr);
//			if (myAns != jury) {
//				System.out.println("l: "+ll+" r: "+rr);
//				System.out.println(list+" "+myAns+" "+jury);
//				throw null;
//			}
//			
//		}
//		System.out.println("Passed all");
//		Scanner fs=new Scanner(new File("F.in"));
//		PrintWriter out=new PrintWriter(new File("FMe.out"));
		
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
//			int[] a=fs.readArray(n);
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=fs.nextInt();
			compress(a);
			int[] firstIndexOf=new int[n], lastIndexOf=new int[n];
			int[] nOccurances=new int[n+1];
			ArrayList<Integer>[] occurances=new ArrayList[n];
			for (int i=0; i<n; i++) occurances[i]=new ArrayList<>();
			Arrays.fill(firstIndexOf, n+1); Arrays.fill(lastIndexOf, -1);
			for (int i=0; i<n; i++) {
				nOccurances[a[i]]++;
				occurances[a[i]].add(i);
				firstIndexOf[a[i]]=Math.min(firstIndexOf[a[i]], i);
				lastIndexOf[a[i]]=Math.max(lastIndexOf[a[i]], i);
			}
			int ans=0;
			for (int i:nOccurances) ans=Math.max(ans, i);
			
			//dp[x] = how many numbers work starting at the first x
			int[] dp=new int[n+1];
			for (int x=n-1; x>=0; x--) {
				if (nOccurances[x]==0) continue;
				dp[x]+=nOccurances[x];
				if (nOccurances[x+1]==0) continue;
				if (lastIndexOf[x]<firstIndexOf[x+1]) {
					dp[x]+=dp[x+1];
				}
				else {
					dp[x]+=nInRange(occurances[x+1], lastIndexOf[x], n);
				}
			}
			
			
			for (int x=0; x<n; x++) {
				int prefix=x==0?0:nInRange(occurances[x-1], 0, firstIndexOf[x]);
				ans=Math.max(ans, prefix+dp[x]);
			}
			
			//handle keeping just two numbers
			for (int i=0; i<n; i++) {
				if (a[i]!=n-1) {
					ans=Math.max(ans, nInRange(occurances[a[i]], 0, i)+nInRange(occurances[a[i]+1], i+1, n));
				}
			}
			
			out.println(n-ans);
		}
		out.close();
	}
	
//	static int nInRangeBrute(ArrayList<Integer> list, int l, int r) {
//		int ans=0;
//		for (int i:list) if (i>=l && i<=r) ans++;
//		return ans;
//	}
	
	//inclusive, inclusive, assuming list is sorted
	static int nInRange(ArrayList<Integer> list, int l, int r) {
//		System.out.println("Querying nInRange: "+l+" "+r+" for array: "+list);
		int n=list.size();
		if (list.isEmpty() || list.get(0)>r || list.get(n-1)<l || r<l) return 0;
		
		//first index >= l
		int min=0, max=n-1;
		while (min!=max) {
			int mid=(min+max)/2;
			if (list.get(mid) >= l) {
				max=mid;
			}
			else {
				min=mid+1;
			}
		}
		int firstLegal=min;
		
		//last index <=r
		min=0; max=n-1;
		while (min!=max) {
			int mid=(min+max+1)/2;
			if (list.get(mid)<=r) {
				min=mid;
			}
			else {
				max=mid-1;
			}
		}
		int lastLegal=min;
		return lastLegal-firstLegal+1;
	}
	
	static void compress(int[] a) {
		TreeSet<Integer> vals=new TreeSet<>();
		for (int i:a) vals.add(i);
		HashMap<Integer, Integer> map=new HashMap<>();
		int index=0;
		for (int i:vals)
			map.put(i, index++);
		for (int i=0; i<a.length; i++) a[i]=map.get(a[i]);
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