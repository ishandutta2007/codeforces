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
			int n=fs.nextInt()*2;
			int[] a=fs.readArray(n);
			ArrayList<Integer> evens=new ArrayList<>(), odds=new ArrayList<>();
			for (int i=0; i<n; i++) 
				if (a[i]%2==0) evens.add(i+1);
				else odds.add(i+1);
			if (evens.size()%2==0) {
				if (evens.size()>0) {
					evens.remove(0);
				}
				else {
					odds.remove(0);
				}
			}
			for (int i=0; i+1<evens.size(); i+=2)
				System.out.println(evens.get(i)+" "+evens.get(i+1));
			for (int i=0; i+1<odds.size(); i+=2)
				System.out.println(odds.get(i)+" "+odds.get(i+1));
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