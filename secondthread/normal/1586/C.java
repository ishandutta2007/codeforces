import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
//		int T=fs.nextInt();
		int T=1;
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int h=fs.nextInt(), w=fs.nextInt();
			char[][] board=new char[h][w];
			for (int y=0; y<h; y++) board[y]=fs.next().toCharArray();
			int[] illegalsOnX=new int[w];
			//TODO:
			for (int y=1; y<h; y++)
				for (int x=1; x<w; x++)
					if (board[y][x-1]=='X' && board[y-1][x]=='X') illegalsOnX[x]++;
			
			int[] cs=new int[w+1];
			for (int i=1; i<=w; i++) cs[i]=cs[i-1]+illegalsOnX[i-1];
			int nq=fs.nextInt();
			for (int qq=0; qq<nq; qq++) {
				int x1=fs.nextInt()-1, x2=fs.nextInt()-1;
				int count=cs[x2+1]-cs[x1+1];
				out.println(count==0?"YES":"NO");
			}
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