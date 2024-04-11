import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class D2 {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		for (int i=n-1; i>=0; i--) {
			if (a[i]==0) continue;
			else {
				if (a[i]>1) {
					System.out.println(-1);
					return;
				}
				else break;
			}
		}
		
		//3s and 2s need a match
		int[] matchWith=new int[n];
		ArrayDeque<Integer> nonOnes=new ArrayDeque<>();
		ArrayDeque<Integer> ones=new ArrayDeque<>();
		ArrayDeque<Integer> onesYs=new ArrayDeque<>();
		ArrayList<Integer> xs=new ArrayList<>(), ys=new ArrayList<>();
		int y=n;
		for (int i=n-1; i>=0; i--) {
//			System.out.println(i+" "+ones.size());
			if (a[i]==0) continue;
			if (a[i]==1) {
				ones.add(i);
				onesYs.add(y);
				ys.add(y--);
				xs.add(i);
			}
			else if (a[i]==2) {
				if (ones.isEmpty()) {
					System.out.println(-1);
					return;
				}
				matchWith[i]=ones.remove();
				int matchY=onesYs.remove();
//				System.out.println("  Removed index "+matchWith[i]);
				xs.add(i);
				ys.add(matchY);
//				xs.add(matchWith[i]);
//				ys.add(matchY);
				y--;
				
				nonOnes.add(i);
			}
			else {
				if (!nonOnes.isEmpty()) {
					matchWith[i]=nonOnes.remove();
				}
				else if (!ones.isEmpty()) {
					matchWith[i]=ones.remove();
					onesYs.remove();
				}
				else {
					System.out.println(-1);
					return;
				}
				xs.add(i);
				ys.add(y);
				xs.add(matchWith[i]);
				ys.add(y);
				
				nonOnes.add(i);
				y--;
			}
		}
		
		PrintWriter out=new PrintWriter(System.out);
		out.println(xs.size());
		for (int i=0; i<xs.size(); i++)
			out.println(ys.get(i)+" "+(xs.get(i)+1));
		out.close();
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