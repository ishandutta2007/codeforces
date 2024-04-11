import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class C {
	
	static final int mod=1_000_000_007;
	static int w, h, maxDown[][], maxRight[][];

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		h=fs.nextInt(); w=fs.nextInt();
		if (Math.max(w, h)==1) {
			System.out.println(1);
			return;
		}
		boolean[][] board=new boolean[w][h];
		for (int y=0; y<h; y++) {
			char[] line=fs.next().toCharArray();
			for (int x=0; x<w; x++)
				board[x][y]=line[x]!='.';
		}
		maxDown=new int[w][h]; maxRight=new int[w][h];
		for (int x=0; x<w; x++) {
			int seen=0;
			for (int y=h-1; y>=0; y--) {
				maxDown[x][y]=(h-y-1)-seen;
				if (board[x][y]) seen++;
			}
		}
		for (int y=0; y<h; y++) {
			int seen=0;
			for (int x=w-1; x>=0; x--) {
				maxRight[x][y]=(w-x-1)-seen;
				if (board[x][y]) seen++;
			}
		}
		
		//access a particular x, range sum accross ys |    oppisite
		BIT[] answerIfStartGoingRight=new BIT[w],          answerIfStartGoingDown=new BIT[h];
		for (int x=0; x<w; x++) answerIfStartGoingRight[x]=new BIT(h);
		for (int y=0; y<h; y++) answerIfStartGoingDown[y]=new BIT(w);
		
		for (int x=w-1; x>=0; x--)
			for (int y=h-1; y>=0; y--) {
				int rightEndpoint=x+maxRight[x][y], downEndpoint=y+maxDown[x][y];
				long rightAns=answerIfStartGoingDown[y].rangeSum(x+1, rightEndpoint);
				long downAns=answerIfStartGoingRight[x].rangeSum(y+1, downEndpoint);
				if (x==w-1&&y==h-1) {
					rightAns=downAns=1;
				}
				answerIfStartGoingDown[y].update(x, (int) (downAns%mod));
				answerIfStartGoingRight[x].update(y, (int) (rightAns%mod));
			}
		long ans=answerIfStartGoingRight[0].rangeSum(0, 0)+answerIfStartGoingDown[0].rangeSum(0, 0);
		System.out.println(ans%mod);
	}


	static class BIT {
		int n;
		long[] tree;
		
		public BIT(int n) {
			this.n = n;
			tree = new long[n + 10];
		}
		
		void update(int i, int val) {
			tree[i]=(tree[i+1]+val)%mod;
		}
		
		int rangeSum(int from, int to) {
			if (from>to) return 0;
			return (int) (((tree[from]-tree[to+1])%mod+mod)%mod);
//			return ((read(to)-read(from-1))%mod+mod)%mod;
		}

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
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
	
	
}