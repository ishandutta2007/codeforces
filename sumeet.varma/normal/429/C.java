import java.io.*;
import java.util.*;

public class R245qCGuessTheTree {
	
	static int n;
	static int c[];
	static int cnt[];
	static int subtree[];
	static int leafs,inter;
	static boolean dp[][],done[][];
	
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
		
		c = new int[n];
		for(int i=0;i<n;i++)
			c[i] = in.nextInt();
		
		cnt = new int[n + 1];
		
		for(int x : c)
			cnt[x]++;
		
		int minLeafs = (n + 1) >> 1;
		if(cnt[1] < minLeafs || cnt[n] != 1){
			System.out.println("NO");
			return;
		}
		else{
			leafs = cnt[1];
			inter = n - cnt[1];
			subtree = new int[inter];
			inter = 0;
			for(int x : c)
				if(x != 1)
					subtree[inter++] = x;
			Arrays.sort(subtree);
			//System.out.println(Arrays.toString(subtree));
			dp = new boolean[leafs + 1][1<<inter];
			done = new boolean[leafs + 1][1<<inter];
			w.println(go(leafs,0) ? "YES" : "NO");
		}
		
		w.close();
	}
	
	public static boolean go(int leafsLeft,int mask){
		//System.out.println(leafsLeft + " " + Integer.toBinaryString(mask));
		if(!done[leafsLeft][mask]){
			int curr = -1;
			boolean ans = false;
			for(int i=0;i<inter;i++)
				if(get(i,mask))
					curr = i;
			curr++;
			if(curr == inter)
				ans = true;
			
			else{
				//System.out.println("here " + curr + " " + (1<<curr));
				for(int newMask=0;newMask<(1<<curr);newMask++){
					int tot = 0;
					boolean valid = true;
					int goMask = mask | (1<<curr);
					//System.out.println(Integer.toBinaryString(newMask) + " " + Integer.toBinaryString(goMask));
					int cnt = 0;
					for(int j=0;j<curr;j++){
						if(get(j,newMask)){
							if(get(j,mask)){
								tot += subtree[j];
								goMask ^= 1 << j;
								cnt++;
							}
							else{
								valid = false;
								break;
							}
						}
					}
					//System.out.println(Integer.toBinaryString(goMask) + " " + valid + " " + cnt);
					valid &= tot < subtree[curr];
					if(valid){
						int leafsNeeded = subtree[curr] - 1 - tot;
						cnt += leafsNeeded;
						if(leafsNeeded <= leafsLeft && cnt >= 2){
							ans |= go(leafsLeft - leafsNeeded,goMask);
							if(ans)
								break;
						}
					}
				}
			}
			
			done[leafsLeft][mask] = true;
			dp[leafsLeft][mask] = ans;
		}
		return dp[leafsLeft][mask];
	}
	
	public static boolean get(int bit,int mask){
		return (mask & (1<<bit)) != 0;
	}
	
	public static int set(int bit,int mask){
		return mask | (1<<bit);
	}
	
	public static void p(int x){
		for(int i=inter-1;i>=0;i--){
			if((x & (1<<i)) != 0)
				System.out.print('1');
			else
				System.out.print('0');
		}
		System.out.println();
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