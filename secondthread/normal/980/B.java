import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B2 {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int width=fs.nextInt()-2;
		int toPlace=fs.nextInt();
		
		boolean[][] board=new boolean[width][2];
		if (toPlace>=width) {
			toPlace-=width;
			for (int i=0; i<width; i++) {
				board[i][0]=true;
			}
		}
		for (int i=0; i<toPlace/2; i++) {
			board[i][1]=true;
			board[width-i-1][1]=true;
		}
		if (toPlace%2==1) {
			board[width/2][1]=true;
		}
		/*else if (toPlace%2==0) {
			for (int i=0; i<toPlace/2; i++)
				board[i][1]=board[i][0]=true;
		}*/
		System.out.println("YES");
		for (int i=0; i<width+2; i++) {
			System.out.print('.');
		}
		System.out.println();
		System.out.print('.');
		for (int i=0; i<width; i++)
			System.out.print(board[i][0]?'#':'.');
		System.out.println('.');
		System.out.print('.');
		for (int i=0; i<width; i++)
			System.out.print(board[i][1]?'#':'.');
		System.out.println('.');
		for (int i=0; i<width+2; i++) {
			System.out.print('.');
		}
//		System.out.println();
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}