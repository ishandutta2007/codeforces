import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*

 */
public class C {
	
	static int mod=998244353;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int h=fs.nextInt(), w=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		System.out.println(w-1+h-1+(w)*(h)-1);
		for (int i=0; i<w-1; i++) out.print('L');
		for (int i=0; i<h-1; i++) out.print('U');
		for (int y=0; y<h; y++) {
			if (y!=0) out.print('D');
			for (int x=0; x<w-1; x++) out.print((y%2==0)?'R':'L');
		}
		out.println();
		out.close();
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