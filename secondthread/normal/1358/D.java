import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nMonths=fs.nextInt();
		long windowSize=fs.nextLong();
		int[] lengths=fs.readArray(nMonths);
		TreeMap<Long, Long> map=new TreeMap<>();
		long time=0;
		long csHugs=0;
		for (int i=0; i<nMonths; i++) {
			map.put(time, csHugs);
			time+=lengths[i];
			csHugs+=nc2(lengths[i]);
		}
		long cycleLength=time;
		for (int i=0; i<nMonths; i++) {
			map.put(time, csHugs);
			time+=lengths[i];
			csHugs+=nc2(lengths[i]);
		}
		long ans=0;
		time=cycleLength;
		for (int i=0; i<nMonths; i++) {
			time+=lengths[i];
			long end=eval(time, map);
			long start=eval(time-windowSize, map);
			ans=Math.max(ans, end-start);
		}
		System.out.println(ans);
	}
	
	static long eval(long at, TreeMap<Long, Long> map) {
		long prevTime=map.floorKey(at);
		long nHugs=map.get(prevTime);
		return nHugs+nc2(at-prevTime);
	}
	
	static long nc2(long n) {
		return n*(n+1)/2;
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