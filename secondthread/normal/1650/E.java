import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;
/*
1
2 20
17 20
 */
public class E {
	
	static TreeSet<Integer> exams=new TreeSet<>();
	static TreeMap<Integer, Integer> rangeSizes=new TreeMap<>();

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			exams.clear();
			rangeSizes.clear();
			
			int n=fs.nextInt(), length=fs.nextInt();
			int[] a=fs.readArray(n);
			Range[] ranges=new Range[n];
			for (int i=0; i<a.length; i++)
				ranges[i]=new Range(i, i==0?a[i]:a[i]-a[i-1]);
			
			Arrays.sort(ranges);
			int toMove=ranges[0].id;
			addExam(0);
			for (int i:a) {
				addExam(i);
			}
			
			
			int ans=getMinRangeSize();
			for (int toSub=0; toSub<2 && toMove-toSub>=0; toSub++) {
				int startPos=a[toMove-toSub];
				{
					//move ourselves to the middle of our range
					Integer after=exams.higher(startPos);
					Integer before=exams.lower(startPos);
					if (after!=null) {
						removeExam(startPos);
						addExam((after+before)/2);
						ans=Math.max(ans, getMinRangeSize());
						removeExam((after+before)/2);
						addExam(startPos);
					}
				}
				
				{
					//move ourselves to the end
					if (!exams.contains(length)) {
						removeExam(startPos);
						addExam(length);
						ans=Math.max(ans, getMinRangeSize());
						removeExam(length);
						addExam(startPos);
					}
				}
				{
					int maxRange=ranges[ranges.length-1].id;
					//move ourselves to middle of best range
					int maxEnd=a[maxRange];
					int beforeMax=exams.lower(maxEnd);
					if (maxEnd-beforeMax>=2) {
						removeExam(startPos);
						addExam((beforeMax+maxEnd)/2);
						ans=Math.max(ans, getMinRangeSize());
						removeExam((beforeMax+maxEnd)/2);
						addExam(startPos);
					}
				}
			}
			
			System.out.println(ans-1);
		}
	}
	
	static void addExam(int time) {
		if (exams.contains(time)) throw null;
		Integer after=exams.higher(time);
		Integer before=exams.lower(time);
		if (after!=null) {
			removeRange(after-before);
		}
		exams.add(time);
		if (after!=null) addRange(after-time);
		if (before!=null) addRange(time-before);
	}
	
	static void removeRange(int size) {
		rangeSizes.put(size, rangeSizes.get(size)-1);
		if (rangeSizes.get(size)==0) rangeSizes.remove(size);
	}
	static void addRange(int size) {
		rangeSizes.put(size, rangeSizes.getOrDefault(size, 0)+1);
	}
	
	static void removeExam(int time) {
		if (!exams.contains(time)) throw null;
		exams.remove(time);
		Integer after=exams.higher(time);
		Integer before=exams.lower(time);
		if (after!=null) {
			removeRange(after-time);
			addRange(after-before);
		}
		if (before!=null) {
			removeRange(time-before);
		}
	}
	
	static int getMinRangeSize() {
		return rangeSizes.firstKey();
	}
	
	static int spaceBefore(int[] a, int ind) {
		return ind==0?a[0]:a[ind]-a[ind-1];
	}
	
	static class Range implements Comparable<Range> {
		int id;
		int size;
		public Range(int id, int size) {
			this.id=id;
			this.size=size;
		}
		public int compareTo(Range o) {
			return Integer.compare(size, o.size);
		}
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
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}

}