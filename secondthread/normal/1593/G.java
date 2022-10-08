import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class G {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			char[] line=fs.next().toCharArray();
			int n=line.length;
			int[] cs=new int[n+2];
			for (int i=0; i<n; i++) {
				if (line[i]=='['||line[i]==']') {
					cs[i+2]++;
				}
			}
			for (int i=2; i<=n+1; i++) cs[i]+=cs[i-2];
			
			int nQ=fs.nextInt();
			for (int qq=0; qq<nQ; qq++) {
				int s=fs.nextInt()-1, e=fs.nextInt()-1;
				int v1=cs[e+1]-cs[s];
				int v2=cs[e+2]-cs[s+1];
				out.println(Math.abs(v2-v1));
			}
		}
		out.close();
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