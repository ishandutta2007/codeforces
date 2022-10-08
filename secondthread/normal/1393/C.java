import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
/*
1
7
1 7 1 6 4 4 6
 */
public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			int[] f=new int[n];
			for (int i:a) f[i-1]++;
			int min=1, max=n;
			while (min!=max) {
				int mid=(min+max+1)/2;
				if (possible(f, mid, n)) {
					min=mid;
				}
				else {
					max=mid-1;
				}
			}
			System.out.println(min-1);
		}
		
	}
	
	static boolean possible(int[] f, int dist, int n) {
		ArrayList<Integer>[] lists=new ArrayList[n];
		for (int i=0; i<n; i++) lists[i]=new ArrayList<>();
		for (int i:f) if (i!=0) lists[0].add(-i);
		PriorityQueue<Integer> pq=new PriorityQueue<>();
//		System.out.println("\n dist: "+dist);
		for (int i=0; i<n; i++) {
			for (int toAdd:lists[i]) pq.add(toAdd);
			if (pq.isEmpty()) return false;
			int toAdd=pq.remove();
//			System.out.println("At "+i+" using "+(-toAdd));
			toAdd++;
			if (toAdd!=0) {
				if (i+dist>=n) return false;
				lists[i+dist].add(toAdd);
			}
		}
		return true;
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