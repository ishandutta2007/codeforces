import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/*
a
ab
abc
abaa
abaac

abaacaaada
aaabaaaa


 b
0 ba
0 bac
1 abaa
1 abaac
aabaaa
 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			if (n==1) {
				out.println("b");
			}
			else {
				int start=n/2-1;
				for (int i=0; i<start; i++) out.print('a');
				out.print('b');
				for (int i=0; i<=start; i++) out.print('a');
				if (n%2!=0) out.print('c');
				out.println();
			}
		}
		out.close();
//		String s=fs.next();
//		check(s);
	}

	static boolean check(String s) {
		for (int start=0; start<s.length(); start++) {
			for (int end=start+1; end<=s.length(); end++) {
				String sub=s.substring(start, end);
				int count=0;
				for (int i=0; i+sub.length()<=s.length(); i++) {
					String other=s.substring(i, i+sub.length());
					if (sub.equals(other)) {
						count++;
					}
				}
				if (count%2==0) {
					System.out.println(count+" "+sub);
					return false;
				}
			}
		}
		return true;
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