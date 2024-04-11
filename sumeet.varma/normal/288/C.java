import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class R177qCPoloAndXor {

	static int currmax = -1;
	static ArrayList<Integer[]> list;
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		
		boolean taken[] = new boolean[n + 1];
		int ans[] = new int[n + 1];
		Arrays.fill(ans, -1);
		
		boolean found = true;
		int last = -1;
		long total = 0;
		
		while(found){
			
			int max = 1;
			while(max <= n)
				max *= 2;
			int NEG = max - 1;
			NEG = Math.max(NEG, 0);
			
			found = false;
			
			for(int i=0;i<=n;i++){
				if(ans[i] != -1)
					continue;
				int other = NEG ^ i;
				if(other > n){
					last = i;
					continue;
				}
				if(!taken[other]){
					total += i ^ other;
					ans[i] = other;
					taken[other] = true;
				}
				found = true;
			}
			
			n = last;
		}
		
		w.println(total);
		for(int i=0;i<ans.length;i++)
			w.print(ans[i] + " ");
		w.println();
		
		w.close();
	}
	
	public static void p(int x){
		System.out.print(x + ": ");
		for(int i=4;i>=0;i--)
			System.out.print((x & (1<<i)) == 0 ? '0' : '1');
		System.out.println();
	}
	
	public static void go(int pos,int n,Integer arr[],boolean vis[]){
		if(pos == n + 1){
			
			int ans = get(arr);
			if(ans > currmax){
				list.clear();
				currmax = ans;
			}
			
			if(ans == currmax)
				list.add(arr.clone());
		}
		
		else{
			for(int i=0;i<=n;i++){
				if(!vis[i]){
					vis[i] = true;
					arr[pos] = i;
					go(pos+1,n,arr,vis);
					vis[i] = false;
				}
			}
		}
		
	}
	
	
	public static int get(Integer p[]){
		int ans = 0;
		for(int i=0;i<p.length;i++)
			ans += i ^ p[i];
		return ans;
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
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