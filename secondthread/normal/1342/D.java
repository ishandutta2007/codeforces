import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nTests=fs.nextInt(), maxSize=fs.nextInt();
		int[] tests=new int[nTests];
		for (int i=0; i<nTests; i++) tests[i]=fs.nextInt()-1;
		sort(tests);
		
		int[] limitCS=new int[maxSize+1];
		int[] limit=new int[maxSize];
		for (int i=0; i<maxSize; i++) limitCS[i]=fs.nextInt();
		for (int i=0; i<maxSize; i++) limit[i]=limitCS[i]-limitCS[i+1];
		
		ArrayList<Array> list=new ArrayList<>();
		list.add(new Array(limitCS, limit));
		int listInd=0;
		for (int testsInd=nTests-1; testsInd>=0; testsInd--) {
			int toGive=tests[testsInd];
			int nextInd=(listInd+1)%list.size();
			if (!list.get(listInd).canTake(toGive) &&!list.get(nextInd).canTake(toGive)) {
				list.add(new Array(limitCS, limit));
				listInd=list.size()-1;
			}
			else if (!list.get(listInd).canTake(toGive)) {
				listInd=nextInd;
			}
			list.get(listInd).taken.add(toGive);
		}
		PrintWriter out=new PrintWriter(System.out);
		out.println(list.size());
		for (Array l:list) {
			out.print(l.taken.size()+" ");
			for (int i:l.taken) out.print(i+1+" ");
			out.println();
		}
		out.close();
	}
	
	static class Array {
		int[] limitCS, limit;
		ArrayList<Integer> taken=new ArrayList<>();
		public Array(int[] limitCS, int[] limit) {
			this.limit=limit;
			this.limitCS=limitCS;
		}
		
		int rangeSum(int l, int r) {
			return limitCS[l]-limitCS[r+1];
		}
		
		public boolean canTake(int value) {
			int sum=rangeSum(value, limit.length-1);
//			System.out.println("Sum for "+value+" is "+sum+" "+Arrays.toString(limitCS)+" "+Arrays.toString(limit));
			return sum>taken.size();
		}
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

		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
	
}