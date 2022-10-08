import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		char[] line1=fs.next().toCharArray();
		char[] line2=fs.next().toCharArray();
		TreeSet<Integer> pluses=new TreeSet<>(), minuses=new TreeSet<>();
		for (int i=0; i<n; i++) {
			if (line1[i]==line2[i]) continue;
			if (line1[i]=='0') pluses.add(i);
			else minuses.add(i);
		}
		
		if (pluses.size()!=minuses.size()) {
			System.out.println(-1);
			return;
		}
		int turns=0;
		while (!pluses.isEmpty()) {
			TreeSet<Integer> a=null, b=null;
			if (pluses.first()<minuses.first()) {
				a=pluses;
				b=minuses;
			}
			else {
				a=minuses;
				b=pluses;
			}
			int pos=-1;
			while (true) {
				Integer higher=a.higher(pos);
				if (higher==null) break;
				Integer bHigher=b.higher(higher);
				if (bHigher==null) break;
				a.remove(higher);
				b.remove(bHigher);
				pos=bHigher;
			}
			turns++;
		}
		System.out.println(turns);
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