import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
1
11
aba?abacaba
 */
public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		test: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[] word=fs.next().toCharArray();
			outer: for (int startPos=0; startPos+6<n; startPos++) {
				char[] created=new char[n];
				for (int i=0; i<7; i++) {
					if (word[startPos+i]!='?' && word[startPos+i]!="abacaba".charAt(i)) {
//						System.out.println("Breaking on position");
						continue outer;
					}
					created[startPos+i]="abacaba".charAt(i);
				}
				for (int i=0; i<n; i++)
					if (created[i]==0) {
						created[i]=word[i]=='?'?'z':word[i];
					}
				if (works(created)) {
					System.out.println("Yes");
					System.out.println(created);
					continue test;
				}
			}
			System.out.println("No");
		}
	}
	
	static boolean works(char[] a) {
		int times=0;
		outer: for (int i=0; i+6<a.length; i++) {
			boolean works=true;
			for (int j=0; j<7; j++) {
				if (a[i+j]!="abacaba".charAt(j)) works=false;
			}
			if (works) times++;
		}
		return times==1;
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