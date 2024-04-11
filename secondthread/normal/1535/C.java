import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			char[] line=fs.next().toCharArray();
			for (int i=1; i<line.length; i+=2) {
				if (line[i]=='1')
					line[i]='0';
				else if (line[i]=='0')
					line[i]='1';
			}
			long count=0;
			int zCount=0, oCount=0, lPtr=0, rPtr=-1;
			while (rPtr+1<line.length) {
				rPtr++;
				if (line[rPtr]=='1') oCount++;
				else if (line[rPtr]=='0') zCount++;
				while (oCount>0 && zCount>0) {
					if (line[lPtr]=='1') oCount--;
					else if (line[lPtr]=='0') zCount--;
					lPtr++;
				}
				count+=rPtr-lPtr+1;
			}
			System.out.println(count);
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