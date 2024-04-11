import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
1
4
1
1
2
3
 */
public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			int[] stack=new int[n];
			int size=0;
			for (int i:a) {
				if (i==1) {
					stack[size++]=i;
				}
				else {
					while (stack[size-1]!=i-1) {
						size--;
					}
					size--;
					stack[size++]=i;
				}
				for (int j=0; j<size; j++) {
					out.print(stack[j]);
					if (j!=size-1) out.print('.');
				}
				out.println();
			}
			
//			int[] mapTo=new int[n];
//			Arrays.fill(mapTo, -1);
//			ArrayDeque<Integer>[] occsOf=new ArrayDeque[1001];
//			for (int i=0; i<occsOf.length; i++) occsOf[i]=new ArrayDeque<>();
//			int lastOne=-1;
//			
//			for (int i=0; i<n; i++) {
//				if (a[i]==1) {
//					mapTo[i]=lastOne;
//					lastOne=i;
//				}
//			}
//			for (int value=2; value<occsOf.length; value++) {
//				for (int i:occsOf[value]) {
//					int mapsTo=occsOf[value-1].removeFirst();
//					mapTo[i]=mapsTo;
//				}
//			}
//			System.out.println(Arrays.toString(mapTo));
//			for (int i=0; i<n; i++) {
//				ArrayList<Integer> listBackwards=new ArrayList<>();
//				listBackwards.add(a[i]);
//				int at=i;
//				while (true) {
////					System.out.println("x");
//					if (mapTo[at]==-1) {
//						break;
//					}
//					if (a[mapTo[at]]!=a[at]-1) {
//						listBackwards.add(a[mapTo[at]]);
//					}
//					at=mapTo[at];
//				}
//				for (int j=listBackwards.size()-1; j>=0; j--) {
//					out.print(listBackwards.get(j));
//					if (j!=0) out.print('.');
//				}
//				out.println();
//			}
		}
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