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
		int nProjects=fs.nextInt();
		long resumeSize=fs.nextLong();
		long[] a=new long[nProjects];
		for (int i=0; i<nProjects; i++) a[i]=fs.nextLong();
		long maxDelta=(long)8e18;
		long minDelta=0;
		long toSub=(long)4e18;
		while (minDelta!=maxDelta) {
//			System.out.println(minDelta+" "+maxDelta);
			long mid=minDelta+((maxDelta-minDelta)>>1);
			long[] placed=tryPlacing(mid-toSub, a);
			if (tooMany(placed, resumeSize)) {
				minDelta=mid+1;
			}
			else {
				maxDelta=mid;
			}
		}
		long[] originalPlaced=tryPlacing(minDelta-toSub, a);
		ArrayList<Pair> pairs=new ArrayList<>();
		for (int i=0; i<nProjects; i++) {
			resumeSize-=originalPlaced[i];
			if (originalPlaced[i]<a[i]) {
				//then I can place more
				long bi=originalPlaced[i];
				long dValue=a[i]-(3*bi*bi+3*bi+1);
				pairs.add(new Pair(dValue, i));
			}
		}
		Collections.sort(pairs);
		for (int i=0; i<resumeSize; i++) {
			int toUpgrade=pairs.get(pairs.size()-1-i).index;
			originalPlaced[toUpgrade]++;
		}
		PrintWriter out=new PrintWriter(System.out);
		for (int i=0; i<nProjects; i++) {
			out.print(originalPlaced[i]+" ");
		}
		out.println();
		out.close();
	}
	
	static boolean tooMany(long[] bs, long k) {
		long sum=0;
		for (long l:bs) sum+=l;
		return sum>k;
	}
	
	static long[] tryPlacing(long delta, long[] a) {
		int n=a.length;
		long[] bs=new long[n];
		for (int i=0; i<n; i++) bs[i]=findBI(delta, a[i]);
		return bs;
	}
	
	static long findBI(long delta, long a) {
		long min=0, max=a;
		while (min<max) {
//			System.out.println(min+" "+max);
			long mid=(min+max+1)>>1;
			if (delta<=a-(3*mid*mid+3*mid+1)) {
				min=mid;
			}
			else {
				max=mid-1;
			}
		}
		return min;
	}
	
	static class Pair implements Comparable<Pair> {
		long value;
		int index;
		public Pair(long value, int index) {
			this.value=value;
			this.index=index;
		}
		
		public int compareTo(Pair o) {
			return Long.compare(value, o.value);
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
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
		long nextLong() {
			return Long.parseLong(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}
	
	public void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

}