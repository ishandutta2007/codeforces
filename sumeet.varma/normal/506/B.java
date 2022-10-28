import java.io.*;
import java.util.*;

public class R286qBMrKitayatuTech {

	static int n,m,ans,s,count;
	static ArrayList<Integer> forw[],revs[],list[];
	static int vis[];
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		InputReader in = new InputReader(System.in);
	    PrintWriter w = new PrintWriter(System.out);
	    
	    n = in.nextInt();
	    m = in.nextInt();
	    
		forw = new ArrayList[n];
		revs = new ArrayList[n];
		list = new ArrayList[n];
		for(int i=0;i<n;i++){
			forw[i] = new ArrayList<Integer>();
			revs[i] = new ArrayList<Integer>();
		}
		
		for(int i=0;i<m;i++){
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			forw[a].add(b);
			revs[b].add(a);
		}
	    
		ans = n;
		vis = new int[n];
		
		for(int i=0;i<n;i++){
			if(vis[i] == 0){
				list[count] = new ArrayList<Integer>();
				vis[i] = 1;
				dfs(i);
				count++;
			}
		}
		ans -= count;
		
		Arrays.fill(vis, 0);
		
		for(int i=0;i<count;i++){
			for(int j : list[i]){
				if(vis[j] == 0){
					if(dfs2(j)){
						ans++;
						break;
					}
				}
			}
		}
		
		w.println(ans);
	    w.close(); 
	}
	
	public static void dfs(int curr){
		list[count].add(curr);
		
		for(int i=0;i<forw[curr].size();i++){
			int nxt = forw[curr].get(i);
			if(vis[nxt] == 0){
				vis[nxt] = 1;
				dfs(nxt);
			}
		}
		
		for(int i=0;i<revs[curr].size();i++){
			int nxt = revs[curr].get(i);
			if(vis[nxt] == 0){
				vis[nxt] = 1;
				dfs(nxt);
			}
		}
	}
	
	public static boolean dfs2(int curr){
		
		vis[curr] = 1;
		
		for(int i=0;i<forw[curr].size();i++){
			int nxt = forw[curr].get(i);
			if(vis[nxt] == 1)
				return true;
			else if(vis[nxt] == 0 && dfs2(nxt))
				return true;
		}
		
		vis[curr] = 2;
		return false;
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