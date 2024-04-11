import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class D {

	static int time;
	static PriorityQueue<State> pq=new PriorityQueue<>();
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			time=1;
			int n=fs.nextInt();
			pq.add(new State(0, n-1));
			int[] a=new int[n];
			while (!pq.isEmpty()) {
				State next=pq.remove();
				solve(a, next.l, next.r);
			}
			for (int i=0; i<n; i++) System.out.print(a[i]+" ");
			System.out.println();
		}
	}
	
	static void solve(int[] a, int l, int r) {
		if (l>r) return;
		int mid=(l+r)/2;
		a[mid]=time++;
		pq.add(new State(l, mid-1));
		pq.add(new State(mid+1, r));
	}
	
	static class State implements Comparable<State> {
		int l, r;
		int len;
		public State(int l, int r) {
			this.l=l;
			this.r=r;
			this.len=r-l+1;
		}
		
		public int compareTo(State o) {
			if (len!=o.len) {
				return -Integer.compare(len, o.len);
			}
			else {
				return Integer.compare(l, o.l);
			}
		}
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