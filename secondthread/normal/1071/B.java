import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;
/*
4 2
abcd
bcde
bcad
bcde

2 0
qq
za

2 1
qq
zz
2 0
qz
qa

7 3
bbabbbb
bbbaaab
abbbbbb
abbbbbb
bbbbbbb
bbbbbbb
bbbbbbb
 */
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		char[][] board=new char[n][n];
		for (int y=0; y<n; y++) {
			char[] line=fs.next().toCharArray();
			for (int x=0; x<n; x++)
				board[x][y]=line[x];
		}
	
		boolean[][] visited=new boolean[n][n];
		ArrayDeque<Integer> xs=new ArrayDeque<>(), ys=new ArrayDeque<>();
		ArrayDeque<Integer> nextLevelXs=new ArrayDeque<>(), nextLevelYs=new ArrayDeque<>();
		int skipsLeft=board[0][0]=='a'?k:k-1;
		xs.add(0);
		ys.add(0);
		
		while (skipsLeft>=0) {
			while (!xs.isEmpty()) {
				int x=xs.remove();
				int y=ys.remove();
				if (visited[x][y])
					continue;
				visited[x][y]=true;
//				System.out.println("with skipsLeft: "+skipsLeft+" visiting "+x+" "+y);
				if (x+1<n) {
					if (board[x+1][y]=='a') {
						xs.add(x+1);
						ys.add(y);
					}
					else {
						nextLevelXs.add(x+1);
						nextLevelYs.add(y);
					}
				}
				if (y+1<n) {
					if (board[x][y+1]=='a') {
						xs.add(x);
						ys.add(y+1);
					}
					else {
						nextLevelXs.add(x);
						nextLevelYs.add(y+1);
					}
				}
			}
			skipsLeft--;
			
			ArrayDeque<Integer> tmp=xs;
			xs=nextLevelXs;
			nextLevelXs=tmp;
			tmp=ys;
			ys=nextLevelYs;
			nextLevelYs=tmp;
		}
		if (visited[n-1][n-1]) {
			StringBuilder sb=new StringBuilder();
			for (int i=0; i<=n-1+n-1; i++)
				sb.append('a');
			System.out.println(sb);
			return;
		}
		ArrayList<Vec> farthest=new ArrayList<>();
		while (!xs.isEmpty()) {
			int x=xs.remove();
			int y=ys.remove();
			Vec cur=new Vec(x, y, x+y, board[x][y]);
			if (!farthest.isEmpty()&&cur.compareTo(farthest.get(0))<0)
				farthest.clear();
			if (farthest.isEmpty()||farthest.get(0).compareTo(cur)==0)
				farthest.add(cur);
		}
		StringBuilder sb=new StringBuilder();
		for (int i=0; i<farthest.get(0).distance; i++) sb.append('a');
		sb.append(farthest.get(0).nextChar);
		
		while (!(farthest.get(0).distance==n-1+n-1)) {
			ArrayList<Vec> considering =new ArrayList<>();
			for (Vec v:farthest) {
				int x=v.x;
				int y=v.y;
				if (visited[x][y])
					continue;
				visited[x][y]=true;
				if (x+1<n) {
					considering.add(new Vec(x+1, y, v.distance+1, board[x+1][y]));
				}
				if (y+1<n) {
					considering.add(new Vec(x, y+1, v.distance+1, board[x][y+1]));
				}
			}
			farthest.clear();
			for (Vec cur:considering) {
				if (!farthest.isEmpty()&&cur.compareTo(farthest.get(0))<0)
					farthest.clear();
				if (farthest.isEmpty()||farthest.get(0).compareTo(cur)==0)
					farthest.add(cur);
			}
			sb.append(farthest.get(0).nextChar);
		}
		System.out.println(sb.toString());
	}
	
	static class Vec implements Comparable<Vec> {
		int x, y;
		int distance;
		char nextChar;
		
		public Vec(int x, int y, int distance, char nextChar) {
			this.x=x;
			this.y=y;
			this.distance=distance;
			this.nextChar=nextChar;
		}

		public int compareTo(Vec o) {
			if (distance!=o.distance)
				return -Integer.compare(distance, o.distance);
			return Character.compare(nextChar, o.nextChar);
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