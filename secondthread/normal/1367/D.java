import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			char[] line=fs.next().toCharArray();
			Arrays.sort(line);
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			boolean[] killed=new boolean[n];
			char[] ans=new char[n]; Arrays.fill(ans, '-');
			int nKilled=0;
			int lineIndex=line.length-1;
			while (nKilled<n) {
				ArrayList<Integer> zeros=new ArrayList<>();
				for (int i=0; i<n; i++) if (!killed[i] && a[i]==0) zeros.add(i);
				
				char fillWith='.';
				while (true) {
					char current=line[lineIndex];
					int currentCount=0;
					while (lineIndex>=0 && line[lineIndex]==current) {
						currentCount++;
						lineIndex--;
					}
					if (currentCount>=zeros.size()) {
						fillWith=current;
						break;
					}
				}
				for (int z:zeros) {
					killed[z]=true;
					//TODO: set ans[i]
					ans[z]=fillWith;
					for (int i=0; i<n; i++) {
						if (!killed[i]) a[i]-=Math.abs(z-i);
					}
					
				}
				nKilled+=zeros.size();
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