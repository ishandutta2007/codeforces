import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			sort(a);
			int ans=0;
			for (int start=0; start<n; start++) {
				int startVal=a[start];
				int count=1;
				while (start+1<n && a[start+1]==a[start]) {
					start++;
					count++;
				}
				if (start==n-1) {
					ans=Math.max(ans, count);
					break;
				}
				int curVal=ceil(a, startVal+1);
				count++;
				
				while (true) {
					int min=curVal+(curVal-startVal);
					int ceil=ceil(a, min);
					if (ceil==-1) break;
					curVal=ceil;
					count++;
				}
				ans=Math.max(ans, count);
			}
			out.println(n-ans);
		}
		out.close();
	}
	
	static int ceil(int[] a, int than) {
		if (a[a.length-1]<than) return -1;
		int min=0, max=a.length-1;
		while (min!=max) {
			int mid=(min+max)/2;
			if (a[mid]>=than) {
				max=mid;
			}
			else {
				min=mid+1;
			}
		}
		return a[min];
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