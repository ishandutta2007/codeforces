import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

/*
2
4 3
5 0
1 4
2 2
 */
public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int nBuy=fs.nextInt();
			int nTypes=fs.nextInt();
			Flower[] flowers=new Flower[nTypes];
			Flower[] bSorted=new Flower[nTypes];
			for (int i=0; i<nTypes; i++) bSorted[i]=flowers[i]=new Flower(fs.nextLong(), fs.nextLong());
			bComp=false;
			Arrays.sort(flowers);
			bComp=true;
			Arrays.sort(bSorted);
			
			long[] cs=new long[nTypes+1];
			for (int i=1; i<=nTypes; i++)
				cs[i]=cs[i-1]+flowers[i-1].a;
			
			int flowerIndex=0;
			long best=0;
			for (int i=0; i<nTypes; i++) {
				while (flowerIndex<nTypes && flowers[flowerIndex].a>bSorted[i].b) {
					flowers[flowerIndex].used=true;
					flowerIndex++;
				}
				long cand;
				if (nBuy<=flowerIndex) {
					cand=cs[nBuy];
				}
				else {
					if (bSorted[i].used) {
						int realBuy=nBuy-flowerIndex;
						cand=realBuy*(long)bSorted[i].b + cs[flowerIndex];
					}
					else {
						int realBuy=nBuy-flowerIndex-1;
						cand=realBuy*(long)bSorted[i].b + bSorted[i].a + cs[flowerIndex];
					}
				}
				best=Math.max(best, cand);
			}
			System.out.println(best);
		}
	}
	
	static boolean bComp=false;
	
	static class Flower implements Comparable<Flower> {
		long a, b;
		boolean used=false;
		
		public Flower(long a, long b) {
			this.a=a;
			this.b=b;
		}
		
		public int compareTo(Flower o) {
			if (bComp) return -Long.compare(b, o.b);
			return -Long.compare(a, o.a);
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