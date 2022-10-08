import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/*

 */
public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Val[] a=new Val[n];
		for (int i=0;i<n; i++) a[i]=new Val(fs.nextInt());
		int[] counts=new int[30];
		for (int i=0; i<counts.length; i++) {
			for (Val v:a) if (v.has(i)) counts[i]++;
			if (counts[i]>1)
				for (Val v:a)
					v.remove(i);
		}
		Arrays.sort(a);
		for (int i=n-1; i>=0; i--) {
			System.out.print(a[i].n+" ");
		}
		System.out.println();
	}
	
	static class Val implements Comparable<Val>{
		int n;
		int v;
		public Val(int n) {
			this.v=this.n=n;
		}
		
		boolean has(int i) {
			return (n&(1<<i))!=0;
		}
		
		void remove(int i) {
			if (has(i)) {
				v-=1<<i;
			}
		}
		
		public int compareTo(Val o) {
			return Integer.compare(v, o.v);
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

}