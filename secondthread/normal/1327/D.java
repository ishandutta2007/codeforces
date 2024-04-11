import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			for (int i=0; i<n; i++) a[i]--;
			int[] c=fs.readArray(n);
			boolean[] hit=new boolean[n];
			int best=n;
			for (int start=0; start<n; start++) {
				if (hit[start]) continue;
				int at=start;
				ArrayList<Integer> cycle=new ArrayList<>();
				while (!hit[at]) {
					hit[at]=true;
					cycle.add(c[at]);
					at=a[at];
				}
				best=Math.min(best, solve(cycle));
			}
			
			out.println(best);
		}
		out.close();
	}
	
	static int solve(ArrayList<Integer> cycleL) {
		int[] a=new int[cycleL.size()];
		for (int i=0; i<a.length; i++) a[i]=cycleL.get(i);
		int best=1000000000;
		for (int factor=1; factor<=a.length; factor++) {
			if (a.length%factor!=0) continue;
			outer:for (int start=0; start<factor; start++) {
				for (int i=start; i<a.length; i+=factor)
					if (a[i]!=a[start]) continue outer;
				best=Math.min(best, factor);
			}
		}
		return best;
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
		
		boolean hasNext() {
			String next=null;
			try {
				next = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (next==null) {
				return false;
			}
			st=new StringTokenizer(next);
			return true;
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

}