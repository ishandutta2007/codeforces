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
		outer: for (int tt=0; tt<T; tt++) {
			char[] a=fs.next().toCharArray();
			int[] counts=new int[26];
			for (char c:a) counts[c-'a']++;
			for (int i=0; i<26; i++) {
				if (counts[i]>1 || (i>0 &&counts[i]==1 && counts[i-1]==0)) {
					System.out.println("NO");
					continue outer;
				}
			}
			int aind=0;
			int n=a.length;
			for (int i=0; i<n; i++) if (a[i]=='a') aind=i;
			int l=aind, r=aind+1;
			int target='a';
			while (true) {
				boolean found=false;
				if (l>=0 && a[l]==target) {
					l--;
					target++;
					found=true;
				}
				if (r<n && a[r]==target) {
					r++;
					target++;
					found=true;
				}
				if (!found) break;
			}
			System.out.println(l>0 || r<n ? "NO" : "YES");
			
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