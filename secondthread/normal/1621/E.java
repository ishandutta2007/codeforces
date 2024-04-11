import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeMap;
/*
2
1 1
30
3
25 16 37

4 2
9 12 12 6
2
4 5
3
111 11 11



1
1 1
30
3
25 16 37

1
5 1
1 2 3 3 1
2
4 4

1
2 2
4 4
2
4 5
2
3 4

1
2 2
2 2 
3
1 3 2 
3
2 2 1 


 */
public class E {

	public static void main(String[] args) throws FileNotFoundException {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
//		PrintWriter out=new PrintWriter(new File("E.out"));
		for (int tt=0; tt<T; tt++) {
			int nTeachers=fs.nextInt(), nGroups=fs.nextInt();
			int[] teachersRaw=fs.readArray(nTeachers);
			sort(teachersRaw);
			int[] b=new int[nGroups];
			for (int i=0; i<nGroups; i++)
				b[i]=teachersRaw[i+(nTeachers-nGroups)];
			
			Group[] a=new Group[nGroups];
			for (int i=0; i<nGroups; i++) {
				int n=fs.nextInt();
				int[] values=fs.readArray(n);
				a[i]=new Group(values);
			}
			Group[] unsorted=a.clone();
			Arrays.sort(a);
			for (int i=0; i<nGroups; i++) a[i].position=i;
			
			BIT okayToStay=new BIT(nGroups);
			BIT okayLeft=new BIT(nGroups);
			BIT okayRight=new BIT(nGroups);
			for (int i=0; i<nGroups; i++) {
				if (a[i].averageCeiled<=b[i])
					okayToStay.update(i, 1);
				if (i>0 && a[i].averageCeiled<=b[i-1])
					okayLeft.update(i, 1);
				if (i+1<nGroups && a[i].averageCeiled<=b[i+1])
					okayRight.update(i, 1);
			}
			TreeMap<Long, Integer> lastThingWithAverage=new TreeMap<>();
			for (int i=0; i<nGroups; i++) {
				lastThingWithAverage.put(a[i].averageCeiled, i);
			}
			lastThingWithAverage.put(Long.MAX_VALUE/2, nGroups);
			lastThingWithAverage.put(Long.MIN_VALUE/2, -1);
			
			for (Group g:unsorted) {
				for (int i:g.values) {
					boolean canRemove=considerRemoveingPerson(g, i, lastThingWithAverage, okayToStay, okayLeft, okayRight, nGroups, b);
					out.print(canRemove?1:0);
				}
			}
			out.println();
		}
		out.close();
	}
	
	static boolean considerRemoveingPerson(Group oldValue, int decSumBy, 
			TreeMap<Long, Integer> lastThingWithAverage,
			BIT okayToStay,
			BIT okayLeft,
			BIT okayRight, 
			int nGroups,
			int[] b) {
		long newAverage=((oldValue.sum-decSumBy+(oldValue.n-2))/(oldValue.n-1));
		if (newAverage==oldValue.averageCeiled) {
			//nothing changes
			return okayToStay.query(0, nGroups-1)==nGroups;
		}
//		boolean print=oldValue.n==6 && decSumBy==1;
//		if (print)
//			System.out.println("Here "+newAverage+" "+oldValue.averageCeiled);
		if (newAverage<oldValue.averageCeiled) {
			//then this moves left
			int oldIndex=oldValue.position;
			int newIndex=lastThingWithAverage.lowerEntry(newAverage).getValue()+1;
			if (newIndex>oldIndex) throw null;
			int nGood=okayToStay.query(0, newIndex-1)+okayToStay.query(oldIndex+1, nGroups-1)+okayRight.query(newIndex, oldIndex-1);
			if (newAverage<=b[newIndex])nGood++;
			return nGood==nGroups;
		}
		else {
			//this moves right
			int oldIndex=oldValue.position;
			int newIndex=lastThingWithAverage.floorEntry(newAverage).getValue();
			if (newIndex<oldIndex) throw null;
			int nGood=okayToStay.query(0, oldIndex-1)+okayToStay.query(newIndex+1, nGroups-1)+okayLeft.query(oldIndex+1, newIndex);
			if (newAverage<=b[newIndex]) nGood++;
//			if (print) System.out.println("Moving right "+oldIndex+" "+newIndex);
			return nGood==nGroups;
		}
	}
	
	static class BIT {
		int n, tree[];
		
		public BIT(int N) {
			n = N;  tree = new int[N + 1];
		}

		void update(int i, int val) {
			for (i++; i <= n; i += i & -i) tree[i] += val;
		}
		
		int read(int i) {
			int sum = 0;
			for (i++; i > 0; i -= i & -i) sum += tree[i];
			return sum;
		}
		
		// query sum of [l, r] inclusive
		int query(int l, int r) { 
			if (l>r+1) throw null;
			if (l>r) return 0;
			return read(r) - read(l - 1); 
			}
		
		// if the BIT is a freq array, returns the index of the
		// kth item (0-indexed), or n if there are <= k items.
		int getKth(int k) {
			if (k < 0) return -1;
			int i = 0;
			for (int pw = Integer.highestOneBit(n); pw > 0; pw >>= 1)
				if (i + pw <= n && tree[i + pw] <= k) k -= tree[i += pw];
			return i;
		}
	}
	
	static class Group implements Comparable<Group> {
		long averageCeiled;
		int[] values;
		int position;
		long sum;
		int n;
		
		public Group(int[] values) {
			this.values=values;
			n=values.length;
			sum=0;
			for (int i:values) sum+=i;
			averageCeiled=(int) ((sum+n-1)/n);
		}
		public int compareTo(Group o) {
			return Long.compare(averageCeiled, o.averageCeiled);
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