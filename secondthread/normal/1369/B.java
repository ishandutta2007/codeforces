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
			int n=fs.nextInt();
			char[] line=fs.next().toCharArray();
			int zPre=0;
			int suf=0;
			boolean hasZ=false, hasO=false;
			for (char c:line) if (c=='0') hasZ=true; else hasO=true;
			if (!hasZ || !hasO) {
				System.out.println(line);
				continue;
			}
			for (int i=0; i<n; i++) if (line[i]=='1') {
				zPre=i;
				break;
			}
			for (int i=n-1; i>=0; i--) if (line[i]=='0') {
				suf=i;
				break;
			}
			if (zPre+(n-suf+1)>n) {
				System.out.println(line);
				continue;
			}
			for (int i=0; i<zPre; i++) System.out.print(line[i]);
			for (int i=suf; i<n; i++) System.out.print(line[i]);
			System.out.println();
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