import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int[] board=new int[24];
		for (int i=0; i<24; i++) {
			board[i]=fs.nextInt();
		}
//		System.out.println(Arrays.toString(rotateMiddle(board)));
		
		if (isSolved(rotateMiddle(board))) {
			System.out.println("YES");
			return;
		}
		if (isSolved(rotateMiddleRev(board))) {
			System.out.println("YES");
			return;
		}
		if (isSolved(rotateSide(board))) {
			System.out.println("YES");
			return;
		}
		if (isSolved(rotateSideRev(board))) {
			System.out.println("YES");
			return;
		}
		if (isSolved(rotateFront(board))) {
			System.out.println("YES");
			return;
		}
		if (isSolved(rotateFrontRev(board))) {
			System.out.println("YES");
			return;
		}
		System.out.println("NO");
	}
	
	private static boolean isSolved(int[] board) {
		if (board[0]!=board[1]||board[0]!=board[2]||board[0]!=board[3]) {
			return false;
		}
		if (board[4]!=board[5]||board[4]!=board[6]||board[4]!=board[7]) {
			return false;
		}
		if (board[8]!=board[9]||board[8]!=board[10]||board[8]!=board[11]) {
			return false;
		}
		if (board[12]!=board[13]||board[12]!=board[14]||board[12]!=board[15]) {
			return false;
		}
		if (board[16]!=board[17]||board[16]!=board[18]||board[16]!=board[19]) {
			return false;
		}
		return true;
	}
	
	private static int[] rotateMiddle(int[] o) {
		int[] r=o.clone();
		r[0]=o[23];
		r[2]=o[21];
		r[4]=o[0];
		r[6]=o[2];
		r[8]=o[4];
		r[10]=o[6];
		r[23]=o[8];
		r[21]=o[10];
		return r;
	}
	
	private static int[] rotateMiddleRev(int[] o) {
		int[] r=o.clone();
		o=o.clone();
		o[23]=r[0];
		o[21]=r[2];
		o[0]=r[4];
		o[2]=r[6];
		o[4]=r[8];
		o[6]=r[10];
		o[8]=r[23];
		o[10]=r[21];
		return o;
	}
	
	private static int[] rotateSide(int[] o) {
		int[] r=o.clone();
		r[12]=o[4];
		r[13]=o[5];
		r[4]=o[16];
		r[5]=o[17];
		r[16]=o[20];
		r[17]=o[21];
		r[20]=o[12];
		r[21]=o[13];
		return r;
	}
	
	private static int[] rotateSideRev(int[] o) {
		int[] r=o.clone();
		o=o.clone();
		o[4]=r[12];
		o[5]=r[13];
		o[16]=r[4];
		o[17]=r[5];
		o[20]=r[16];
		o[21]=r[17];
		o[12]=r[20];
		o[13]=r[21];
		return o;
	}
	
	private static int[] rotateFront(int[] o) {
		int[] r=o.clone();
		r[14]=o[0];
		r[12]=o[1];
		r[11]=o[14];
		r[10]=o[12];
		r[17]=o[11];
		r[19]=o[10];
		r[0]=o[17];
		r[1]=o[19];
		return r;
	}
	
	private static int[] rotateFrontRev(int[] o) {
		int[] r=o.clone();
		o=o.clone();
		o[0]=r[14];
		o[1]=r[12];
		o[14]=r[11];
		o[12]=r[10];
		o[11]=r[17];
		o[10]=r[19];
		o[17]=r[0];
		o[19]=r[1];
		return o;
	}

	private static class FastScanner {
		private BufferedReader br;
		private StringTokenizer st;
		
		public FastScanner() {
			st=new StringTokenizer("");
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next() {
			if (st.hasMoreTokens()) {
				return st.nextToken();
			}
			while (!st.hasMoreTokens()) {
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
	
}