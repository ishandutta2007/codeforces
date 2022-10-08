import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			char[] line=fs.next().toCharArray();
			int ans=Integer.MAX_VALUE;
			for (int i=0; i<line.length; i++) {
				for (int j=i+1; j<line.length; j++) {
					if (line[i]=='0' && line[j]=='0') ans=line.length-2-i;
					if (line[i]=='2' && line[j]=='5') ans=line.length-2-i;
					if (line[i]=='5' && line[j]=='0') ans=line.length-2-i;
					if (line[i]=='7' && line[j]=='5') ans=line.length-2-i;
				}
			}
			System.out.println(ans);
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