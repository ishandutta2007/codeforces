import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class _507B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		long n=fs.nextLong(), k=fs.nextLong();
		long min=1, max=n;
		Random r=new Random();
		while (true) {
			if (max-min>100) {
				long mid=(max+min)/2;
				System.out.println(min+" "+mid);
				System.out.flush();
				String input=fs.next();
				if (input.equals("Yes")) {
					max=mid;
				}
				else {
					min=mid+1;
				}
			}
			else {
				long toPick=r.nextInt((int)(max-min+1))+min;
				System.out.println(toPick+" "+toPick);
				System.out.flush();
				String input=fs.next();
				if (input.equals("Yes")) {
					return;
				}
				else {
					//oops, got it wrong
				}
			}
			min-=k;
			max+=k;
			min=Math.max(min, 1);
			max=Math.min(n, max);
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		String next() {
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
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	// Disjoint set but can set a save point and restore to it
	// Do not save twice in a row without restoring first
	static class RestorableDisjointSet {
		int[] s, s2, vs;
		int curv;
		public RestorableDisjointSet(int n) {
			s=new int[n];
			s2=new int[n];
			vs=new int[n];
			Arrays.fill(s, -1);
			curv=-1;
		}
		void save() {
			curv=1-curv;
		}
		void restore() {
			curv*=-1;
		}
		int find(int i) {
			return get(i)<0 ? i : set(i, find(get(i)));
		}
		int get(int i) {
			return vs[i]==curv ? s2[i] : s[i];
		}
		int set(int i, int v) {
			if (curv<0)
				return s[i]=v;
			vs[i]=curv;
			return s2[i]=v;
		}
		void union(int a, int b) {
			if (get(a=find(a))==get(b=find(b)))
				set(a, get(a)-1);
			if (get(a)<=get(b))
				set(b, a);
			else
				set(a, b);
		}
	}

}