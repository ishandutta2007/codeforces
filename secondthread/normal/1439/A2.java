import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class A {

	static ArrayList<String> moves=new ArrayList<>();
	static boolean[][] board;
	static int w, h;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			moves.clear();
			h=fs.nextInt(); w=fs.nextInt();
			board=new boolean[w][h];
			for (int y=0; y<h; y++) {
				char[] line=fs.next().toCharArray();
				for (int x=0; x<w; x++)
					board[x][y]=line[x]=='1';
			}
			for (int y=0; y+2<h; y++) {
				for (int x=0; x<w-1; x++) {
					if (board[x][y]) {
						topLeft(x, y);
					}
				}
				if (board[w-1][y]) {
					bottomRight(w-2, y);
				}
			}
			for (int x=0; x+2<w; x++) {
				if (board[x][h-2]) {
					topLeft(x, h-2);
				}
				if (board[x][h-1]) {
					bottomRight(x, h-2);
				}
			}
			//TODO: solve last 4x4
			boolean tl=board[w-2][h-2], tr=board[w-1][h-2], bl=board[w-2][h-1], br=board[w-1][h-1];
			if (!tl&&!tr&&!bl&&!br) {
				//nothing
			}
			//just one
			else if (!tl&&!tr&&!bl&&br) {
				tr();
				br();
				bl();
			}
			else if (!tl&&!tr&&bl&&!br) {
				tl();
				bl();
				br();
			}
			else if (!tl&&tr&&!bl&&!br) {
				tl();
				tr();
				br();
			}
			else if (tl&&!tr&&!bl&&!br) {
				tl();
				tr();
				bl();
			}
			//two oppisite, pick them
			else if (tl&&!tr&&!bl&&br) {
				tl();
				br();
			}
			else if (!tl&&tr&&bl&&!br) {
				tr();
				bl();
			}
			//two adjacent, pick others
			else if (tl&&tr&&!bl&&!br) {
				bl();
				br();
			}
			else if (!tl&&tr&&!bl&&br) {
				tl();
				bl();
			}
			else if (!tl&&!tr&&bl&&br) {
				tl();
				tr();
			}
			else if (tl&&!tr&&bl&&!br) {
				tr();
				br();
			}
			//three
			else if (!tl&&tr&&bl&&br) {
				br();
			}
			else if (tl&&!tr&&bl&&br) {
				bl();
			}
			else if (tl&&tr&&!bl&&br) {
				tr();
			}
			else if (tl&&tr&&bl&&!br) {
				tl();
			}
			// four
			else if (tl&&tr&&bl&&br) {
				tl();
				tr();
				bl();
				br();
			}
			else throw null;
			for (boolean[] a:board)
				for (boolean b:a) if (b) throw null;
			System.out.println(moves.size());
			for (String s:moves) {
				System.out.println(s);
			}
		}
	}
	
	static void tl() {
		topLeft(w-2, h-2);
	}
	static void tr() {
		topRight(w-2, h-2);
	}
	static void bl() {
		bottomLeft(w-2, h-2);
	}
	static void br() {
		bottomRight(w-2, h-2);
	}
	
	static void topLeft(int x, int y) {
		add(x, y, x+1, y, x, y+1);
	}
	static void topRight(int x, int y) {
		add(x, y, x+1, y, x+1, y+1);
	}
	static void bottomLeft(int x, int y) {
		add(x, y, x, y+1, x+1, y+1);
	}
	static void bottomRight(int x, int y) {
		add(x+1, y, x, y+1, x+1, y+1);
	}
	
	static void add(int x1, int y1, int x2, int y2, int x3, int y3) {
		board[x1][y1]^=true;
		board[x2][y2]^=true;
		board[x3][y3]^=true;
		x1++;
		y1++;
		x2++;
		y2++;
		x3++;
		y3++;
		moves.add(y1+" "+x1+" "+y2+" "+x2+" "+y3+" "+x3);
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