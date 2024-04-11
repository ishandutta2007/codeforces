import java.io.*;
import java.util.*;

public class R245QAXorTree {

	@SuppressWarnings("unchecked")
	public static void main(String args[]) throws Exception{
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		
		ArrayList<Integer> g[] = new ArrayList[n+1];
		for(int i=1;i<=n;i++)
			g[i] = new ArrayList<Integer>();
		
		for(int i=1;i<n;i++){
			int u = in.nextInt();
			int v = in.nextInt();
			g[u].add(v);
			g[v].add(u);
		}
		
		int init[] = new int[n+1];
		for(int i=1;i<=n;i++)
			init[i] = in.nextInt();
		
		int goal[] = new int[n+1];
		for(int i=1;i<=n;i++)
			goal[i] = in.nextInt();
		
		int swaps[][] = new int[n+1][2];
		int level[] = new int[n+1];
		boolean vis[] = new boolean[n+1];
		ArrayList<Integer> nodes = new ArrayList<Integer>();
		
		if(init[1] != goal[1]){
			swaps[1][0] = 1;
			level[1] = 0;
			nodes.add(1);
		}
		
		Queue<Integer> q = new LinkedList<Integer>();
		vis[1] = true;
		q.add(1);
		
		while(!q.isEmpty()){
			int curr = q.remove();
			int s = g[curr].size();
			for(int i=0;i<s;i++){
				int nxt = g[curr].get(i);
				if(!vis[nxt]){
					level[nxt] = level[curr] + 1;
					swaps[nxt][0] = swaps[curr][0];
					swaps[nxt][1] = swaps[curr][1];
					if(swaps[nxt][level[nxt] % 2] % 2 == 1)
						init[nxt] = 1 - init[nxt];
					if(init[nxt] != goal[nxt]){
						swaps[nxt][level[nxt] % 2]++;
						nodes.add(nxt);
					}
					vis[nxt] = true;
					q.add(nxt);
				}
			}
		}
		
		int s = nodes.size();
		w.println(s);
		for(int i=0;i<s;i++)
			w.println(nodes.get(i));
		w.close();
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;
	public InputReader(InputStream stream) {
		this.stream = stream;
	}
	
	public int snext() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int nextInt() {
		int c = snext();
		while (isSpaceChar(c))
			c = snext();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = snext();
		}

		int res = 0;

		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = snext();
		} while (!isSpaceChar(c));

		return res * sgn;
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}