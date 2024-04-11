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
			int h=fs.nextInt(), w=fs.nextInt();
			Space[][] spaces=new Space[w][h];
			ArrayList<Space> all=new ArrayList<>();
			for (int y=0; y<h; y++) {
				for (int x=0; x<w; x++) {
					spaces[x][y]=new Space(x, y, fs.nextInt());
					all.add(spaces[x][y]);
				}
			}
			Collections.sort(all);
			
			for (int i=0; i<w; i++) {
				Space cur=all.get(i);
				if (cur.x==i) continue;
				swap(spaces, cur, spaces[i][cur.y]);
			}
			for (int y=0; y<h; y++) {
				for (int x=0; x<w; x++) {
					if (x!=0) System.out.print(" ");
					System.out.print(spaces[x][y].val);
				}
				System.out.println();
			}
		}
	}
	
	static void swap(Space[][] board, Space a, Space b) {
		int x1=a.x, x2=b.x, y1=a.y, y2=b.y;
		a.x=x2;
		b.x=x1;
		a.y=y2;
		b.y=y1;
		board[x1][y1]=b;
		board[x2][y2]=a;
	}
	
	static class Space implements Comparable<Space> {
		int x,y,val;
		public Space(int x, int y, int val) {
			this.x=x;
			this.y=y;
			this.val=val;
		}
		
		public int compareTo(Space o) {
			return Integer.compare(val, o.val);
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