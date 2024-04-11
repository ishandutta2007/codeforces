import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		int[] bitsIn=new int[1<<7];
		for (int i=0; i<1<<7;i++) bitsIn[i]=Integer.bitCount(i);
		FastScanner fs=new FastScanner();
		int h=fs.nextInt(), w=fs.nextInt();
		if (Math.min(w, h)==1) {
			//1xn case
			System.out.println(0);
			return;
		}
		if (Math.min(w, h)>3) {
			System.out.println("-1");
			return;
		}
		//brute force
		char[][] board=new char[w][h];
		for (int y=0; y<h; y++) {
			char[] line=fs.next().toCharArray();
			for (int x=0; x<w; x++) board[x][y]=line[x];
		}
		if (w>3) {
			int temp=w;
			w=h;
			h=temp;
			char[][] newBoard=new char[w][h];
			for (int x=0; x<w; x++)
				for (int y=0; y<h; y++)
					newBoard[x][y]=board[y][x];
			board=newBoard;
		}
		
		boolean[][] possibleTrans=new boolean[1<<w][1<<w];
		for (int m1=0; m1<1<<w; m1++) {
			for (int m2=0; m2<1<<w; m2++) {
				boolean[][] mat=new boolean[w][2];
				for (int x=0; x<w; x++)
					mat[x][0]=(m1&(1<<x))!=0;
				for (int x=0; x<w; x++)
					mat[x][1]=(m2&(1<<x))!=0;
				possibleTrans[m1][m2]=works(mat);
			}
		}
		//make spacespaving if needed
		int[] cost=new int[1<<w];
		int[] masks=new int[h];
		for (int y=0; y<h; y++) {
			int mask=0;
			for (int x=0; x<w; x++) {
				if (board[x][y]=='1') mask+=1<<x;
			}
			masks[y]=mask;
		}
		cost[masks[0]]=0;
		for (int i=0; i<1<<w; i++) cost[i]=bitsIn[i^masks[0]];
		for (int y=1; y<h; y++) {
			int[] newCosts=new int[1<<w];
			Arrays.fill(newCosts, (int)1e9);
			for (int newMask=0; newMask<1<<w; newMask++) {
				for (int from=0; from<1<<w; from++) {
					if (!possibleTrans[from][newMask]) continue;
					newCosts[newMask]=Math.min(newCosts[newMask], 
							cost[from]+bitsIn[newMask^masks[y]]);
				}
			}
			cost=newCosts;
		}
		
		int best=cost[0];
		for (int i:cost) best=Math.min(best, i);
		System.out.println(best<1e9?best:-1);
	}
	
	public static boolean works(boolean[][] board) {
		//check 2x2s
		for (int x1=0; x1+1<board.length; x1++) {
			for (int y1=0; y1+1<board[x1].length; y1++) {
				int count=0;
				for (int x=0; x<2; x++)
					for (int y=0; y<2; y++)
						if (board[x+x1][y+y1]) count++;
				if (count%2==0) return false;
			}
		}
		return true;
	}
	
	public void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreElements())
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
	}

}