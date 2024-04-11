import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int k=fs.nextInt();
		if (k>n) {
			System.out.println("NO");
			return;
		}
		PriorityQueue<Integer> pq=new PriorityQueue<>((a, b)->{return Integer.compare(b, a);});
		for (int i=0; i<32; i++)
			if ((n&(1<<i))!=0)
				pq.add(1<<i);
		k-=pq.size();
		while (k>0) {
			k--;
			int next=pq.remove();
			pq.add(next/2);
			pq.add(next/2);
		}
		if (k<0) {
			System.out.println("NO");
			return;
		}
		System.out.println("YES");
		while (!pq.isEmpty()) {
			System.out.print(pq.remove()+" ");
		}
	}
	
	static class FastScanner {
		StringTokenizer st = new StringTokenizer("");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		public String next() {
			while (!st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public int[] readArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

	}
	
}