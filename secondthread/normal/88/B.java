import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int h=fs.nextInt(), w=fs.nextInt(), d=fs.nextInt();
		char[][] board=new char[w][h];
		for (int y=0; y<h; y++) {
			char[] line=fs.next().toCharArray();
			for (int x=0; x<w; x++) {
				board[x][y]=line[x];
			}
		}
		int n=fs.nextInt();
		char[] type=fs.next().toCharArray();
		boolean[] possible=new boolean[26];
		boolean shift=false;
		boolean[] has=new boolean[26];
		for (int i=0; i<w; i++) {
			for (int j=0; j<h; j++) {
				if (board[i][j]=='S') {
					shift=true;
				}
				else {
					has[board[i][j]-'a']=true;
					continue;
				}
				for (int ii=0; ii<w; ii++) {
					for (int jj=0; jj<h; jj++) {
						if ((ii-i)*(ii-i)+(jj-j)*(jj-j) <=d*d) {
							if (board[ii][jj]!='S') {
								possible[board[ii][jj]-'a']=true;
							}
						}
					}
				}
			}
		}
		
		int ans=0;
		for (char c:type) {
			if (Character.isUpperCase(c) && !shift)
				ans=(int)1e9;
			if (!has[Character.toLowerCase(c)-'a'])
				ans=(int)1e9;
			if (Character.isUpperCase(c) && !possible[c-'A']) {
				ans++;
			}
		}
		if (ans>=1e9) {
			System.out.println(-1);
		}
		else {
			System.out.println(ans);
		}
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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