import java.io.*;
import java.util.*;

public class ER12qEBeautifulSubarrays {

	static int root;
	static int child[][];
	static int cnt[];
	static final int max = 32 * (int)1e6;
	static int global;
	
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int k = in.nextInt();
		
		root = 0;
		global = 0;
		child = new int[2][max];
		child[0][0] = child[1][0] = -1;
		cnt = new int[max];
		
		insert(0);
		
		int p = 0;
		long ans = 0;
		
		for(int i = 1; i <= n; i++){
			p ^= in.nextInt();
			ans += query(k , p);
			insert(p);
		}
		
		w.println(ans);	
		w.close();
	}
	
	static int query(int k, int p){
		int curr = root;
		int ans = 0;
		for(int i = 30; i >= 0 && curr != -1; i--){
			if( get(k,  i) == 1){
				if(get(p, i) == 0){
					curr = child[1][curr];
				}
				else{
					curr = child[0][curr];
				}
			}
			else{
				if(get(p , i) == 0){
					ans += cnt(child[1][curr]);
					curr = child[0][curr];
				}
				else{
					ans += cnt(child[0][curr]);
					curr = child[1][curr];
				}
			}
		}
		ans += cnt(curr);
		return ans;
	}
	
	static int cnt(int x){
		return x == -1 ? 0 : cnt[x];
	}
	
	static void insert(int x){
		int curr = root;
		cnt[curr]++;
		for(int i = 30; i >= 0; i--){
			if( (x & (1 << i)) != 0 ){
				if(child[1][curr] == -1){
					child[1][curr] = ++global;
					child[0][global] = child[1][global] = -1;
				}
				curr = child[1][curr];
			}
			else{
				if(child[0][curr] == -1){
					child[0][curr] = ++global;
					child[0][global] = child[1][global] = -1;
				}
				curr = child[0][curr];
			}
			cnt[curr]++;
		}
	}
	
	static int get(int x, int bit){
		return (x & (1 << bit)) != 0 ? 1 : 0;
	}
	
	static int get2(int p[], int k){
		int ans = 0;
		for(int i = 0; i < p.length; i++)
			for(int j = i + 1; j < p.length; j++)
				if((p[i] ^ p[j]) >= k)
					ans++;
		return ans;
	}
	
	static class Node{
		int cnt;
		Node child[];
		Node(){
			cnt = 0;
			child = new Node[2];
		}
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar, snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
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

		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
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
}