import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
//		int T=fs.nextInt();
		int T=1;
		outer: for (int tt=0; tt<T; tt++) {
			int h=fs.nextInt(), w=fs.nextInt();
			boolean[][] board=new boolean[w][h];
			for (int y=0; y<h; y++) {
				char[] line=fs.next().toCharArray();
				for (int x=0; x<w; x++) board[x][y]=line[x]=='#';
			}
			boolean[] usedX=new boolean[w], usedY=new boolean[h];
			int[] topX=new int[w], bottomX=new int[w];
			int[] leftY=new int[h], rightY=new int[h];
			Arrays.fill(leftY, 10000);
			Arrays.fill(topX, 100000);
			for (int x=0; x<w; x++) {
				for (int y=0; y<h; y++) {
					if (!board[x][y]) continue;
					usedX[x]=true;
					usedY[y]=true;
					topX[x]=Math.min(topX[x], y);
					bottomX[x]=Math.max(bottomX[x], y);
					leftY[y]=Math.min(leftY[y], x);
					rightY[y]=Math.max(rightY[y], x);
				}
			}
			boolean unusedRow=false, unusedCol=false;
			for (int x=0; x<w; x++) if (!usedX[x]) unusedCol=true;
			for (int y=0; y<h; y++) if (!usedY[y]) unusedRow=true;
			if (unusedRow!=unusedCol) {
				System.out.println("-1");
				continue;
			}
			for (int x=0; x<w; x++) {
				for (int y=0; y<h; y++) {
					if (board[x][y]) continue;
					if (topX[x]<y && bottomX[x]>y) {
						System.out.println("-1");
						continue outer;
					}
					if (leftY[y]<x && rightY[y]>x) {
						System.out.println("-1");
						continue outer;
					}
				}
			}
			DisjointSet dj=new DisjointSet(w*h);
			int comps=w*h;
			for (int x=0; x<w; x++) {
				for (int y=0; y<h; y++) {
					if (!board[x][y]) comps--;
					if (x>0 && board[x][y] && board[x-1][y] && dj.union(x+y*w, x-1+y*w))
						comps--;
					if (y>0 && board[x][y] && board[x][y-1] && dj.union(x+y*w, x+(y-1)*w))
						comps--;
				}
			}
			System.out.println(comps);
		}
	}
	
	static class DisjointSet {
		int[] s;
		
		public DisjointSet(int n) {
			Arrays.fill(s = new int[n], -1);
		}
		
		public int find(int i) {
			return s[i] < 0 ? i : (s[i] = find(s[i]));
		}
		
		public boolean union(int a, int b) {
			if ((a = find(a)) == (b = find(b))) return false;
			if(s[a] == s[b]) s[a]--;
			if(s[a] <= s[b]) s[b] = a; else s[a] = b;
			return true;
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
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
		long nextLong() {
			return Long.parseLong(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}
	
	public void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

}