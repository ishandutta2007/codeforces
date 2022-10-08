import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int h=fs.nextInt(), w=fs.nextInt();
			boolean w1=false, w2=false;
			char[][] board=new char[h][];
			for (int i=0; i<h; i++) 
				board[i]=fs.next().toCharArray();
			for (int x=0; x<w; x++) {
				for (int y=0; y<h; y++) {
					if (board[y][x]!='.') {
						if (board[y][x]=='W' == ((x+y)%2==0)) {
							w1=true;
						}
						else {
							w2=true;
						}
					}
				}
			}
			if (w1&&w2) {
				System.out.println("NO");
			}
			else {
				System.out.println("YES");
				if (w1) {
					for (int y=0; y<h; y++) {
						for (int x=0; x<w; x++) {
							System.out.print((x+y)%2==0?"W":"R");
						}
						System.out.println();
					}
				}
				else {
					for (int y=0; y<h; y++) {
						for (int x=0; x<w; x++) {
							System.out.print((x+y)%2!=0?"W":"R");
						}
						System.out.println();
					}
				}
			}
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