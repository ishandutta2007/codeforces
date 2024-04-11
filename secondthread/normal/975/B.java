import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int[] board=fs.readArray(14);
		long max=0;
		for (int i=0; i<14; i++)
			max=Math.max(max, countPoints(board.clone(), i));
		System.out.println(max);
	}
	
	static long countPoints(int[] board, int toShare) {
		int[] toDist=new int[14];
		int oStones=board[toShare];
		for (int i=0; i<14; i++)
			toDist[i]=(oStones-i+13)/14;
		board[toShare]=0;
		for (int d=0; d<14; d++) {
			board[(toShare+1+d)%14]+=toDist[d];
		}
//		System.out.println(oStones);
//		System.out.println(Arrays.toString(toDist));
		long total=0;
		for (int i:board)
			if (i%2==0)
				total+=i;
//		System.out.println(Arrays.toString(board));
		return total;
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
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