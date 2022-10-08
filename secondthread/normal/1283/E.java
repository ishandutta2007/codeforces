import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		sort(a);
		//calculate min possible
		int lastUsed=a[0]+1;
		int usedCount=1;
		for (int i:a) {
			if (Math.abs(lastUsed-i)>1) {
				lastUsed=i+1;
				usedCount++;
			}
		}
		int minAnswer=usedCount;
		lastUsed=-999;
		usedCount=0;
		for (int i:a) {
			if (lastUsed==i+1) continue;
			lastUsed=Math.max(lastUsed+1, i-1);
			usedCount++;
		}
		System.out.println(minAnswer+" "+usedCount);
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> list=new ArrayList<>();
		for (int i:a) list.add(i);
		Collections.sort(list);
		for (int i=0; i<a.length; i++) a[i]=list.get(i);
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreTokens())
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

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

	}

}